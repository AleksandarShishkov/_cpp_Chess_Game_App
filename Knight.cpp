#include "Knight.h"


Knight::Knight(int owner, int piece_id) :Piece(owner, piece_id)
{
	this->owner_knight = owner;

	this->piece_id_knight = piece_id;
}


bool Knight::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{
	if (get_owner() == 0)
	{

		if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 12) ||
			board[endRow - 1][endCol - 1] == 0)
		{


			if ((endRow - 1 == startRow - 3) && (endCol - 1 == startCol))
			{
				return true;
			}
			else if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol + 1))
			{
				return true;
			}
			else if ((endRow - 1 == startRow) && (endCol - 1 == startCol + 1))
			{
				return true;
			}
			else if ((endRow - 1 == startRow + 1) && (endCol - 1 == startCol))
			{
				return true;
			}
			else if ((endRow - 1 == startRow + 1) && (endCol - 1 == startCol - 2))
			{
				return true;
			}
			else if ((endRow - 1 == startRow) && (endCol - 1 == startCol - 3))
			{
				return true;
			}
			else if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol - 3))
			{
				return true;
			}
			else if ((endRow - 1 == startRow - 3) && (endCol - 1 == startCol - 2))
			{
				return true;
			}

		}

	}
	else if (get_owner() == 1)
	{

		if ((board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 6) ||
			board[endRow - 1][endCol - 1] == 0)
		{


			if ((endRow - 1 == startRow - 3) && (endCol - 1 == startCol))
			{
				return true;
			}
			else if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol + 1))
			{
				return true;
			}
			{
				return true;
			}
			else if ((endRow - 1 == startRow + 1) && (endCol - 1 == startCol))
			{
				return true;
			}
			else if ((endRow - 1 == startRow + 1) && (endCol - 1 == startCol - 2))
			{
				return true;
			}
			else if ((endRow - 1 == startRow) && (endCol - 1 == startCol - 3))
			{
				return true;
			}
			else if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol - 3))
			{
				return true;
			}
			else if ((endRow - 1 == startRow - 3) && (endCol - 1 == startCol - 2))
			{
				return true;
			}

		}
		

	}

	cout << "\n\tInvalid move!\n";
	return false;
}
