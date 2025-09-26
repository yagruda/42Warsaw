// Write a programm taht will take one and only one argument s.

// Your programm will then read from stdin and write all the content read in stdout
// except that every occurence of s must be replaced by '*'.

// For example :

// ./filter bonjour
// will behave the same way as:
// sed 's/bonjour/*******/g'

// in case of error during read or a malloc you must write "Error: " followed by
// the error message in stderr and return 1.

// $> echo 'abcdefgaaaabcdefabc' | ./filter abc | cat -e
// ***defgaaa***def***

// If the program is called whitout argument or with an empty argument or with
// multiples arguments it must return 1.

#include <string.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10 
#endif

void ft_filter(char* str, char* chn)
{
	int i = 0;
	int k = 0;
	int len = strlen(chn);
	while (str[i])
	{
		while (str[i + k] == chn[k])
		{
			k++;
		}
		if (len == k)
		{
			while(k > 0 && str[i] != '\0')
			{
				write(1, "*", 1);
				k--;
			}
			i += len;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
		}
		
	}
}

int main(int argc, char** argv)
{
	int i = 0;
	int r = 1;
	char buffer[99999];

	if (argc < 2)
		return 0;

	while (r > 0)
	{
		r = read(0, &buffer[i], BUFFER_SIZE);
		if (r == -1)
		{
			perror("Error: ");
			return 1;
		}
		i += r;
	}
	buffer[i] = '\0';

	ft_filter(buffer, argv[1]);

	//printf("buffer %s", buffer);
	
	return 0;
}