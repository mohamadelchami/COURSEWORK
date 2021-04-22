#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include "mystdio.h"

//assignFlags: Assign the variable flag modes depending on the mode specified
//Inputs: mode(the opening mode of the file)
//Output: flag variable
int assignFlags(const char * mode){
  int flag = 0;

  if(!strcmp(mode, "r")){
    flag |= O_RDONLY;
  }

  else{
    if(mode[0] == 'w'){
      flag |= O_CREAT | O_TRUNC;
    }

    if(mode[0] == 'a'){
      flag |= O_CREAT | O_APPEND;
    }

    flag |= mode[strlen(mode) - 1] == '+' ? O_RDWR : O_WRONLY;
  }

  return flag;
}

//myfopen: opens a files with specified modes
//Input: *path (pointer to the file via path), *mode(pointer to the specified mo
de)
//Output: Struct fp with holding file discriptor
MYFILE * myfopen(const char * path, const char * mode){

  MYFILE * fp = (MYFILE *)malloc(sizeof(MYFILE));

  fp->fileDis = open(path, assignFlags(mode), S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  if(fp->fileDis == -1){
    return NULL;
  }

  return fp;
}

//myfdopen: open files with specified write/read modes
//Input: FileDis (already opened file specifier), mode (The new mode)
//Output: fp of type strucy MYFILE
MYFILE * myfdopen(int fileDis, const char * mode){

  MYFILE * fp = (MYFILE *)malloc(sizeof(MYFILE));

  int flag = fcntl(fileDis, F_GETFL);

  switch(mode[0]){
    case 'r':
      if(!((flag & O_RDONLY) || (flag & O_RDWR))){
        return NULL;
      }
    case 'w':
    case 'a':
      if(!((flag & O_WRONLY) || (flag & O_RDWR))){
        return NULL;
      }
  }

  fp->fileDis = fileDis;

  return fp;
}

//myfclose: Closes the file fp
//Input: File pointer to fp of strcut MYGILE
//Output: 0 if proper execution, error if not closes
int myfclose(MYFILE * fp){
  if(!fp){
    return MYEOF;
  }

  if(close(fp->fileDis) == -1){
    fp->error = 1;
    return MYEOF;
  }

  free(fp);
  fp = NULL;

  return 0;
}

//myfileno:returns the file discriptor of fp
//Input: pointer of fp to file discriptor
//Output: the file discriptor as type int
int myfileno(MYFILE * fp){
  return fp->fileDis;
}

//myfgetc: Gets ones character at a time from the file
//Input: pointer to fp to file discriptor
//Output: C(the character read)
int myfgetc(MYFILE * fp){

  char c;

  int i = read(fp->fileDis, &c, 1);

  if(i == -1){
    fp->error = 1;
    return MYEOF;
  }

  else if(i == 0){
    fp->endOfFile = 1;
    return MYEOF;
  }

  return (int)c;
}

//myfgets: gets one stromg at a time from he file
//Input: buffer(Char array that holds the string), n(size of the buffer), *fp(po
//inter to the file discriptor)
//Output: buffer(the string read)
char * myfgets(char * buffer, int n, MYFILE * fp){

  int i;

  for(i = 0; i < n - 1; ++i){
    char c;

    int r = read(fp->fileDis, &c, 1);

    if(r == -1){
      fp->error = 1;
      return NULL;
    }

    else if(r == 0){
      fp->endOfFile = 1;
      buffer[i] = '\0';
      break;
    }

    buffer[i] = c;

    if(c == '\n'){
      buffer[i + 1] = '\0';
      break;
    }
  }

  return buffer;
}

//myfputc: Prints a character to the file
//Input: c(the value of the character in ascii), *fp(point to file discriptor)
//Output: returns the character printer
int myfputc(int c, MYFILE * fp){

  char character = (char)c;

  if(write(fp->fileDis, &character, 1) != 1){
    fp->error = 1;
    return MYEOF;
  }

  return c;
}

//myfputs: Prints a string to the file
//Input: *str(pointer string to be printed), *fp(pointer to the file discriptor)
//Output: 0(if the string is printed), MYEOF if not printed
int myfputs(const char * str, MYFILE * fp){

  if(write(fp->fileDis, str, strlen(str)) != strlen(str)){
    fp->error = 1;
    return MYEOF;
  }

  return 0;
}

//myferror: returns fp errors
//Input: *fp(pointer to the file discriptor)
//Output: The error of fp
int myferror(MYFILE * fp){
  return fp->error;
}

//myfeof: returns the end of file of fp
//Input: *fp(pointer to the file discriptor)
//Output: the end of file(fp)
int myfeof(MYFILE * fp){
  return fp->endOfFile;
}

//myclearerror: Clears the errors and eof of the file fp
//Input: *fp (pointer to the fiel discriptor)
//Output: No return
void myclearerr(MYFILE * fp){
  fp->error = 0;
  fp->endOfFile = 0;
}

//myftell: seeks the current poition of the file
//Input: *fp(pointer to the file discriptor)
//Output: The crrent position in the file
long myftell(MYFILE * fp){

  return (long)lseek(fp->fileDis, 0, SEEK_CUR);
}

//myfseek: Seeks into a file
//Input: *fp(pointer to the file discriptor), offset(the distance wished to
//travel), whence(from where you wish to seek)
//Output: 0(if properly executed), error=1 and -1 if not properly executed
int myfseek(MYFILE * fp, long offset, int whence){

  if(lseek(fp->fileDis, (off_t)offset, whence) == -1){
    fp->error = 1;
    return -1;
  }

  return 0;
}

//myrewind: Goes back to the beginning of the file
//Input: *fp(pointer to the file discriptor)
//Output: no return
void myrewind(MYFILE * fp){
  lseek(fp->fileDis, 0, SEEK_SET);
}
