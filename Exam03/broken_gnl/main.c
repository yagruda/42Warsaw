#include "gnl.h"
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

char	*ft_strchr(char *s, int c)
{
	int	i = 0;
	while (s[i] != c && s[i] != '\0') // 1
		i++;
	if (s[i] == c)
		return (s + i);
	else
		return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t i = 0;

	while (i < n)
	{
		((char *)dest)[i] = ((char *)src)[i];/*((char *)dest)[i] = ((char *)src)[i];*/
		/*i++;*/
	}
	return (dest);
}

size_t	ft_strlen(char *s)
{
	size_t	ret = 0;
	while (*s)
	{
		s++;
		ret++;
	}
	return (ret);
}

int	str_append_mem(char **s1, char *s2, size_t size2)
{
	size_t	size1  = *s1 ? ft_strlen(*s1) : 0;
	char	*tmp = malloc(size2 + size1 + 1);
	if (!tmp)
	return (0);
	
	if (s1)
		memcpy(tmp, *s1, size1);
	memcpy(tmp + size1, s2, size2);
	tmp [size1 + size2] = 0;
	free(*s1);
	*s1 = tmp;
	return (1);
}

int	str_append_str(char **s1, char *s2)
{
	return (str_append_mem(s1, s2, ft_strlen(s2)));
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest </*<*/ src)
	return (memcpy(dest, src, n));
	else if (dest == src)
	return (dest);
	size_t	i = n; /* = n*/
	while (i > 0) /*>*/
	{
		i--;
		((char *)dest)[i] = ((char *)src)[i];
	}
	return (dest);
}

char	*get_next_line(int fd)
{
	printf("runed get_next_line\n");
	static char	b[BUFFER_SIZE + 1] = "";
	char	*ret = NULL;
	
	char	*tmp = ft_strchr(b, '\n');
	while (!tmp)
	{
		if (!str_append_str(&ret, b))
			return (NULL);
		b[0] = '\0';
		int	read_ret = read(fd, b, BUFFER_SIZE);
		if (read_ret == -1)
			return (NULL);
		if (read_ret == 0)
			break;
		b[read_ret] = 0;
		tmp = ft_strchr(b, '\n');
	}
	if (tmp)
	{
		if (!str_append_mem(&ret, b, tmp - b + 1))
		{
			free(ret);
			return (NULL);
		}
		ft_memmove(b, tmp + 1, ft_strlen(tmp + 1) + 1);
	}
	{
		b[0] = '\0';
		if (!ret || !*ret)
		{
			free(ret);
			return (NULL);
			}
			}
		return (ret);
	}
	
	int main(int argc, char **argv)
	{
		int fd;
		char *line;
		int line_count = 0;
	
		if (argc != 2)
		{
			printf("Usage: %s <filename>\n", argv[0]);
			printf("Or use: echo 'line1\\nline2\\nline3' | %s /dev/stdin\n", argv[0]);
			return (1);
		}
	
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			perror("Error opening file");
			return (1);
		}
		else 
		{
			printf("File '%s' opened successfully.\n", argv[1]);
		}
	
		printf("\n=== Testing get_next_line ===\n");
		
		get_next_line(fd); // to test if it works at all

		while ((line = get_next_line(fd)) != NULL)
		{
			printf("gnl work");
			line_count++;
			printf("Line %d: '%s'", line_count, line);
			if (line[strlen(line) - 1] != '\n')
				printf(" (no newline)");
			printf("\n");
			free(line);
		}
		
		printf("\n=== Test completed ===\n");
		printf("Total lines read: %d\n", line_count);
	
		close(fd);
		return (0);
	}