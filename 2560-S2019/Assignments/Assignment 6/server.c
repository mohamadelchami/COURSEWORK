#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include "msg.h"

void rot13(char * str);
static void cleanup(int signo);

int msqid;

int main(int argc, char * argv[])
{
  // register signal handling for termination cleanup
  struct sigaction act;
  act.sa_handler = cleanup;
  sigemptyset(&act.sa_mask);
  act.sa_flags = SA_RESTART;
  sigaction(SIGTERM, &act, NULL);
  sigaction(SIGINT, &act, NULL);

  // create the message queue
  msqid = msgget(ftok("msg.h", 1), IPC_CREAT | 0666);
  if(msqid < 0)
  {
    perror(strerror(errno));
    exit(1);
  }

  // listen for requests
  msgbuf msg;
  while(1)
  {
    // receive an encrypted message
    msgrcv(msqid, &msg, sizeof(msgbuf), TYPE_ENCRYPTED, MSG_NOERROR);

    // decrypt it
    rot13(msg.line);
    msg.mtype = TYPE_DECRYPTED;

    // put the decrypted message on the queue
    msgsnd(msqid, &msg, sizeof(msgbuf), 0);
  }

  return 0;
}

void rot13(char * str)
{
  while(*str != '\0')
  {
    if('a' <= *str && *str <= 'z')
    {
      *str = ((*str - 'a' + 13) % 26) + 'a';
    }
    else if('A' <= *str && *str <= 'Z')
    {
      *str = ((*str - 'A' + 13) % 26) + 'A';
    }
    str++;
  }
}

static void cleanup(int signo)
{
  msgctl(msqid, IPC_RMID, NULL);
  exit(0);
}