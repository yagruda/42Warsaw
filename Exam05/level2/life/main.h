#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>

typedef struct s_life
{
	int height;
	int width;
	int iterations;
	int i; // y
	int j; // x
	int draw;
	char dead;
	char alive;
	char** board;
} t_life;

int init_game(t_life* obj, char** argv);
void fill_board(t_life* obj);
int play_game(t_life* obj);
int count_neighbours(t_life* obj,int i, int j);
void free_board(t_life* obj);
void print_board(t_life* obj);

#endif