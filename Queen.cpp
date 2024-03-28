#include "Queen.h"


Queen::Queen(int owner, int piece_id) : Piece(owner, piece_id)
{
	this->owner_queen = owner;

	this->piece_id_queen = piece_id;
}



bool Queen::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{

	
	if (get_owner() == 0)
	{
		int w_queen_n_rows = 0;

		int w_queen_n_cols = 0;

		
		if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 12) ||
			board[endRow - 1][endCol - 1] == 0)
		{

			if ((startRow - 1 > endRow - 1) && (endCol - 1 == startCol - 1))
			{
				w_queen_n_rows = (startRow - 1) - (endRow - 1);

				if ((startRow - 1) - w_queen_n_rows == endRow - 1)
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}

				}

			}
			else if ((startRow - 1 < endRow - 1) && (endCol - 1 == startCol - 1))
			{

				w_queen_n_rows = (endRow - 1) - (startRow - 1);

				if ((startRow - 1) + w_queen_n_rows == endRow - 1)
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 == endRow - 1) && (endCol - 1 > startCol - 1))
			{

				w_queen_n_cols = (endCol - 1) - (startCol - 1);

				if ((startCol - 1) + w_queen_n_cols == endCol - 1)
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 > endCol - 1))
			{
				
				w_queen_n_cols = (startCol - 1) - (endCol - 1);

				if ((startCol - 1) - w_queen_n_cols == endCol - 1)
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
			{
				w_queen_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - w_queen_n_rows == endRow - 1) && 
					((startCol - 1) + w_queen_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}
				
			}
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
			{

				w_queen_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + w_queen_n_rows == endRow - 1) &&
					((startCol - 1) + w_queen_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}
			}
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
			{

				w_queen_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + w_queen_n_rows == endRow - 1) &&
					((startCol - 1) - w_queen_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
			{
				w_queen_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - w_queen_n_rows == endRow - 1) && ((startCol - 1) - w_queen_n_rows == endCol - 1))
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


		int b_queen_n_rows = 0;

		int b_queen_n_cols = 0;

		
		if ((board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 6) ||
			board[endRow - 1][endCol - 1] == 0)
		{

			if ((startRow - 1 > endRow - 1) && (startCol - 1 == endCol - 1))
			{
				b_queen_n_rows = (startRow - 1) - (endRow - 1);

				if ((startRow - 1) - b_queen_n_rows == endRow - 1)
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}

				}

			}
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 == endCol - 1))
			{

				b_queen_n_rows = (endRow - 1) - (startRow - 1);

				if ((startRow - 1) + b_queen_n_rows == endRow - 1)
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 < endCol - 1))
			{

				b_queen_n_cols = (endCol - 1) - (startCol - 1);

				if ((startCol - 1) + b_queen_n_cols == endCol - 1)
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 > endCol - 1))
			{

				b_queen_n_cols = (startCol - 1) - (endCol - 1);

				if ((startCol - 1) - b_queen_n_cols == endCol - 1)
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
			{
				b_queen_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - b_queen_n_rows == endRow - 1) &&
					((startCol - 1) + b_queen_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
			{

				b_queen_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + b_queen_n_rows == endRow - 1) &&
					((startCol - 1) + b_queen_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}


			}
			else if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
			{

				b_queen_n_rows = (endRow - 1) - (startRow - 1);

				if (((startRow - 1) + b_queen_n_rows == endRow - 1) &&
					((startCol - 1) - b_queen_n_rows == endCol - 1))
				{
					if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
					{
						return true;
					}
				}

			}
			else if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
			{
				b_queen_n_rows = (startRow - 1) - (endRow - 1);

				if (((startRow - 1) - b_queen_n_rows == endRow - 1) && 
					((startCol - 1) - b_queen_n_rows == endCol - 1))
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
