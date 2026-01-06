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

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int ft_strlen(char* str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

void filter (char* buffer, char* istr)
{
	int i = 0;
	int k = 0;
	int len = ft_strlen(istr);

	while (buffer[i])
	{
		k = 0;
		while (buffer[i + k] == istr[k])
			k++;
		if (len == k)
		{
			while (k > 0)
			{
				write(1, "*", 1);
				k--;
			}
			i += len;
		}
		else
		{
			write(1, &buffer[i], 1);
			i++;
		}
	}

}

int main(int argc, char** argv)
{
	if (argc < 2)
		return 1;
	
	int i = 0;
	int r = 1;
	char buffer[999];

	while (r > 0)
	{
		r = read(0, &buffer[i], 10);
		i += r;
	}
	buffer[i] = '\0';

	filter(buffer, argv[1]);

	return 0;
}