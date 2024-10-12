#include "Bishop.h"

// commit test
Bishop::Bishop(int owner, int piece_id) : Piece(owner, piece_id)
{
	// assigning owner to owner_bishop
	this->owner_bishop = owner;

	// assigning piece_id to piece_id_bishop
	this->piece_id_bishop = piece_id;
}


bool Bishop::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{
	// if it si white`s turn
	if (get_owner() == 0)
	{

		int w_bishop_n_rows = 0;

		if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 12) ||
			board[endRow - 1][endCol - 1] == 0)
		{



			if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
			{

				w_bishop_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - w_bishop_n_rows == endRow - 1) && ((startCol - 1) + w_bishop_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}

				}
			}
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
			{

				w_bishop_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + w_bishop_n_rows == endRow - 1) && ((startCol - 1) + w_bishop_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}

				}
			}
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
			{

				w_bishop_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + w_bishop_n_rows == endRow - 1) && ((startCol - 1) - w_bishop_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
			{

				w_bishop_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1 - w_bishop_n_rows == endRow - 1) && (startCol - 1) - w_bishop_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}

				}
			}

		}
		
	}
	else if (get_owner() == 1)
	{

		int b_bishop_n_rows = 0;

		
		if ((board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 6) ||
			board[endRow - 1][endCol - 1] == 0)
		{


			if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
			{

				b_bishop_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - b_bishop_n_rows == endRow - 1) && ((startCol - 1) + b_bishop_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
			{

				b_bishop_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + b_bishop_n_rows == endRow - 1) && ((startCol - 1) + b_bishop_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
			{

				b_bishop_n_rows = (endRow - 1) - (startRow - 1);

				
				if (((startRow - 1) + b_bishop_n_rows == endRow - 1) && ((startCol - 1) - b_bishop_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}
				

			}
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
			{
				b_bishop_n_rows = (startRow - 1) - (endRow - 1);

				
				if (((startRow - 1) - b_bishop_n_rows == endRow - 1) && ((startCol - 1) - b_bishop_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}

		}

	}

	cout << "\n\tInvalid move!\n";
	return false;
}
