//FOLHA 2 - p2b.c
//LEITURA DE PASSWORD, SEM ECOAR CARACTER LIDO

#include <termios.h>
#include <unistd.h>
#include <string.h>

#define MAX_PASSWD_LEN 20

int main(void)
{
	struct termios term, oldterm;
	int i;
	char pass[MAX_PASSWD_LEN+1], ch;

	char password[] = "\nPassword? ";
	char password2[] = "\n\nPassword: ";

	tcgetattr(STDIN_FILENO, &oldterm);
	term = oldterm;
	term.c_lflag &= ~(ECHO | ECHOE | ECHOK | ECHONL | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);

	write(STDOUT_FILENO, password, strlen(password));
	i=0;
	while (i < MAX_PASSWD_LEN && read(STDIN_FILENO, &ch, 1) && ch != '\n') {
		pass[i++] = ch;
		write(STDOUT_FILENO, "*", 1);
	}
	pass[i] = 0;

	tcsetattr(STDIN_FILENO, TCSANOW, &oldterm);
	write(STDOUT_FILENO, password2, strlen(password2));
	write(STDOUT_FILENO, pass, strlen(pass));
	write(STDOUT_FILENO, "\n\n", 1);

	return 0;
}

