#include <stdio.h>
#include <unistd.h>
#define BUFFSIZE 4096

int main()
{
	int n;

	char buf[4096];

	while((n = read(STDIN_FILENO, buf ,BUFFSIZE)) > 0)
	{
		if( write(STDOUT_FILENO, buf, n) != n)
		{
			printf("write error \n");
			return 1;
		}
	}

	if(n < 0)
	{
		printf("read error \n");
		return 2;
	}
	return 0;
}
