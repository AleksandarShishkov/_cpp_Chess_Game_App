#include "Queen.h"


Queen::Queen(int owner, int piece_id) : Piece(owner, piece_id)
{
	// assigning owner to owner_queen
	this->owner_queen = owner;

	// assigning piece_id to piece_id_queen
	this->piece_id_queen = piece_id;
}



bool Queen::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{

	
	// if it is white`s turn
	if (get_owner() == 0)
	{
		// integer to hold the number of the rows
		int w_queen_n_rows = 0;

		// integer to hold the number of the columns
		int w_queen_n_cols = 0;

		
		// id the destination square is valid
		if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 12) ||
			board[endRow - 1][endCol - 1] == 0)
		{

			// validating the white queen`s upper vertical
			if ((startRow - 1 > endRow - 1) && (endCol - 1 == startCol - 1))
			{
				w_queen_n_rows = (startRow - 1) - (endRow - 1);

				if ((startRow - 1) - w_queen_n_rows == endRow - 1)
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}

				}

			}
			// validating the white queen`s lower vertical
			else if ((startRow - 1 < endRow - 1) && (endCol - 1 == startCol - 1))
			{

				w_queen_n_rows = (endRow - 1) - (startRow - 1);

				if ((startRow - 1) + w_queen_n_rows == endRow - 1)
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			// vallidating the white queen`s right side horizontally
			else if ((startRow - 1 == endRow - 1) && (endCol - 1 > startCol - 1))
			{

				w_queen_n_cols = (endCol - 1) - (startCol - 1);

				if ((startCol - 1) + w_queen_n_cols == endCol - 1)
				{
					// validating if the  move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			// validating the white queen`s left side horizontally
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 > endCol - 1))
			{
				
				w_queen_n_cols = (startCol - 1) - (endCol - 1);

				if ((startCol - 1) - w_queen_n_cols == endCol - 1)
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			// valdiating the white queen`s upper right diagonal
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
			{
				w_queen_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - w_queen_n_rows == endRow - 1) && 
					((startCol - 1) + w_queen_n_rows == endCol - 1))
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}
				
			}
			// validating the white queen`s lower right diagonal
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
			{

				w_queen_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + w_queen_n_rows == endRow - 1) &&
					((startCol - 1) + w_queen_n_rows == endCol - 1))
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}
			}
			// vallidating the white queen`s lower left diagonal
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
			{

				w_queen_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + w_queen_n_rows == endRow - 1) &&
					((startCol - 1) - w_queen_n_rows == endCol - 1))
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			// validating the white queen`s upper left diagonal
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
			{
				w_queen_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - w_queen_n_rows == endRow - 1) && ((startCol - 1) - w_queen_n_rows == endCol - 1))
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}

				}
			}
		}


	}
	// if it is black`s move
	else if (get_owner() == 1)
	{


		// integer to hold the number of the rows
		int b_queen_n_rows = 0;

		// integer to hold the number of the columns
		int b_queen_n_cols = 0;

		
		// if the destination square is valid
		if ((board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 6) ||
			board[endRow - 1][endCol - 1] == 0)
		{

			// validating the black queen`s upper vertical
			if ((startRow - 1 > endRow - 1) && (startCol - 1 == endCol - 1))
			{
				b_queen_n_rows = (startRow - 1) - (endRow - 1);

				if ((startRow - 1) - b_queen_n_rows == endRow - 1)
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}

				}

			}
			// validating the black queen`s lower vertical
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 == endCol - 1))
			{

				b_queen_n_rows = (endRow - 1) - (startRow - 1);

				if ((startRow - 1) + b_queen_n_rows == endRow - 1)
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			// vallidating the black queen`s right side horizontally
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 < endCol - 1))
			{

				b_queen_n_cols = (endCol - 1) - (startCol - 1);

				if ((startCol - 1) + b_queen_n_cols == endCol - 1)
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			// validating the black queen`s left side horizontally
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 > endCol - 1))
			{

				b_queen_n_cols = (startCol - 1) - (endCol - 1);

				if ((startCol - 1) - b_queen_n_cols == endCol - 1)
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			// valdiating the black queen`s upper right diagonal
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
			{
				b_queen_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - b_queen_n_rows == endRow - 1) &&
					((startCol - 1) + b_queen_n_rows == endCol - 1))
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			// validating the black queen`s lower right diagonal
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
			{

				b_queen_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + b_queen_n_rows == endRow - 1) &&
					((startCol - 1) + b_queen_n_rows == endCol - 1))
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}


			}
			// vallidating the white queen`s lower left diagonal
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
			{

				b_queen_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + b_queen_n_rows == endRow - 1) &&
					((startCol - 1) - b_queen_n_rows == endCol - 1))
				{
					// validating if the move is blocked
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			// validating the white queen`s upper left diagonal
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
			{
				b_queen_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - b_queen_n_rows == endRow - 1) && 
					((startCol - 1) - b_queen_n_rows == endCol - 1))
				{
					// validating if the moveis blocked
					if (!!is_move_blocked(startRow, startCol, endRow, endCol, board))
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