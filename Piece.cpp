#include "Piece.h"


Piece::Piece()
{

}


Piece::Piece(int owner, int piece_id) :owner(owner), piece_id(piece_id)
{

}


int Piece::get_owner()
{
	return this->owner;
}

int Piece::get_piece_id()
{
	return this->piece_id;
}

bool Piece::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{

	if (get_owner() == 0)
	{


		if ((startRow - 1 >= 0 && startRow - 1 < 8) && (startCol - 1 >= 0 && startCol - 1 < 8) &&
			(endRow - 1 >= 0 && endRow - 1 < 8) && (endCol - 1 >= 0 && endCol - 1 < 8) &&
			(startRow != endRow) || (startCol != endCol))
		{
			if ((board[startRow - 1][startCol - 1] != 0) && (board[startRow - 1][startCol - 1] >= 1 && board[startRow - 1][startCol - 1] <= 6) &&
				(board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 12) || board[endRow - 1][endCol - 1] == 0)
				return true;
		}

	}
	else if (get_owner() == 1)
	{

		if ((startRow - 1 >= 0 && startRow - 1 < 8) && (startCol - 1 >= 0 && startCol - 1 < 8) &&
			(endRow - 1 >= 0 && endRow - 1 < 8) && (endCol - 1 >= 0 && endCol - 1 < 8) &&
			(startRow != endRow) || (startCol != endCol))
		{
			if ((board[startRow - 1][startCol - 1] != 0) && (board[startRow - 1][startCol - 1] >= 7 && board[startRow - 1][startCol - 1] <= 12) &&
				(board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 6))
				return true;
		}
		
	}

	return false;


}

