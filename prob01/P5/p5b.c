#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[])  
{ 
	int i = 0;
	int j = 5;
	char user[] = "USER";
	
	while(envp[i] != NULL){
		if(!strncmp(envp[i],user,4)){
			printf("Hello ");
			while(envp[i][j] != '\0'){
				printf("%c", envp[i][j]);
				j++;
			}
			printf(" !\n");
		}
		i++;
	}
	return 0; 
} 
