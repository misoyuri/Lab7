#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define N 200

int main(int argc , char* argv[]){

	pid_t pid[N] = {0,};
	int i = 0 , status;
	int size;
	char files[N][N];
	for(i= 0 ; fgets(files[i],100,stdin) ; i++);
	size = i;
	for(i = 0 ; i<size ; i++){
		files[i][strlen(files[i])-1] = '\0';
	}
	for(i= 0 ; i<size ; i++){
		
		if((pid[i] = fork()) == 0){
			printf("CHILD %d :%s\n",i,files[i]);
			execl("/bin/gzip","gzip","-d",files[i],NULL);
			exit(1);
		}
	}
	i = 0;
	while(waitpid(pid[i++], &status ,0) > 0);

	exit(0);
}

