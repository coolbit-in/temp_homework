#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main () {
	pid_t pid;
	pid = fork();
	if (pid < 0) {
		printf("fork error\n");
		return 1;	
	}
	if (pid == 0) {
		char *const ps_argv[] = {"ps", "ax", 0};
		execv("/bin/ps", ps_argv); 
	}
	else {
		int st;
		wait(&st);
		printf("Child process was finished\n");
	}
	return 0;
}
