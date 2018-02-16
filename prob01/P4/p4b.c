#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])  
{ 
	int i;
	int rep = atoi(argv[argc-1]);

	if(argc < 2){
		printf("Missing your name\n");
		return 0;
	}
	else if (argc > 1){
		while(rep > 0){
			printf("Hello ");
			for(i = 1; i < (argc-1); i++){
				printf("%s ", argv[i]);
			}
			printf("!\n");
			rep--;
		}
	} 

	return 0; 
} 
