/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 13:46:26 by yhruda            #+#    #+#             */
/*   Updated: 2025/03/07 13:49:05 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// return NULL if an error occurs or nothing to read
// return Read Line when success

// FIX work with BUFFER_SIZE > 1. For this I need to use malloc and free
#include "get_next_line.h"

char* get_next_line(int fd)
{
    static char* stash;
    char* buffer;
    int chars_read;
    char* line;
    char* temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);

    buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    // if buffer = null (failed malloc returns NULL)
    if (!buffer)
        return (NULL);

// To Work With strjoin, strchr and other string functions I need to initialize stash with empty string. Otherwise I would get undefined behavior
    if (!stash)
        stash = ft_strdup("");

    // Everytime we run while we do read. E.g   1 while run = 1 read run.
    while (ft_strchr(stash, '\n') == NULL && (chars_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[chars_read] = '\0';
        temp = ft_strjoin(stash, buffer);
        free(stash);
        stash = temp;
    }

        // if chars_read = -1 (failed read returns -1) buffer will not contact valid data. Subsequent operations may lead to undef, segfault. To be able to debug free buffer and stash and return NULL
    // stash = NULLL to avoid undefined behavior in ft_strjoin and sobsequent operations
    if (chars_read == -1)
    {
        free(buffer);
        free(stash);
        stash = NULL;
        return (NULL);
    }
    else
        free(buffer);

// if stash isn't null and isn't pointing to the end of the string
    if (stash && *stash)
    {
        printf ("\nstash = %s\n", stash);
        line = ft_get_line(&stash);
        printf("\nline = ft_get_line(&stash) = %s\n", line);

        // temp = part of stash after '\n' or '\0'. E.g FirstLineX\nSeco = 14,  -> temp = Seco. ft_strlen(line) = 9
        temp = ft_strdup(stash + ft_strlen(line));
        printf("\ntemp after ft_strdup stash+ ft_strlen (line) =%s", temp);
        free(stash);
        stash = temp;
        printf("\nstash after free & stash = temp %s\n", stash);
        return (line);
    }

    free(stash);
    stash = NULL;
    return (NULL);
}

char* ft_get_line(char** saved_text)
{
    int counter;
    char* line;

    // if saved_text is NULL or saved_text is pointing to NULL or saved_text is pointing to empty string (string starts with '\0')
    if (!saved_text || !(*saved_text) || (*saved_text)[0] == '\0')
        return (NULL);

    counter = 0;

    // count characters until '\n' or '\0'
    while ((*saved_text)[counter] && (*saved_text)[counter] != '\n')
        counter++;

    line = malloc(sizeof(char) * (counter + 2));
    if (!line)
        return (NULL);

    counter = 0;

    // copy characters until '\n' or '\0'
    while ((*saved_text)[counter] && (*saved_text)[counter] != '\n')
    {
        line[counter] = (*saved_text)[counter];
        counter++;
    }

    if ((*saved_text)[counter] == '\n')
    {
        line[counter] = '\n';
        counter++;
    }

    line[counter] = '\0';
    return (line);
}

 int main() {
    int fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Error\n");
		return (1);
	}

    char *line;
	int i = 0;
	int j = 0;
    while (j < 1) {
		printf("\nStarted main while run times: %d \n", ++i);
		line = get_next_line(fd);
        printf("\nBuffer text (final): \n%s\n", line);
        line = get_next_line(fd);
        printf("\nBuffer text (final): \n%s\n", line);
        line = get_next_line(fd);
        printf("\nBuffer text (final): \n%s\n", line);

        free(line);
		j++;
    }
    close(fd);
	return 0;
}