bool Piece::is_move_blocked(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{

	if (get_piece_id() == 1)
	{
		if ((startRow - 1 == 6 && endRow - 1 == startRow - 3) && (startCol - 1 == endCol - 1))
		{

			for (int i = 1; i < 3; ++i)
			{
				if (board[startRow - 1 - i][startCol - 1] != 0)
				{
					cout << "\n\tThe move`s blocked!\n";
					return true;
				}
			}

		}


		if ((startRow - 1 <= 6 && endRow - 1 == startRow - 2) && (endCol - 1 == startCol - 1))
		{
			if (board[endRow - 1][endCol - 1] != 0)
			{
				cout << "\n\tThe move`s blocked!\n";
				return true;
			}
		}

	}
	else if (get_piece_id() == 2)
	{


		int w_rook_cols = 0;

		if ((startRow - 1 > endRow - 1) && (startCol - 1 == endCol - 1))
		{

			w_rook_rows = (startRow - 1) - (endRow - 1);

			if (w_rook_rows != 1)
			{

				for (int i = 1; i < w_rook_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1] != 0)
					{

						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 < endRow - 1) && (startCol - 1 == endCol - 1))
		{

			w_rook_rows = (endRow - 1) - (startRow - 1);

			if (w_rook_rows != 1)
			{

				for (int i = 1; i < w_rook_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 == endRow - 1) && (startCol - 1 < endCol - 1))
		{

			w_rook_cols = (endCol - 1) - (startCol - 1);

			if (w_rook_cols != 1)
			{

				for (int i = 1; i < w_rook_cols; ++i)
				{
					if (board[startRow - 1][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 == endRow - 1) && (startCol - 1 > endCol - 1))
		{

			w_rook_cols = (startCol - 1) - (endCol - 1);


			if (w_rook_cols != 1)
			{

				for (int i = 1; i < w_rook_cols; ++i)
				{
					if (board[startRow - 1][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}
	}
	else if (get_piece_id() == 4)
	{


		int w_bishop_rows = 0;



		if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
		{
			w_bishop_rows = (startRow - 1) - (endRow - 1);

			if (w_bishop_rows != 1)
			{
				for (int i = 1; i < w_bishop_rows; ++i)
				{

					if (board[startRow - 1 - i][startCol - 1 + i] != 0)
					{

						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
		{

			w_bishop_rows = (endRow - 1) - (startRow - 1);

			if (w_bishop_rows != 1)
			{
				for (int i = 1; i < w_bishop_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
		{

			w_bishop_rows = (endRow - 1) - (startRow - 1);

			if (w_bishop_rows != 1)
			{

				for (int i = 1; i < w_bishop_rows; ++i)
				{

					if (board[startRow - 1 + i][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}




		if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
		{

			w_bishop_rows = (startRow - 1) - (endRow - 1);

			if (w_bishop_rows != 1)
			{

				for (int i = 1; i < w_bishop_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}

				}
			}
		}
	}
	else if (get_piece_id() == 5)
	{

		int w_queen_rows = 0;

		int w_queen_cols = 0;




		if ((startRow - 1 > endRow - 1) && (endCol - 1 == startCol - 1))
		{

			w_queen_rows = (startRow - 1) - (endRow - 1);

			if (w_queen_rows != 1)
			{
				for (int i = 1; i < w_queen_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 < endRow - 1) && (endCol - 1 == startCol - 1))
		{

			w_queen_rows = (endRow - 1) - (startRow - 1);

			if (w_queen_rows != 1)
			{
				for (int i = 1; i < w_queen_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 == endRow - 1) && (startCol - 1 < endCol - 1))
		{

			w_queen_cols = (endCol - 1) - (startCol - 1);

			if (w_queen_cols != 1)
			{
				for (int i = 1; i < w_queen_cols; ++i)
				{
					if (board[startRow - 1][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 == endRow - 1) && (endCol - 1 < startCol - 1))
		{

			w_queen_cols = (startCol - 1) - (endCol - 1);

			if (w_queen_cols != 1)
			{
				for (int i = 1; i < w_queen_cols; ++i)
				{
					if (board[startRow - 1][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
		{
			
			w_queen_rows = (startRow - 1) - (endRow - 1);

			if (w_queen_rows != 1)
			{
				for (int i = 1; i < w_queen_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}




		if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
		{

			w_queen_rows = (endRow - 1) - (startRow - 1);

			if (w_queen_rows != 1)
			{
				for (int i = 1; i < w_queen_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}




		if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
		{

			w_queen_rows = (endRow - 1) - (startRow - 1);

			if (w_queen_rows != 1)
			{
				for (int i = 1; i < w_queen_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}




		if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
		{

			w_queen_rows = (startRow - 1) - (endRow - 1);

			if (w_queen_rows != 1)
			{
				for (int i = 1; i < w_queen_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}


	}
	else if (get_piece_id() == 7)
	{

		if ((startRow - 1 == 1 && endRow - 1 == startRow + 1) && (endCol - 1 == startCol - 1))
		{

			for (int i = 1; i < 3; ++i)
			{
				if (board[startRow - 1 + i][startCol - 1] != 0)
				{
					cout << "\n\tThe move`s blocked!\n";
					return true;
				}
			}

		}


		if ((startRow - 1 >= 1 && endRow - 1 == startRow) && (endCol - 1 == startCol - 1))
		{
			if (board[endRow - 1][endCol - 1] != 0)
			{
				cout << "\n\tThe move`s blocked!\n";
				return true;
			}
			
		}

	}

	else if (get_piece_id() == 8)
	{
		int b_rook_rows = 0;


		if ((startRow - 1 > endRow - 1) && (startCol - 1 == endCol - 1))
		{

			b_rook_rows = (startRow - 1) - (endRow - 1);

			if (b_rook_rows != 1)
			{
				for (int i = 1; i < b_rook_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1] != 0)
					{

						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 < endRow - 1) && (startCol - 1 == endCol - 1))
		{

			b_rook_rows = (endRow - 1) - (startRow - 1);

			if (b_rook_rows != 1)
			{

				for (int i = 1; i < b_rook_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 == endRow - 1) && (startCol - 1 < endCol - 1))
		{

			b_rook_cols = (endCol - 1) - (startCol - 1);

			if (b_rook_cols != 1)
			{
				for (int i = 1; i < b_rook_cols; ++i)
				{
					if (board[startRow - 1][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 == endRow - 1) && (startCol - 1 > endCol - 1))
		{

			b_rook_cols = (startCol - 1) - (endCol - 1);

			if (b_rook_cols != 1)
			{

				for (int i = 1; i < b_rook_cols; ++i)
				{
					if (board[startRow - 1][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}


	}
	else if (get_piece_id() == 10)
	{
		int b_bishop_rows = 0;


		if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
		{

			b_bishop_rows = (startRow - 1) - (startCol - 1);


			if (b_bishop_rows != 1)
			{
				for (int i = 1; i < b_bishop_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
		{

			b_bishop_rows = (endRow - 1) - (startRow - 1);

			if (b_bishop_rows != 1)
			{

				for (int i = 1; i < b_bishop_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
		{

			b_bishop_rows = (endRow - 1) - (startRow - 1);

			if (b_bishop_rows != 1)
			{

				for (int i = 1; i < b_bishop_rows; ++i)
				{

					if (board[startRow - 1 + i][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
		{

			b_bishop_rows = (startRow - 1) - (endRow - 1);

			if (b_bishop_rows != 1)
			{

				for (int i = 1; i < b_bishop_rows; ++i)
				{

					if (board[startRow - 1 - i][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!\n";
						return true;
					}
				}
			}
		}


	}
	else if (get_piece_id() == 11)
	{


		int b_queen_rows = 0;

		int b_queen_cols = 0;



		if ((startRow - 1 > endRow - 1) && (startCol - 1 == endCol - 1))
		{

			b_queen_rows = (startRow - 1) - (endRow - 1);

			if (b_queen_rows != 1)
			{
				for (int i = 1; i < b_queen_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1] != 0)
					{
						cout << "\n\tThe move`s blocked!";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 < endRow - 1) && (startCol - 1 == endCol - 1))
		{

			b_queen_rows = (endRow - 1) - (startRow - 1);

			if (b_queen_rows != 1)
			{
				for (int i = 1; i < b_queen_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1] != 0)
					{
						cout << "\n\tThe move`s blocked!";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 == endRow - 1) && (startCol - 1 < endCol - 1))
		{

			b_queen_cols = (endCol - 1) - (startCol - 1);

			if (b_queen_cols != 1)
			{
				for (int i = 1; i < b_queen_cols; ++i)
				{
					if (board[startRow - 1][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 == endRow - 1) && (startCol - 1 > endCol - 1))
		{

			b_queen_cols = (startCol - 1) - (endCol - 1);

			if (b_queen_cols != 1)
			{
				for (int i = 1; i < b_queen_cols; ++i)
				{
					if (board[startRow - 1][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!";
						return true;
					}
				}
			}
		}


		if ((startRow - 1 > endRow - 1) && (startCol - 1 < endCol - 1))
		{

			b_queen_rows = (startRow - 1) - (endRow - 1);

			if (b_queen_rows != 1)
			{
				for (int i = 1; i < b_queen_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 < endRow - 1) && (startCol - 1 < endCol - 1))
		{

			b_queen_rows = (endRow - 1) - (startRow - 1);

			if (b_queen_rows != 1)
			{
				for (int i = 1; i < b_queen_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1 + i] != 0)
					{
						cout << "\n\tThe move`s blocked!";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 < endRow - 1) && (startCol - 1 > endCol - 1))
		{

			b_queen_rows = (endRow - 1) - (startRow - 1);

			if (b_queen_rows != 1)
			{
				for (int i = 1; i < b_queen_rows; ++i)
				{
					if (board[startRow - 1 + i][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!";
						return true;
					}
				}
			}
		}



		if ((startRow - 1 > endRow - 1) && (startCol - 1 > endCol - 1))
		{

			b_queen_rows = (startRow - 1) - (endRow - 1);

			if (b_queen_rows != 1)
			{
				for (int i = 1; i < b_queen_rows; ++i)
				{
					if (board[startRow - 1 - i][startCol - 1 - i] != 0)
					{
						cout << "\n\tThe move`s blocked!";
						return true;
					}
				}
			}
		}
	}
	
	
		
	return false;

}



bool Piece::are_right_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8])
{
	return false;
}

bool Piece::are_left_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8])
{
	return false;
}




