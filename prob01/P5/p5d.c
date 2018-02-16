#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[], char* envp[])  
{ 
	char* user_name = getenv("USER_NAME");
	if(user_name != NULL){
		printf("Hello %s !\n",user_name);
	}
	else{
		printf("Nenhuma variável ambiente USER_NAME definida\n");
	}
	return 0; 
} 
