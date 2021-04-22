#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

enum {r_OK = 0, r_EXIT = -1, r_ERROR = -2};

int prompt(const char * ps, int (*handler)(const char *));
int handler(const char * str);

int main(int argc, char * argv[])
{
	  if(isatty(fileno(stdin))){
		  while(prompt(">>", &handler) != r_EXIT);
	  }
	  else{
		  char str[80];
		  do{
			  fgets(str, 80, stdin);
			  str[strlen(str) - 1] = '\0';
		  }
		  while(handler(str) != r_EXIT);
	  }
	  return 0;
}

int prompt(const char * ps, int (*handler)(const char *))
{
       	char str[80];
	fputs(ps, stdout);
	fputc(' ', stdout);
	fflush(stdout);
	fgets(str, 80, stdin);
	str[strlen(str) - 1] = '\0';
	return (*handler)(str);
}

int handler(const char * str)
{
	if(!strcmp(str, "pid")){
		printf("%d\n", getpid());
		return r_OK;
	}
	else if(!strcmp(str, "uid")){
		printf("%d\n", getuid());
		return r_OK;
	}
	else if(!strcmp(str, "exit")){
		return r_EXIT;
	}
	else if (!strcmp(str, "ls")){
		int pid;
		int stat;
		pid = fork();
		if (pid == 0) {
			execlp ("/bin/ls", "ls", "-l", NULL);
			exit(0);
		}
		else
			wait(&stat);
		if WIFEXITED(stat)
			printf("Exit status: %d\n", WEXITSTATUS(stat));
	}
	else
	{
		printf("Error: unknown command %s\n", str);
		return r_ERROR;
	}
}
