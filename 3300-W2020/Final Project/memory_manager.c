#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
 
#define TLB_SIZE 16
#define PAGES 256
#define PAGE_MASK 255
#define PAGE_SIZE 256
#define OFFSET_BITS 8
#define OFFSET_MASK 255

#define MEMORY_SIZE PAGES * PAGE_SIZE
 
// Max number of characters per line from the input file to read
#define BUFFER_SIZE 10
 
struct tlb_entry_address {
    unsigned char logical_address;
    unsigned char physical_address;
};
 
// TLB is kept track of as a circular array, with the oldest element being overwritten once the TLB is full.
struct tlb_entry_address tlb[TLB_SIZE];
// number of inserts into TLB that have been completed. Use as tlbindex % TLB_SIZE for the index of the next TLB line to use.
int tlbindex = 0;

// this is the physical_address page number for logical_address page. e. Value is -1 if that logical_address page isn't yet in the table.
int pagetable[PAGES];
 
signed char main_memory[MEMORY_SIZE];

const char *output_file = "output.txt";
 
// Pointer to memory mapped backing file
signed char *backing;
 
// function prototype to search the page tables for TLB, add TLB to page, and find the max tlb

int search_tlb(unsigned char logical_page);

void add_to_tlb(unsigned char logical_address, unsigned char physical_address);

int max_tlb(int x, int y);


int main(int argc, const char *argv[])
{
    FILE *output_fp=fopen(output_file, "w"); // writes the result to the file
    
    if (argc != 3) {
        fprintf(stderr, "Usage ./a.out BACKINGSTORE.bin addressess.txt\n");
        exit(1);
    }
     
    const char *backing_filename = argv[1];
    
    //open and return a file descripter for the bin file
    int backing_fd = open(backing_filename, O_RDONLY);
    backing = mmap(0, MEMORY_SIZE, PROT_READ, MAP_PRIVATE, backing_fd, 0);
     
    const char *input_filename = argv[2];
    FILE *input_fp = fopen(input_filename, "r");
     
    // Fill page table entries with -1 (null) for the initially empty table.
    int i;
    for (i = 0; i < PAGES; i++)
        { pagetable[i] = -1; }
    
   // Character buffer for reading lines of input file.
   char buffer[BUFFER_SIZE];
   
   int total_addresses = 0, tlb_hits = 0, page_faults = 0;
    
   // Number of the next unallocated physical_address page in main memory
   unsigned char free_page = 0;
   while (fgets(buffer, BUFFER_SIZE, input_fp) != NULL)
       {total_addresses++;
        int logical_address = atoi(buffer);
        int offset = logical_address & OFFSET_MASK;
        int logical_page = (logical_address >> OFFSET_BITS) & PAGE_MASK; // to get the 16-bit size 
        int physical_page = search_tlb(logical_page);
        // TLB hit
        if (physical_page != -1)
        {
            tlb_hits++;
            // TLB miss
        } else
        {
            physical_page = pagetable[logical_page];
             
            // Page fault, calculating
            if (physical_page == -1)
            {
                page_faults++;
                physical_page = free_page;
                free_page++;
                // read in a 256-byte page from the file BACKING_STORE and store it in an available page frame in physical memory
                memcpy(main_memory + physical_page * PAGE_SIZE, backing + logical_page * PAGE_SIZE, PAGE_SIZE);
                pagetable[logical_page] = physical_page;
            }
            add_to_tlb(logical_page, physical_page);
        }
         
        //The signed byte value stored at the translated physical address
        int physical_address = (physical_page << OFFSET_BITS) | offset; // get the 16 bit size of the physical address
        signed char value = main_memory[physical_page * PAGE_SIZE + offset];
         
        // Writes the logical and physical address and the value to the output file
        fprintf(output_fp,"Virtual Address: %d  physical address:  %d  Value:  %d\n", logical_address, physical_address, value);
        // Writes the logical and physical address and the value to the screen
       printf("Virtual address: %d physical_address address: %d Value: %d\n", logical_address, physical_address, value);
    }
     
    printf("Number of Translated Addresses = %d\n", total_addresses);
    fprintf(output_fp, "Number of Translated Addresses = %d\n", total_addresses);
    printf("Page Faults = %d\n", page_faults);
    fprintf(output_fp, "Page Faults = %d\n", page_faults);
    printf("Page Fault Rate = %.3f\n", page_faults / (1. * total_addresses));
    fprintf(output_fp, "Page Fault Rate = %.3f\n", page_faults / (1. * total_addresses));
    printf("TLB Hits = %d\n", tlb_hits);
    fprintf(output_fp, "TLB Hits = %d\n", tlb_hits);
    printf("TLB Hit Rate = %.3f\n", tlb_hits / (1. * total_addresses));
    fprintf(output_fp, "TLB Hit Rate = %.3f\n", (tlb_hits / (1. * total_addresses)));
    return 0;
}


int max_tlb(int x, int y)
{
    if (x > y)
    { return x;
    }
    else
    {
        return y;
    }
}

// Returns the physical_address address from TLB or -1 if the address is not present in the table
int search_tlb(unsigned char logical_page)
{
    int i;
    for (i = max_tlb((tlbindex - TLB_SIZE), 0); i < tlbindex; i++)
        { struct tlb_entry_address *entry_address = &tlb[i % TLB_SIZE];
            if (entry_address->logical_address == logical_page)
            {
                return entry_address->physical_address;
            }
        }
     
    return -1;
}

// Page Replacement: Adds the specified mapping to the TLB, replacing the oldest mapping using a FIFO replacement technique
void add_to_tlb(unsigned char logical_address, unsigned char physical_address)
{
    struct tlb_entry_address *entry_address = &tlb[tlbindex % TLB_SIZE];
    tlbindex++;
    entry_address->logical_address = logical_address;
    entry_address->physical_address = physical_address;
}
