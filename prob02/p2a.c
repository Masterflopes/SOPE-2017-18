#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 265

int main(int argc, char* argv[]){
	
	if(strncmp(argv[1], "copy", strlen("copy")) != 0){
		printf("Wrong function call\n");
		return 1;
	}
	
	if(argc == 2){
		printf("Missing files\n");
		return 1;
	}
	
	if(argc == 3){
		printf("Missing second file\n");
		return 1;
	}
	
	if(argc > 4){
		printf("Error!");
		return 1;
	}
	
	FILE *ficheiro1 = fopen(argv[2], "r");
	FILE *ficheiro2 = fopen(argv[3], "w");
	
	char conteudo[LENGTH];
	
	while(fgets(conteudo,LENGTH,ficheiro1) != NULL){
		fputs(conteudo,ficheiro2);
	}

	fclose(ficheiro1);
	fclose(ficheiro2);
	return 0;
}