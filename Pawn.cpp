#include "Pawn.h"



Pawn::Pawn(int owner, int piece_id) :Piece(owner, piece_id)
{
	// assigning owner to owner_pawn
	this->owner_pawn = owner;

	// assigning piece_id to piece_id_pawn
	this->piece_id_pawn = piece_id;
}


bool Pawn::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{

	// if it is white`s turn
	if (get_owner() == 0)
	{
	
		// validating the white pawn`s 1st move with 2 squares
		if ((startRow - 1 == 6 && endRow - 1 == startRow - 3) && (endCol - 1 == startCol - 1))
		{
			// validating if the move is blocked
			if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
			{
				return true;
			}
		}
		// validating the white pawn`s move with 1 square
		else if ((startRow - 1 <= 6 && endRow - 1 == startRow - 2) && (endCol - 1 == startCol - 1))
		{
			// validating if the move is blocked
			if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
			{
				return true;
			}
		}
		// vallidating the white pawn`s attack on the right
		else if ((startRow - 1 <= 6 && endRow - 1 == startRow - 2) && (endCol - 1 == startCol))
		{
			// if an enemy piece is attacked
			if (board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 12)
			{
				return true;
			}
			// if en passant move is made
			else if (en_passant(startRow, startCol, endRow, endCol, board))
			{
				return true;
			}
		}
		// validating the white pawn`s attack on the left
		else if ((startRow - 1 <= 6 && endRow - 1 == startRow - 2) && (endCol - 1 == startCol - 2))
		{
			// if an enemy pice is attacked
			if (board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 12)
			{
				return true;
			}
			// if en passant move is made
			else if (en_passant(startRow, startCol, endRow, endCol, board))
			{
				return true;
			}
		}

	}
	// if it is black`s turn
	else if (get_owner() == 1)
	{

				
		// validating the black pawn`s 1st move with 2 squares
		if ((startRow - 1 == 1 && endRow - 1 == startRow + 1) && (endCol - 1 == startCol - 1))
		{
			// validating if the move is blocked
			if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
			{
				return true;
			}
		}
		// validating the black pawn`s move with 1 square
		else if ((startRow - 1 >= 1 && endRow - 1 == startRow) && (endCol - 1 == startCol - 1))
		{
			// validating if the move is blocked
			if (!is_move_blocked(startRow, startCol, endRow, endCol, board))
			{
				return true;
			}
		}
		// vallidating the black pawn`s attack on the right
		else if ((startRow - 1 >= 1 && endRow - 1 == startRow) && (endCol - 1 == startCol))
		{
			// if an enemy piece is attacked
			if (board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 6)
			{
				return true;
			}
			// if en passant move is made
			else if (en_passant(startRow, startCol, endRow, endCol, board))
			{
				return true;
			}
		}
		// validating the black pawn`s attack on the left
		else if ((startRow - 1 >= 1 && endRow - 1 == startRow) && (endCol - 1 == startCol - 2))
		{
			// if an enemy piece is attacked
			if (board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 6)
			{
				return true;
			}
			// if en passant move is made
			else if (en_passant(startRow, startCol, endRow, endCol, board))
			{
				return true;
			}
		}
	}

	cout << "\n\tInvalid move!\n";
	return false;
}




