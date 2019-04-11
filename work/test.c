#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sts/wait.h>

int main(void){
	pid_t pid;
	int status;
	if ((pid = fork()) < 0)
		exit(1);
	else if (pid == 0){
		printf("hi from child\n");
		exit(7);
	}
	else{
		if(wait(&status) != pid)
			perror("wait error");
			printf(" hi from parent\n");
			if(WIFEXITED(status))
				printf("normal termination, exit status= %d\n", WEXITSTATUS(status));
			else if (WIFSIGNALED(status))
				printf("abnormal termination, signal number = %d\n",WTERMSIG(status));

			exit(EXIT_SUCCESS);


}

}

