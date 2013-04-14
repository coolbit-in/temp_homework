#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main () {
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		printf("fork error\n");
		return 1;	
	}
	if (pid == 0) { 
		printf("I'm child process PID = %d\n",getpid());
	}
	else {
		printf("I'm parent process PID = %d\n",getpid());
	}
	return 0;
}
