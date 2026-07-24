/*
[EN]

Assignment name : life
Expected files : *.c *.h
Allowed functions: atoi, read, putchar, malloc, calloc, realloc, free
--------------------------------------------------------------------------------
You must write a program that will simulate a game of life.
The prototype of this program is the following:
./life width height iterations
Width and height are the dimensions of the board and iterations is the number of
iterations of the game of life.
the initial configuration of the board will be drawn by a sequence of commands
in the standard input.
Imagine a pen starting in the top left corner of the board.
Each command is one of these characters:

w a s d -> move the pen up, left, bottom, and right.
x -> lift or lower the pen in order to start or stop drawing.

Once end of file is reached, your program must simulate a game of life on this
board and print the result in stdout (each cell alive will be represented by
the character 'O' and each dead cell will be represented by a space)
each cell outside of the array will be considered dead
Example:
$> echo 'sdxddssaaww' | ./a.out 5 5 0 | cat -e
$
OOO $
O O $
OOO $
$
$> echo 'sdxssdswdxddddsxaadwxwdxwaa' | ./a.out 10 6 0 | cat -e
$
O OOO $
O O $
OOO O $
O OOO $
$
$> echo 'dxss' | ./a.out 3 3 0 | cat -e
O $
O $
O $
$> echo 'dxss' | ./a.out 3 3 1 | cat -e
$
OOO$
$
$> echo 'dxss' | ./a.out 3 3 2 | cat -e
O $
O $
O $
*/

#include "main.h"

#include <stdio.h>
#include <unistd.h>

int init_game(t_life* obj, char** argv)
{
	obj->width = atoi(argv[1]);
	obj->height = atoi(argv[2]);
	obj->iterations = atoi(argv[3]);
	obj->i = 0;
	obj->j = 0;
	obj->draw = 0;
	obj->dead = ' ';
	obj->alive = '0';

	obj->board = (char**)malloc((obj->height) * sizeof(char*));
	if (!obj->board)
		return -1;

	for (int i = 0; i < obj->height; i++)
	{
		obj->board[i] = (char*)malloc((obj->width) * sizeof(char));
		if (!obj->board[i])
			return -2;

		for (int j = 0; j < obj->width; j++)
		{
			obj->board[i][j] = obj->dead;
		}
	}

	return 0;

};

void fill_board(t_life* obj)
{
	int flag;
	char buffer;

	while(read(STDIN_FILENO, &buffer, 1) == 1)
	{
		flag = 1;
		switch(buffer)
		{
			case 'w':
				if (obj->i > 0)
					obj->i--;
				break;
			case 'a':
				if (obj->j > 0)
					obj->j--;
				break;
			case 's':
				if(obj->i < obj->height - 1)
					obj->i++;
				break;
			case 'd':
				if(obj->j < obj->width - 1)
					obj->j++;
				break;
			case 'x':
				obj->draw = !(obj->draw);
			default:
				flag = 0;
				break;
		}

		if (flag && obj->draw)
		{
			if ((obj->i >= 0 && obj->i < obj->height) && (obj->j >= 0 && obj->j < obj->width))
			{
				obj->board[obj->i][obj->j] = obj->alive;
			}
		}


	}
}


int play_game(t_life* obj)
{
	// declare and malloc a temporary board
	// go through each cell in obj, run count_neighbours function, 
	// if this cell == alive -> if neighbous 2 || 3 = make alive in temp arr
	// if this cell == dead -> if 3 neighbours = make alive else dead
	// clear obj board and assign obj->board = temp board 

	char** temp;
	temp = malloc(obj->height * sizeof(char*));
	if (!temp)
		return -1;
	for(int i = 0; i < obj->height; i++)
	{
		temp[i] = malloc(obj->width * sizeof(char*));
		if (!temp[i])
			return -1;
	}


	for(int i = 0; i < obj->height; i++)
	{
		for (int j = 0; j < obj->width; j++)
		{
			int neighbours = count_neighbours(obj, i, j);
			if (obj->board[i][j] == obj->alive)
			{
				if (neighbours == 2 || neighbours == 3)
				{
					temp[i][j] = obj->alive;
				}
				else
				{
					temp[i][j] = obj->dead;
				}
			}
			else if (obj->board[i][j] == obj->dead)
			{
				if(neighbours == 3)
				{
					temp[i][j] = obj->alive;
				}
				else
				{
					temp[i][j] = obj->dead;
				}
			}
		}
	}

	free_board(obj);
	obj->board = temp;
	return 1;
}

int count_neighbours(t_life* obj,int i, int j)
{
	int counter = 0;

	for (int y = -1; y < 2; y++)
	{
		for (int x = -1; x < 2; x++)
		{
			// skip current position
			if (y == 0 && x == 0)
				continue;

			int ni = i + y;
			int nj = j + x;
			
			// boundary check
			//    alive check
			if (ni >= 0 && nj >= 0 && ni < obj->height && nj < obj->width)
				if(obj->board[ni][nj] == obj->alive)
					counter++;
		}
	}
	
	return counter;
}

void free_board(t_life* obj)
{
	for(int i = 0; i < obj->height; i++)
	{
		// do I really need if check here (if game->board[i])
		free(obj->board[i]);
		
	}
	free(obj->board);
}

void print_board(t_life* obj)
{
	for(int i = 0; i < obj->height; i++)
	{
		for (int j = 0; j < obj->width; j++)
		{
			putchar(obj->board[i][j]);
		}
		putchar('\n');
	}
};




int main(int argc, char** argv)
{
	if (argc < 4)
		return 1;
	(void)argv;

	t_life obj;

	if (init_game(&obj, argv) < 0)
		return -1;

	fill_board(&obj);

	for(int i = 0; i < obj.iterations; i++)
	{
		//printf("\n-----------------\n");
		//print_board(&obj); // delete me!
		if (play_game(&obj) == -1)
		{
			printf("fuck");
			//free_board
			return 1;
		}
					
	}
	print_board(&obj);
	free_board(&obj);


	return 0;
}