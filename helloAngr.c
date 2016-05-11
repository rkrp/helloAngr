#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void almostWin(char *);
void fail();
void win(char *);

int main(int argc, char * argv[])
{

	
	if (argc != 2)
	{
		printf("Usage: ./helloAngr <password>\n");
		exit(0);
	}

	if (strlen(argv[1]) < 8)
	{
		fail();
	}

	char *password;
	password = malloc(10);
	strncat(password, argv[1], 10);

	if ((password[4] ^ password[1]) + password[6] == password[2])
	{
		almostWin(password);
	}
	else
	{
		fail();
	}
	return 0;
}

void almostWin(char *password)
{
	if (password[1] ^ password[5] == password[5] ^ password[3])
	{
		win(password);
	}
	else
	{
		fail();
	}
}

void fail()
{
	printf("fail\n");	
	exit(1);
}

void win(char *password)
{
	if (password[7] !=  password[0])
	{
		printf("win!\n");
		exit(0);
	}
	else
	{
		fail();
	}
}
