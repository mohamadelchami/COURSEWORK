#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

enum { BUFFER_SIZE = 16 };

void printError(const char * msg);

int main (int argc, char * argv[]){
  int fd;
  int read_size;

  if(argc < 2)
 {
   printError("missing filename argument");
   return 1;
 }

 fd = open(argv[1], O_RDONLY);
  if(fd < 0){
    printError(strerror(errno));
    return 10;
  }

  char buf[BUFFER_SIZE];
  if(read(fd, buf, sizeof(buf) - 1) == -1){
      printError(strerror(errno));
      return 13;
  }


  int outfd = open(argv[2], O_CREAT);

  if(write(outfd, buf, sizeof(buf)) == -1)
  {
    printError(strerror(errno));
    return 11;
  }

  // close the file
  close(fd);
  close(outfd);

  return 0;
}

void printError(const char * msg)
{
  write(2, "Error: ", 7);
  write(2, msg, strlen(msg));
  write(2, "\n", 1);
}
