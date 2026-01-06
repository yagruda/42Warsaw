#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

// if BUFFER_SIZE is not defined, set it to 1000. Because it can be defined in the compilation command
// gcc -D BUFFER_SIZE=32 get_next_line.c get_next_line_utils.c
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
#endif


char *get_next_line(int fd);
char* ft_get_line(char** saved_text);

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *src);


#endif
