#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define N 200

int main(int argc , char* argv[]){

	pid_t pid[N] = {0,};
	int i , status;

	for(i= 1 ; i<argc ; i++){
		//printf("CHILD %d : %s unzip! \n",i-1 , argv[i]);
		if((pid[i] = fork()) == 0){
			printf("CHILD %d : %s unzip! \n",i-1 , argv[i]);
			execl("/bin/gzip" ,"gzip","-d" , argv[i], NULL);
		}
	}
	i = 0;
	while(waitpid(pid[i++], &status ,0) > 0);

	exit(0);
}

