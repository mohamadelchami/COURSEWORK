#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <stdio.h>

#include "mystdio.h"
#include "myfile.h"  // just checking for include guards!

#define TEST(condition) \
  if(condition) { printf("\x1b[32mPASS\x1b[0m \x1b[33m[+1]\x1b[0m\n"); } \
  else { printf("\x1b[31mFAIL\x1b[0m\n"); }

enum { BUFSIZE = 64 };

int main(int argc, char * argv[])
{
  int r, w, c, p;
  char buf[BUFSIZE];

  // clear umask
  umask(0);

  // open the test file
  MYFILE * testfile;
  printf("Opening 'testfile' for 'w+' using myfopen()... ");
  testfile = myfopen("testfile", "w+");
  TEST(testfile && (fcntl(myfileno(testfile), F_GETFL) & O_RDWR))

  if(testfile)
  {
    // write characters to the test file
    printf("Writing character-at-a-time to 'testfile' using myfputc()... ");
    myfputc('a', testfile);
    myfputc('b', testfile);
    lseek(myfileno(testfile), 0, SEEK_SET);
    r = read(myfileno(testfile), buf, 2);
    TEST(r == 2 && buf[0] == 'a' && buf[1] == 'b')

    // write a line to the test file
    printf("Writing line-at-a-time to 'testfile' using myfputs()... ");
    myfputs("racadabra", testfile);
    lseek(myfileno(testfile), 0, SEEK_SET);
    r = read(myfileno(testfile), buf, 11);
    buf[11] = '\0';
    TEST(r == 11 && !strcmp(buf, "abracadabra"))

    // add additional testing data to the file
    if(write(myfileno(testfile), "\nxyzzy", 6) != 6)
    {
      fprintf(stderr, "Error writing to test file.\n");
    }

    // close the test file
    printf("Closing 'testfile' using myfclose()... ");
    TEST(!myfclose(testfile))
  }

  // reopen the test file read-only
  printf("Opening 'testfile' for 'r' using myfopen()... ");
  testfile = myfopen("testfile", "r");
  TEST(testfile)

  if(testfile)
  {
    // read characters from the test file
    printf("Reading character-at-a-time from 'testfile' using myfgetc()... ");
    buf[0] = (char)myfgetc(testfile);
    buf[1] = (char)myfgetc(testfile);
    TEST(buf[0] == 'a' && buf[1] == 'b')

    // get the current position in the test file
    printf("Getting the current position in 'testfile' using myftell()... ");
    TEST(myftell(testfile) == 2)

    // seek in the test file
    printf("Seeking in 'testfile' using myfseek()... ");
    p = myfseek(testfile, 3, SEEK_CUR);
    TEST(lseek(myfileno(testfile), 0, SEEK_CUR) == 5 && p == 0)

    // rewind the test file
    printf("Rewinding 'testfile' using myrewind()... ");
    myrewind(testfile);
    TEST(lseek(myfileno(testfile), 0, SEEK_CUR) == 0)

    // read a line from the test file
    printf("Reading line-at-a-time from 'testfile' using myfgets()... ");
    myfgets(buf, BUFSIZE, testfile);
    TEST(!strcmp(buf, "abracadabra\n"))

    // read another line from the test file
    printf("Reading line-at-a-time from 'testfile' using myfgets()... ");
    myfgets(buf, BUFSIZE, testfile);
    TEST(!strcmp(buf, "xyzzy"))

    // verify that EOF flag is set
    printf("Verifying EOF flag from second read using myfeof()... ");
    TEST(myfeof(testfile))

    // clear flags
    printf("Verifying function of myclearerr()... ");
    myclearerr(testfile);
    TEST(!myferror(testfile) && !myfeof(testfile))

    // attempt to write to read-only file
    printf("Trying to write to read-only file (should fail)... ");
    TEST(myfputc('c', testfile) == MYEOF)

    // verify that error flag is set
    printf("Verifying error flag from attempted write using myferror()... ");
    TEST(myferror(testfile))

    // close the test file
    myfclose(testfile);
  }

  // reopen the test file for append
  printf("Opening 'testfile' for 'a+' using myfopen()... ");
  testfile = myfopen("testfile", "a+");
  TEST(testfile)

  if(testfile)
  {
    // append a character
    printf("Appending a character to 'testfile' using myfputc()... ");
    TEST((char)myfputc('c', testfile) == 'c')

    // close the test file
    myfclose(testfile);
  }

  // stat the test file
  struct stat st;
  stat("testfile", &st);

  // verify final file size
  printf("Verifying that final size of 'testfile' is 18 bytes... ");
  TEST(st.st_size == 18)

  // verify final file mode
  printf("Verifying the file mode of 'testfile' is 666... ");
  int mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH;
  TEST((st.st_mode & mode) == mode)

  // remove the test file
  unlink("testfile");

  // try to open a file with known permissions in various modes
  MYFILE * binsh;
  int b[4];
  printf("Trying to open /bin/sh in various modes...\n");
  printf("     r : ");
  binsh = myfopen("/bin/sh", "r");
  b[0] = (!binsh);
  printf("%s\n", b[0] ? "no" : "yes");
  myfclose(binsh);
  printf("     w : ");
  binsh = myfopen("/bin/sh", "w");
  b[1] = (!binsh);
  printf("%s\n", b[1] ? "no" : "yes");
  myfclose(binsh);
  printf("     a : ");
  binsh = myfopen("/bin/sh", "a");
  b[2] = (!binsh);
  printf("%s\n", b[2] ? "no" : "yes");
  myfclose(binsh);
  printf("    r+ : ");
  binsh = myfopen("/bin/sh", "r+");
  b[3] = (!binsh);
  printf("%s\n", b[3] ? "no" : "yes");
  myfclose(binsh);
  printf("Opening in various modes: ");
  TEST(!b[0] && b[1] && b[2] && b[3])

  // open streams for stdin and stdout
  MYFILE * mystdin, * mystdout;

  printf("Opening standard input using myfdopen()... ");
  mystdin = myfdopen(0, "r");
  TEST(mystdin)

  printf("Opening standard output using myfdopen()... ");
  mystdout = myfdopen(1, "a+");
  TEST(mystdout)

  // test reading character-at-a-time from stdin
  if(mystdin)
  {
    printf("Reading from standard input using mygetc()...\n");
    printf("    Please enter a character: ");
    fflush(stdout);
    c = myfgetc(mystdin);
    getchar();
    if(c == MYEOF)
    {
      printf("Failed reading from standard input.\n");
      TEST(0)
    }
    else
    {
      printf("    Did you enter the character '%c' [y/n]? ", (char)c);
      int yn = getchar();
      printf("Reading from standard input: ");
      TEST(yn == 'y')
    }
  }

  // test writing line-at-a-time to stdout
  if(mystdout)
  {
    printf("Writing to standard output using myfputs()...\n");
    w = myfputs("    Successfully wrote to standard output!\n", mystdout);
    printf("Writing to standard output: ");
    TEST(w != MYEOF)
  }

  return 0;
}
