#include <stdio.h> 

int main(int argc, char* argv[])  
{ 
	int i;

	if(argc < 2){
		printf("Missing your name\n");
		return 0;
	}
	else if (argc > 1){
		printf("Hello ");
		for(i = 1; i < argc; i++){
			printf("%s ", argv[i]);
		}
		printf("!\n");
	} 
	return 0; 
} 