bool Pawn::en_passant(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{

	// if it is white`s turn
	if (get_owner() == 0)
	{

		// validating the rows
		if (startRow - 1 == 3 && (startCol - 1 >= 0 && startCol - 1 < 8)
			&& endRow - 1 == 2 && (endCol - 1 == startCol || endCol - 1 == startCol - 2))
		{
			if (board[endRow - 1][endCol - 1] == 0)
			{
				// validating en passant on the right
				if (startCol - 1 != 7 && board[startRow - 1][startCol] == 7 && endCol - 1 == startCol)
				{
					board[startRow - 1][startCol] = 0;	
					is_en_passant = true;
					return true;
				}
				// validating en passant on the left
				else if (startCol - 1 != 0 && board[startRow - 1][startCol - 2] == 7 && endCol - 1 == startCol - 2)
				{
					board[startRow - 1][startCol - 2] = 0;
					is_en_passant = true;
					return true;
				}
			}
		}

	}
	// if it is black`s turn
	else if (get_owner() == 1)
	{

		// validating the rows
		if (startRow - 1 == 4 && (startCol - 1 >= 0 && startCol - 1 < 8)
			&& endRow - 1 == 5 && (endCol - 1 == startCol || endCol - 1 == startCol - 2))
		{
			if (board[endRow - 1][endCol - 1] == 0)
			{
				// validating en passant on the right
				if (startCol - 1 != 7 && board[startRow - 1][startCol] == 1)
				{
					board[startRow - 1][startCol] = 0;
					is_en_passant = true;
					return true;
				}
				// validating en passant on the left
				else if (startCol - 1 != 0 && board[startRow - 1][startCol - 2] == 1)
				{
					board[startRow - 1][startCol - 2] = 0;
					is_en_passant = true;
					return true;
				}
			}
		}

	}

	is_en_passant = false;
	return false;
}


bool Pawn::is_pawn_en_passant()
{
	// validating if en passant move is made
	if (is_en_passant)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool Pawn::pawn_promotion(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{

	// integers to count the white promotable figures set to 0
	int white_rook = 0, white_knight = 0, white_bishop = 0, white_queen = 0;

	// integers to count the black promotable figures set to 0
	int black_rook = 0, black_knight = 0, black_bishop = 0, black_queen = 0;

	// integer to hold the choice set to 0
	char choice_promotion = 0;

	// boolean for the promotion loop
	bool promoted;

	// if it is white`s turn
	if (get_owner() == 0)
	{

		// if the white pawn is on the 8th row
		if ((startRow - 1 == 1 && (startCol - 1 >= 0 && startCol - 1 <= 8)) && (endRow - 1 == 0 && (endCol - 1 >= 0 && endCol - 1 < 8)))
		{

			// re-setting the white piece counters
			white_rook = 0;
			white_knight = 0;
			white_bishop = 0;
			white_queen = 0;

			// loacating the current available pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					if (board[i][j] == 2)
					{
						// adding 1 to white_rook
						white_rook++;
					}
					else if (board[i][j] == 3)
					{
						// adding 1 to white_knight
						white_knight++;
					}
					else if (board[i][j] == 4)
					{
						// adding 1 to white_bishop
						white_bishop++;
					}
					else if (board[i][j] == 5)
					{
						// adding 1 to white_queen
						white_queen++;
					}
				}
			}


			// printing the available pieces to promote
			cout << "\n\n\tThe white has reached pawn promotion. Place one of the following figures on the board:\n\n";
			cout << "\n\tSelect between:\n";


			cout << "\n\t(R) for Rook";
			cout << "\n\t(K) for Knight";
			cout << "\n\t(B) for Bishop";
			cout << "\n\t(Q) for Queen";

			cout << "\n\t> ";
			cin >> choice_promotion;

			// validating the input
			while (toupper(choice_promotion) != 'R' && toupper(choice_promotion) != 'K' &&
				toupper(choice_promotion) != 'B' && toupper(choice_promotion) != 'Q')
			{
				cout << "\n\t'" << choice_promotion << "' cannot be a valid input. Try again> ";
				cin >> choice_promotion;
			}

			// setting prompted to false
			promoted = false;

			while (!promoted)
			{
				// if the promoted piece is white rook
				if (toupper(choice_promotion) == 'R')
				{
					cout << "\n\tYou`ve promoted a Rook!\n";
					cout << "\tNow you have " << white_rook + 1 << " Rook/s on the board.\n";
					board[endRow - 1][endCol - 1] = 2;
					promoted = true;
					return true;
				}

				// if the promoted piece is a white knight
				if (toupper(choice_promotion) == 'K')
				{

					cout << "\n\tYou`ve promoted a Knight!\n";
					cout << "\tNow you have " << white_knight + 1 << " Knight/s on the board.\n";
					board[endRow - 1][endCol - 1] = 3;
					promoted = true;
					return true;
				}

				// if the promoted piece is a white bishop
				if (toupper(choice_promotion) == 'B')
				{

					cout << "\n\tYou`ve promoted a Bishop!\n";
					cout << "\tNow you have " << white_bishop + 1 << " Bishop/s on the board.\n";
					board[endRow - 1][endCol - 1] = 4;
					promoted = true;
					return true;
				}

				// if the promoted piece is a white queen
				if (toupper(choice_promotion) == 'Q')
				{

					cout << "\n\tYou`ve promoted a Queen!\n";
					cout << "\tNow you have " << white_queen + 1 << " Queen/s on the board.\n";
					board[endRow - 1][endCol - 1] = 5;
					promoted = true;
					return true;
				}
			}

		}
	}
	// if it is black`s turn
	else if (get_owner() == 1)
	{
		
		// if the black pawn is on the 1st row
		if ((startRow - 1 == 6 && (startCol - 1 >= 0 && startCol - 1 < 8)) && (endRow - 1 == 7 && (endCol - 1 >= 0 && endCol - 1 < 8)))
		{

			// re-setting the black piece counters
			black_rook = 0;
			black_knight = 0;
			black_bishop = 0;
			black_queen = 0;


			// loacating the current available pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{
					if (board[i][j] == 8)
					{
						// adding 1 to black_rook
						black_rook++;
					}
					else if (board[i][j] == 9)
					{
						// adding 1 to black_knight
						black_knight++;
					}
					else if (board[i][j] == 10)
					{
						// adding 1 to black_bishop
						black_bishop++;
					}
					else if (board[i][j] == 11)
					{
						// adding 1 to black_queen
						black_queen++;
					}
				}
			}

			// printing the available pieces to promote
			cout << "\n\n\tThe black has reached pawn promotion. Place one of the following figures on the board:\n\n";
			cout << "\n\tSelect between:\n";


			cout << "\n\t(r) for rook";
			cout << "\n\t(k) for knight";
			cout << "\n\t(b) for bishop";
			cout << "\n\t(q) for queen";

			cout << "\n\t> ";
			cin >> choice_promotion;

			// validating the input
			while (tolower(choice_promotion) != 'r' && tolower(choice_promotion) != 'k' && 
				tolower(choice_promotion) != 'b' && tolower(choice_promotion) != 'q')
			{
				cout << "\n\t'" << choice_promotion << "' cannot be a valid input. Try again> ";
				cin >> choice_promotion;
			}

			promoted = false;

			while (!promoted)
			{
				// if black rook is promoted
				if (tolower(choice_promotion) == 'r')
				{

					cout << "\n\tYou`ve promoted a rook!\n";
					cout << "\tNow you have " << black_rook + 1 << " rook/s on the board.\n";
					board[endRow - 1][endCol - 1] = 8;
					promoted = true;
					return true;

				}

				// if black knight is promoted
				if (tolower(choice_promotion) == 'k')
				{

					cout << "\n\tYou`ve promoted a knight!\n";
					cout << "\tNow you have " << black_knight + 1 << " knight/s on the board.\n";
					board[endRow - 1][endCol - 1] = 9;
					promoted = true;
					return true;

				}

				// if black bishop is promoted
				if (tolower(choice_promotion) == 'b')
				{

					cout << "\n\tYou`ve promoted a bishop!\n";
					cout << "\tNow you have " << black_bishop + 1 << " bishop/s on the board.\n";
					board[endRow - 1][endCol - 1] = 10;
					promoted = true;
					return true;

				}

				// if black queen is promoted
				if (tolower(choice_promotion) == 'q')
				{

					cout << "\n\tYou`ve promoted a queen!\n";
					cout << "\tNow you have " << black_queen + 1 << " queen/s on the board.\n";
					board[endRow - 1][endCol - 1] = 11;
					promoted = true;
					return true;

				}

			}

		}
	}

	return false;
}

