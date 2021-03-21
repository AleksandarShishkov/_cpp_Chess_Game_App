#include "Rook.h"


Rook::Rook(int owner, int piece_id) :Piece(owner, piece_id)
{
	// assigning owner to owner_rook
	this->owner_rook = owner;

	// assigning piece_id to piece_id_rook
	this->piece_id_rook = piece_id;
}



bool Rook::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{
	// if it is white`s turn
	if (get_owner() == 0)
	{
		
		// if the destination square is valid
		if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 12) || 
			board[endRow - 1][endCol - 1] == 0)
		{

			// validating the white rook`s upper vertical
			if ((startRow - 1 > endRow - 1) && (endCol - 1 == startCol - 1))
			{
				// validating if the move is blocked
				if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
				{
					return true;
				}
			}
			// validating the white rook`s lower vertical
			else if ((startRow - 1 < endRow - 1) && (endCol - 1 == startCol - 1))
			{
				// validating if the move is blocked
				if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
				{
					return true;
				}
			}
			// vallidating the white rook`s right side horizontally
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 < endCol - 1))
			{
				// validating if the move is blocked
				if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
				{
					return true;
				}
				cout << board[endRow - 1][endCol - 1];
			}
			// validating the white rook`s left side horizontally
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 > endCol - 1))
			{
				// validating if the move is blocked
				if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
				{
					return true;
				}
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

			// validating the black rook`s upper vertical
			if ((startRow - 1 > endRow - 1) && (endCol - 1 == startCol - 1))
			{
				// validating if the move is blocked
				if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
				{
					return true;
				}

			}
			// validating the black rook`s lower vertical
			else if ((startRow - 1 < endRow - 1) && (endCol - 1 == startCol - 1))
			{
				// validating if the move is blocked
				if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
				{
					return true;
				}
			}
			// vallidating the black rook`s right side horizontally
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 < endCol - 1))
			{
				// validating if the move is bloacked
				if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
				{
					return true;
				}

			}
			// validating the black rook`s left side horizontally
			else if ((startRow - 1 == endRow - 1) && (startCol - 1 > endCol - 1))
			{
				// validating if the move is blocked
				if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
				{
					return true;
				}
			}

		}
	}

	cout << "\n\tInvalid move!\n";
	return false;
}