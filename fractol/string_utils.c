#include "fractol.h"

// ft_strncmp compares two strings up to n characters
int ft_strncmp(char *s1, char *s2, int n)
{
	if (NULL == s1 || NULL == s2 || n <= 0)
		return (0);
	while (*s1 == *s2 && n > 0 && *s1 != '\0')
	{
		++s1;
		++s2;
		--n;
	}
	// chars are basically 1 byte int
	// when 0, it means that the strings are equal
	return (*s1 - *s2);
}

// putstr_fd prints a string to a file descriptor
// s: string to print
// fd: file descriptor
// returns: void
void	putstr_fd(char *s, int fd)
{
	if (NULL == s || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1); 
		putstr_fd(s + 1, fd); 
	}
}