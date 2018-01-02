/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: BONUS PA                                                    
* Date: November 24th, 2017                                                                         
* Description: Create the game of connect four
*******************************************************************************************/
#ifndef CONNECT_FOUR
#define CONNECT_FOUR

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct cell
{
	int row;
	int col;
	int occupied;
	char color;
} Cell;

void init_board(Cell board[][7], int num_rows, int num_cols);
void print_board(Cell board[][7], int num_rows, int num_cols);
int populate_board(Cell board[][7], char color, int player, int col_index);
int vertical_check(Cell board[][7], int row, int column, int player);
int horizontal_check(Cell board[][7], int row, int column, int player);
int diagonal_check_one(Cell board[][7], int row, int column, int player);
int diagonal_check_two(Cell board[][7], int row, int column, int player);
int check_connect_four(Cell board[][7], char color, int player);

#endif
