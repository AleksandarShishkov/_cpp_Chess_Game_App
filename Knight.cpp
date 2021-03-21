#include "Knight.h"


Knight::Knight(int owner, int piece_id) :Piece(owner, piece_id)
{
	// assigning owner to owner_knight
	this->owner_knight = owner;

	// assigning piece_id to piece_id_knight
	this->piece_id_knight = piece_id;
}


bool Knight::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{
	// if it is white`s turn
	if (get_owner() == 0)
	{

		// if the destination square is valid
		if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 12) ||
			board[endRow - 1][endCol - 1] == 0)
		{


			// validating the white knight`s upper right side
			if ((endRow - 1 == startRow - 3) && (endCol - 1 == startCol))
			{
				return true;
			}
			else if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol + 1))
			{
				return true;
			}
			// validating the white knight`s lower right side
			else if ((endRow - 1 == startRow) && (endCol - 1 == startCol + 1))
			{
				return true;
			}
			else if ((endRow - 1 == startRow + 1) && (endCol - 1 == startCol))
			{
				return true;
			}
			// vallidating the white knight`s lower left side 
			else if ((endRow - 1 == startRow + 1) && (endCol - 1 == startCol - 2))
			{
				return true;
			}
			else if ((endRow - 1 == startRow) && (endCol - 1 == startCol - 3))
			{
				return true;
			}
			// validating the white knight`s upper left side
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
	// if it is black`s turn
	else if (get_owner() == 1)
	{

		// if the destination square is valid
		if ((board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 6) ||
			board[endRow - 1][endCol - 1] == 0)
		{


			// validating the black knight`s upper right side
			if ((endRow - 1 == startRow - 3) && (endCol - 1 == startCol))
			{
				return true;
			}
			else if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol + 1))
			{
				return true;
			}
			// validating the black knight`s lower right side
			else if ((endRow - 1 == startRow) && (endCol - 1 == startCol + 1))
			{
				return true;
			}
			else if ((endRow - 1 == startRow + 1) && (endCol - 1 == startCol))
			{
				return true;
			}
			// vallidating the black knight`s lower left side 
			else if ((endRow - 1 == startRow + 1) && (endCol - 1 == startCol - 2))
			{
				return true;
			}
			else if ((endRow - 1 == startRow) && (endCol - 1 == startCol - 3))
			{
				return true;
			}
			// validating the black knight`s upper left side
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