/*******************************************************************************************
* Programmer: Marco Arceo                                                                      
* Class: CptS 121, Fall  2017; Lab Section 21                                    
* Programming Assignment: BONUS PA                                                    
* Date: November 24th, 2017                                                                         
* Description: Create the game of connect four
*******************************************************************************************/
#include "StringsStructs.h"

int main(void)
{
	//Cell c1 = {0, 0, 0, '\0'};
	Cell board[6][7] = { {{0, 0, 0, '\0'}, {0, 1, 0, '\0'}} };
	
	int option = 0, col_index = 0;
	bool game = true, winner = true;

	do // PROGRAM LOOP
	{
		init_board(board, 6, 7);
		do // MENU LOOP
		{
			option = determine_option();
			switch (option)
			{
			case 1: rules();
				system("pause");
				system("cls");
				break;
			case 3: printf("Goodbye!\n");
				game = false;
				return 0;
			}
		} while (option != 2 && option != 3);

		do // MAIN GAME LOOP
		{
			// PLAYER 1
			print_board(board, 6, 7);
			printf("\nPlayer %d's turn!\n", 1);
			col_index = user_choice(board, 1);
			winner = populate_board(board, 'R', 1, col_index);
			if (winner != 0)
			{
				system("cls");
				print_board(board, 6, 7);
				printf("\nThe winner is Player 1!\n");
				winner = true;
				system("pause");
				system("cls");
				break;
			}
			system("cls");

			// PLAYER 2
			print_board(board, 6, 7);
			printf("\nPlayer %d's turn!\n", 2);
			col_index = user_choice(board, 2);
			winner = populate_board(board, 'G', 2, col_index);
			if (winner != 0)
			{
				system("cls");
				print_board(board, 6, 7);
				printf("\nThe winner is Player 2!\n");
				winner = true;
				system("pause");
				system("cls");
				break;
			}
			system("cls");

		} while (winner == false);

	} while (game == true);

	return 0;
}
