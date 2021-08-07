#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void	l(char *msg){if(debug) printf("%s", msg);}
void	ld(int nb){if(debug) printf("%d",nb);}
void	enl(){if(debug) printf("\n");}

int	main(int argc, char *argv[])
{
	(void)argc;(void)argv;
	l("Start\n");
	printf("Debug \t\t%d\nBUFFER_SIZE \t%d\n", debug, BUFFER_SIZE);
	int fd = open(tfile, O_RDONLY);
	l("fd\t\t");ld(fd);enl();
	l(tfile);
	if (fd < 1)
	{
		l("Error opening file");
		return (-1);
	}
	char tmp[32000];
	read(fd, tmp, BUFFER_SIZE);
	l(tmp);
	return (0);
}
