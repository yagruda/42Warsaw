#include <stdbool.h>
#include <unistd.h>

int main()
{
	if (true)
	{
		write(1, "Hello, World!\n", 14);
	}
	return 0;
}