/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: BONUS PA                                                    
* Date: November 24th, 2017                                                                         
* Description: Create the game of connect four
*******************************************************************************************/
#include "StringsStructs.h"

void rules()
{
	printf("To win Connect Four you must be the first player to get four of your\n");
	printf("colored checkers in a row either horizontally, vertically or diagonally.\n\n");
}

void display_menu() // Displays the menu options
{
	int menu_option = 0;

	printf("WELCOME TO CONNECT FOUR!\n\n");
	printf("1. Display game rules\n");
	printf("2. Play Game\n");
	printf("3. Exit\n");
}

int get_option(void) // Gets the option from the user
{					// Used in previous PA's
	int option = 0, status = 0;

	status = scanf("%d", &option);
	if (status == 0)
	{
		printf("Failed at reading the option!\n");
	}
	return option;
}

int determine_option(void) // Determines if the option is valid
{						  // Used in previous PA's
	int option = 0;

	do // input validation loop
	{
		display_menu();
		option = get_option();
		system("cls");
	} while ((option < 1) || (option > 3));

	return option;
}

void init_board(Cell board[][7], int num_rows, int num_cols)
{ // Copied from the starter code
	int row_index = 0, col_index = 0;

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			board[row_index][col_index].row = row_index;
			board[row_index][col_index].col = col_index;
			board[row_index][col_index].color = '\0';
			board[row_index][col_index].occupied = 0;
		}
	}
}

/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: BONUS PA                                                    
* Date: November 27nd, 2017                                                                         
* Description: Day 2 of working on this code
*******************************************************************************************/

void print_board(Cell board[][7], int num_rows, int num_cols)
{ // Took a similar approach to the one used in battleship
	int row_index = 0, col_index = 0;

	printf("  1");
	for (int number = 2; number < 8; number++)
	{
		printf("   %d", number);
	}
	putchar('\n');

	for (; row_index < num_rows; ++row_index)
	{
		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("%3c ", '-');
		}

		putchar('\n');

		for (col_index = 0; col_index < num_cols; ++col_index)
		{
			printf("| %c ", board[row_index][col_index].color);
		}
		putchar('|');
		putchar('\n');
	}
	for (col_index = 0; col_index < num_rows + 1; ++col_index)
	{
		printf("%3c ", '-');
	}
	printf("\n");
}

int user_choice(Cell board[][7], int player)
{ // Copied and pasted the battleship code and modified it for this program
	int col_index = 0, flag = 0;

	do // Runs this code
	{
		do // Gets the user input
		{
			printf("Choose a column wisely: ");
			scanf("%d", &col_index);
			col_index--;
		} while ((col_index < 0) || (col_index > 6)); // Makes sure its a valid column

		if (board[0][col_index].occupied == 1)
		{ // Checks to see if it is occupied
			system("cls");
			print_board(board, 6, 7);
			printf("\nPlayer %d's turn!\n", player);
			printf("You must be blind, new column please!\n");
			flag = 0;
		}
		else
		{
			flag = 1;
		}
	} while (flag == 0);

	return col_index;
}

/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: BONUS PA                                                    
* Date: December 2nd, 2017                                                                         
* Description: Day 3 of working on this code
*******************************************************************************************/

int populate_board(Cell board[][7], char color, int player, int col_index)
{ // Copied and Pasted my battleship code and made some changes
	int row_index = 0;

	// Got help from Ryan Manny for this part
	for (row_index = 0; (board[row_index][col_index].occupied == 0 && row_index < 6); row_index++){}
	row_index--;

	board[row_index][col_index].occupied = 1;
	board[row_index][col_index].col = col_index;
	board[row_index][col_index].row = row_index;

	// This was added based on the Github code in the last function
	// It allows for me to check if there is a four in a row and choose a winner
	if (board[row_index][col_index].color = color)
	{
		if (check_connect_four(board, color, player) > 0)
			return 1;
		else
			return 0;
	}
}

/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: BONUS PA                                                    
* Date: December 4th, 2017                                                                         
* Description: Day 4 of working on this code, code below is based on battleship code
*******************************************************************************************/

int vertical_check(Cell board[][7], int row, int column, int player)
{ // This is code that i modified from below
	// Checks vertically down

	int vertical = 0;

	if (player == 1)
	{
		do
		{
			row--;
			vertical++;
		} while (board[row][column].color == 'R');
	}

	if (player == 2)
	{
		do
		{
			row--;
			vertical++;
		} while (board[row][column].color == 'G');
	}

	if (vertical >= 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int horizontal_check(Cell board[][7], int row, int column, int player)
{ // This is code that i modified from below
	// Checks horizontally to the right

	int horizontal = 0;

	if (player == 1)
	{
		do
		{
			column++;
			horizontal++;
		} while (board[row][column].color == 'R');
	}
	if (player == 2)
	{
		do
		{
			column++;
			horizontal++;
		} while (board[row][column].color == 'G');
	}

	if (horizontal >= 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int diagonal_check_one(Cell board[][7], int row, int column, int player)
{ // This is code i had from the time i tried making an AI for battleship
	// It checks diagonals going Northeast

	int diagonal = 0;

	if (player == 1)
	{
		do
		{
			row--;
			column--;
			diagonal++;
		} while (board[row][column].color == 'R');
	}

	if (player == 2)
	{
		do
		{
			row--;
			column--;
			diagonal++;
		} while (board[row][column].color == 'G');
	}

	if (diagonal >= 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int diagonal_check_two(Cell board[][7], int row, int column, int player)
{ // This is code i had from the time i tried making an AI for battleship
	// Checks diagonals going Northwest

	int diagonal = 0;

	if (player == 1)
	{
		do
		{
			row--;
			column++;
			diagonal++;
		} while (board[row][column].color == 'R');
	}

	if (player == 2)
	{
		do
		{
			row--;
			column++;
			diagonal++;
		} while (board[row][column].color == 'G');
	}

	if (diagonal >= 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: BONUS PA                                                    
* Date: December 9th, 2017                                                                         
* Description: Day 5 of working on this code, finally found a way to make this last function work!
*******************************************************************************************/

int check_connect_four(Cell board[][7], char color, int player)
{ // This code was copied from Github, I dont remember the actual username (Had to clean my harddrive and browser history got deleted)
  // I understand how and why it works, i was mainly confused on the if statement

	int row_index = 0, col_index = 0, winner = 0;

	for (row_index = 0; row_index < 6; ++row_index)
	{
		for (col_index = 0; col_index < 7; ++col_index)
		{
			if (board[row_index][col_index].color == color)
			{ // This portiom underneath was the cause of my confusion which i get now
				winner += vertical_check(board, row_index, col_index, player);
				winner += horizontal_check(board, row_index, col_index, player);
				winner += diagonal_check_one(board, row_index, col_index, player);
				winner += diagonal_check_two(board, row_index, col_index, player);
			}
		}
	}

	if (winner >= 1)
	{
		return 1;
	}
	else if (winner < 1)
	{
		return 0;
	}
}