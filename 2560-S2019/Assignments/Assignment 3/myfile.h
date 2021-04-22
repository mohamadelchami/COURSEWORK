#ifndef MYSTDIO_H_
#define MYSTDIO_H_
typedef struct {
  int fileDis;
  int error : 1;
  int endOfFile : 1;
} MYFILE;

#endif
