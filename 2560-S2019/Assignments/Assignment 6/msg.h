#ifndef MSG_H_
#define MSG_H_

#define TYPE_ENCRYPTED 1L
#define TYPE_DECRYPTED 2L

typedef struct {
  long mtype;
  char line[80];
} msgbuf;

#endif // MSG_H_