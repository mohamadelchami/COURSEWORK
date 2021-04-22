#include <fcntl.h>
#include <semaphore.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

static void cleanup(int signo);

sem_t * semid;

int main(int argc, char * argv[])
{
	int s;
	struct sigaction act;
	act.sa_handler = cleanup;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_RESTART;
	sigaction(SIGTERM, &act, NULL);
	sigaction(SIGINT, &act, NULL);

	semid = sem_open("rocksem", O_CREAT, 0666, 4);
	if(semid == SEM_FAILED){
		perror(strerror(errno));
		exit(1);
	}

	while(1){
		sem_post();
		sleep(2);
		sem_wait(semid);
		while(1){
			printf("I'm working!");
		}
	}
	return 0;
}

static void cleanup(int signo)
{
	sem_post(); 
	sem_close(semid);
	    sem_unlink("rocksem");
	      exit(0);
}


