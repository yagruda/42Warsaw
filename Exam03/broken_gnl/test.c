#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char** argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		printf("error");
	else 
		printf("fd is %d", fd);

	(void) argc;
	close(fd);
	return 0;
}

/* = *s1 ? ft_strlen(*s1) : 0;*/ 


/*if (*s1)*/

/*	*/