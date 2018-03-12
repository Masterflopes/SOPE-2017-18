#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
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
	
	int file1, file2, nr;
	file1 = open(argv[2], O_RDONLY);
	file2 = open(argv[3], O_WRONLY);
	
	char conteudo[LENGTH];
	
	while((nr = read(file1,conteudo,LENGTH)) >0){
		write(file2,conteudo,nr);
	}

	close(file1);
	close(file2);
	return 0;
}
