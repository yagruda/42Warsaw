/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   examples.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:46:26 by yhruda            #+#    #+#             */
/*   Updated: 2025/03/07 13:40:03 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// return NULL if an error occurs or nothing to read
// return Read Line when success

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

char* ft_test_strdup(char* str)
{
	char* line;

	line = strdup(str + 5);

	return (line);
}

int main (int argc, char **argv)
{
	int buffer_size;
	int chars_read;
	int fun;
	int counter = 0;


	int fd = open("test.txt", O_RDONLY);
	int fd2 = open("test.txt", O_RDONLY);
	int fd3 = open("test2.txt", O_RDONLY);

	char buffer[buffer_size];

// Цикл возвращает ненулевое значение (т.е. пока есть что читать).
// прочли первые n символов. внесли n символов в buffer. запустили while и добавили после последнего прочитанного знака конец строки

 	while (read(fd2, buffer, buffer_size) > 0)
	{
		counter++;
		printf("Read %d\n", counter);
	}

	while((chars_read = read(fd,buffer,buffer_size)))
	{
		buffer[chars_read] = '\0';
		printf("%s", buffer);
	}

	read(fd3, &fun, 1);
	fun = fun - '0';
	printf("\n result %d", fun);

	printf("\n----------------");

	printf("\n%s", ft_test_strdup("HelloWorld"));


	return (0);
}
