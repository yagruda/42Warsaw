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


void filter(char* buffer, char* ar)
{

}

int main(int argc, char** argv)
{
	char buffer[999];
	int r = 0;
	int i = 0;
	
	if (argc < 2)
		return 0;

	while (r > 0)
	{
		r = read(0, &buffer[i], BUFFER_SIZE);
		if (r == -1)
		{
			perror("Error:");
			return 1;
		}
		i += r;
	}
	buffer[i] = '\0';


}
