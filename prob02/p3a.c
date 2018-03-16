#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define LENGTH 265

int main(int argc, char* argv[]){
		
	if(argc == 1){
		printf("Missing txt file\n");
		return 1;
	}
	
	if(argc > 2){
		printf("Error!");
		return 1;
	}
	
	int file1, nr;
	file1 = open(argv[1], O_RDONLY);
	
	char conteudo[LENGTH];
	
	while((nr = read(file1,conteudo,LENGTH)) >0){
		printf("%s",conteudo);
	}

	close(file1);
	return 0;
}
