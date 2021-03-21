#include "King.h"


King::King(int owner, int piece_id) : Piece(owner, piece_id)
{
	// assigning owner to owner_king
	this->owner_king = owner;

	// assigning piece_id to piece_id_king
	this->piece_id_king = piece_id;
}



bool King::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{
	// if it is white`s turn
	if (get_owner() == 0)
	{


		// validating the white king`s upper vertical
		if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol - 1))
		{
			// if the destination square is valid
			if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 11) ||
				board[endRow - 1][endCol - 1] == 0)
			{
				if ((board[endRow - 2][endCol - 1] != 12) && board[endRow - 2][endCol] != 12 &&
					board[endRow - 2][endCol - 2] != 12)
				{
					return true;
				}
			}
		}
		// validating the white king`s lower vertical
		else if ((endRow - 1 == startRow) && (endCol - 1 == startCol - 1))
		{
			// if the destination square is valid
			if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 11) ||
				board[endRow - 1][endCol - 1] == 0)
			{
				if ((board[endRow][endCol - 1] != 12) && board[endRow][endCol] != 12 &&
					board[endRow][endCol - 2] != 12)
				{
					return true;
				}
			}
		}
		// vallidating the white king`s right side horizontally
		else if ((endRow - 1 == startRow - 1) && (endCol - 1 == startCol))
		{
			// if the destination square is valid
			if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 11) ||
				board[endRow - 1][endCol - 1] == 0)
			{
				if ((board[endRow - 1][endCol] != 12) && board[endRow - 2][endCol] != 12 &&
					board[endRow][endCol] != 12)
				{
					return true;
				}
			}
		}
		// validating the white king`s left side horizontally
		else if ((endRow - 1 == startRow - 1) && (endCol - 1 == startCol - 2))
		{
			// if the destination square is valid
			if ((board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 11) ||
				board[endRow - 1][endCol - 1] == 0)
			{
				if ((board[endRow - 1][endCol - 2] != 12) && board[endRow - 2][endCol - 2] != 12 &&
					board[endRow][endCol - 2] != 12)
				{
					return true;
				}
			}
		}
		// vallidating the white king`s attack on the upper right
		else if ((endRow - 1 == startRow - 2 && endCol - 1 == startCol) &&
			(board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 11))
		{
			if ((board[endRow - 1][endCol] != 12) && board[endRow - 2][endCol] != 12 &&
				board[endRow][endCol] != 12 && board[endRow - 2][endCol - 2] != 12 &&
				board[endRow - 2][endCol - 1] != 12)
			{
				return true;
			}
		}
		// vallidating the white king`s attack on the lower right
		else if ((endRow - 1 == startRow && endCol - 1 == startCol) &&
			(board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 11))
		{
			if ((board[endRow - 1][endCol] != 12) && board[endRow - 2][endCol] != 12 &&
				board[endRow][endCol] != 12 && board[endRow][endCol - 1] != 12 &&
				board[endRow][endCol - 2] != 12)
			{
				return true;
			}
		}
		// vallidating the white king`s attack on the upper left
		else if ((endRow - 1 == startRow - 2 && endCol - 1 == startCol - 2) &&
			(board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 11))
		{
			if ((board[endRow - 1][endCol - 2] != 12) && board[endRow - 2][endCol - 2] != 12 &&
				board[endRow][endCol - 2] != 12 && board[endRow - 2][endCol - 1] != 12 &&
				board[endRow - 2][endCol] != 12)
			{
				return true;
			}
		}
		// vallidating the white king`s attack on the lower left
		else if ((endRow - 1 == startRow && endCol - 1 == startCol - 2) &&
			(board[endRow - 1][endCol - 1] >= 7 && board[endRow - 1][endCol - 1] <= 11))
		{
			if ((board[endRow - 1][endCol - 2] != 12) && board[endRow - 2][endCol - 2] != 12 &&
				board[endRow][endCol - 2] != 12 && board[endRow][endCol - 1] != 12 &&
				board[endRow][endCol] != 12)
			{
				return true;
			}
		}
		// validating if the king castles
		else if (castling(startRow, startCol, endRow, endCol, board))
		{

			return true;

		}

				

	}
	// if it is black`s turn
	else if (get_owner() == 1)
	{

	
		// validating the black king`s upper vertical
		if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol - 1))
		{
			// if the destination square is valid
			if ((board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 5) ||
				board[endRow - 1][endCol - 1] == 0)
			{
				if ((board[endRow - 2][endCol - 1] != 6) && board[endRow - 2][endCol] != 6 &&
					board[endRow - 2][endCol - 2] != 6)
				{
					return true;
				}
			}
		}
		// validating the black king`s lower vertical
		else if ((endRow - 1 == startRow) && (endCol - 1 == startCol - 1))
		{
			// if the destination square is valid
			if ((board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 5) ||
				board[endRow - 1][endCol - 1] == 0)
			{
				if ((board[endRow][endCol - 1] != 6) && board[endRow][endCol] != 6 &&
					board[endRow][endCol - 2] != 6)
				{
					return true;
				}
			}
		}
		// vallidating the black king`s right side horizontally
		else if ((endRow - 1 == startRow - 1) && (endCol - 1 == startCol))
		{
			// if the destination square is valid
			if ((board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 5) ||
				board[endRow - 1][endCol - 1] == 0)
			{
				if ((board[endRow - 1][endCol] != 6) && board[endRow - 2][endCol] != 6 &&
					board[endRow][endCol] != 6)
				{
					return true;
				}
			}
		}
		// validating the black king`s left side horizontally
		else if ((endRow - 1 == startRow - 1) && (endCol - 1 == startCol - 2))
		{
			// if the destination square is valid
			if ((board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 5) ||
				board[endRow - 1][endCol - 1] == 0)
			{
				if ((board[endRow - 1][endCol - 2] != 6) && board[endRow - 2][endCol - 2] != 6 &&
					board[endRow][endCol - 2] != 6)
				{
					return true;
				}
			}
		}
		// vallidating the black king`s attack on the upper right
		else if ((endRow - 1 == startRow - 2 && endCol - 1 == startCol) &&
			(board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 5))
		{
			if ((board[endRow - 1][endCol] != 6) && board[endRow - 2][endCol] != 6 &&
				board[endRow][endCol] != 6 && board[endRow - 2][endCol - 2] != 6 &&
				board[endRow - 2][endCol - 1] != 6)
			{
				return true;
			}
		}
		// vallidating the black king`s attack on the lower right
		else if ((endRow - 1 == startRow && endCol - 1 == startCol) &&
			(board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 5))
		{
			if ((board[endRow - 1][endCol] != 6) && board[endRow - 2][endCol] != 6 &&
				board[endRow][endCol] != 6 && board[endRow][endCol - 1] != 6 &&
				board[endRow][endCol - 2] != 6)
			{
				return true;
			}
		}
		// vallidating the black king`s attack on the upper left
		else if ((endRow - 1 == startRow - 2 && endCol - 1 == startCol - 2) &&
			(board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 5))
		{
			if ((board[endRow - 1][endCol - 2] != 6) && board[endRow - 2][endCol - 2] != 6 &&
				board[endRow][endCol - 2] != 6 && board[endRow - 2][endCol - 1] != 6 &&
				board[endRow - 2][endCol] != 6)
			{
				return true;
			}
		}
		// vallidating the black king`s attack on the lower left
		else if ((endRow - 1 == startRow && endCol - 1 == startCol - 2) &&
			(board[endRow - 1][endCol - 1] >= 1 && board[endRow - 1][endCol - 1] <= 5))
		{
			if ((board[endRow - 1][endCol - 2] != 6) && board[endRow - 2][endCol - 2] != 6 &&
				board[endRow][endCol - 2] != 6 && board[endRow][endCol - 1] != 6 &&
				board[endRow][endCol] != 6)
			{
				return true;
			}
		}
		// validating if the black king castles
		else if (castling(startRow, startCol, endRow, endCol, board))
		{
			return true;

		}

		
	}


	cout << "\n\tInvalid move!\n";
	return false;
}





bool King::castling(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{

	// if it is white`s turn
	if (get_owner() == 0)
	{

		// validating castling on the right
		if (endRow - 1 == 7 && endCol - 1 == 6)
		{
			// if the right castling squares valid
			if (are_right_castling_sqs_valid(get_owner(), startRow, startCol, board))
			{

				board[endRow - 1][endCol - 1] = 6;
				board[endRow - 1][endCol] = 0;
				board[endRow - 1][endCol - 2] = 2;

				return true;
			}

		}
		// validating castling on the left
		else if (endRow - 1 == 7 && endCol - 1 == 2)
		{
			// if the left castling squares are valid
			if (are_left_castling_sqs_valid(get_owner(), startRow, startCol, board))
			{

				board[endRow - 1][endCol - 1] = 6;
				board[endRow - 1][endCol - 3] = 0;
				board[endRow - 1][endCol] = 2;

				return true;
			}

		}


	}
	// if it is black`s turn
	else if (get_owner() == 1)
	{
		// valdiatign castling on the right
		if (endRow - 1 == 0 && endCol - 1 == 6)
		{
			// if the right castling squares are valid
			if (are_right_castling_sqs_valid(1, startRow, startCol, board))
			{

				board[endRow - 1][endCol - 1] = 12;
				board[endRow - 1][endCol] = 0;
				board[endRow - 1][endCol - 2] = 8;

				return true;
			}

		}
		// validating castling on the left
		else if (endRow - 1 == 0 && endCol - 1 == 2)
		{
			// if the left caslitng squares are valid
			if (are_left_castling_sqs_valid(1, startRow, startCol, board))
			{

				board[endRow - 1][endCol - 1] = 12;
				board[endRow - 1][endCol - 3] = 0;
				board[endRow - 1][endCol] = 8;

				return true;
			}
			
		}

	}

	return false;
}




bool King::are_right_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8])
{
	// if it is white`s turn
	if (owner == 0)
	{
		// validating if the right castling squares are empty
		for (int i = 1; i < 3; ++i)
		{
			if (board[startRow - 1][startCol - 1 + i] != 0)
			{
				return false;
			}
			
		}

		// validating if the squares are in check
		if (are_right_castling_sqs_in_check(owner, startRow, startCol, board))
		{
			return false;
		}
	}
	// if it`s black`s turn
	else if (owner == 1)
	{
		// validating if the right castling squares are empty
		for (int i = 1; i < 2; ++i)
		{
			if (board[startRow - 1][startCol - 1 + i] != 0)
			{
				return false;
			}
		}

		//. validating if the squares are in check
		if (are_right_castling_sqs_in_check(owner, startRow, startCol, board))
		{
			return false;
		}

	}

	return true;
}

bool King::are_right_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8])
{

	// integer to hold the side of the castling
	int right = 1;

	// if it is white`s turn
	if (owner == 0)
	{
		// validating if the first castling square is in check
		if (is_sq1_in_check(owner, right, startRow - 1, startCol, board) || is_sq2_in_check(owner, right, startRow - 1, startCol + 1, board))
		{
			return true;
		}
	}
	// if it is black`s turn
	else if (owner == 1)
	{
		if (is_sq1_in_check(owner, right, startRow - 1, startCol, board) || is_sq2_in_check(owner, right, startRow - 1, startCol + 1, board))
		{
			return true;
		}
	}

	return false;
}


bool King::are_left_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8])
{

	// if it`s white`s turn
	if (owner == 0)
	{
		// validating if the left castling squares empty
		for (int i = 1; i < 2; ++i)
		{
			if (board[startRow - 1][startCol - 1 - i] != 0)
			{
				return false;
			}

		}

		// validating if the left castling suqares are in check
		if (are_left_castling_sqs_in_check(owner, startRow, startCol, board))
		{
			return false;
		}
	}
	// if it`s black`s turn
	else if (owner == 1)
	{
		// validating if the left castling squares empty
		for (int i = 1; i < 2; ++i)
		{
			if (board[startRow - 1][startCol - 1 - i] != 0)
			{
				return false;
			}
		}

		// valdiating if the left castling squares are in check
		if (are_left_castling_sqs_in_check(owner, startRow, startCol, board))
		{
			return false;
		}

	}

	return true;

}


bool King::are_left_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8])
{
	// integer to hold the side of the caslting
	int left = 0;

	// if it is white`s turn
	if (owner == 0)
	{
		// validating if the furst castling square in check
		if (is_sq1_in_check(owner, left, startRow - 1, startCol - 2, board) || is_sq2_in_check(owner, left, startRow - 1, startCol - 3, board))
		{
			return true;
		}
	}
	// if it is black`s turn
	else if (owner == 1)
	{
		// validating if the first castling square in check
		if (is_sq1_in_check(owner, left, startRow - 1, startCol - 2, board) || is_sq2_in_check(owner, left, startRow - 1, startCol - 3, board))
		{
			return true;
		}
	}


	return false;
}



bool King::is_sq1_in_check(int owner, int side, int sqRow, int sqCol, int board[8][8])
{
	
	// boolean for the squares
	bool is_sq_empty = false;


	// if it`s white`s turn
	if (owner == 0)
	{

		// validating the 1st square on the right
		if (side == 1)
		{

			// locating the black owner`s pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					// setting is_sq_empty to true
					is_sq_empty = true;

					// if the piece is a black pawn
					if (board[i][j] == 7)
					{
						if ((i + 1 == sqRow) && (j + 1 == sqCol))
						{
							return true;
						}
						else if ((i + 1 == sqRow) && (j - 1 == sqCol))
						{
							return true;
						}
					}
					// if the piece is a black rook
					else if (board[i][j] == 8)
					{

						// integer to hold the number of rows
						int b_rook_n_row = 0;


						// validating whether the lower squares on the column are empty
						if (i < sqRow && j == sqCol)
						{
							b_rook_n_row = sqRow - i;

							if ((i + b_rook_n_row == sqRow) && (j == sqCol))
							{

								if (b_rook_n_row == 1)
								{

									for (int k = 1; k <= b_rook_n_row; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < b_rook_n_row; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a black night
					else if (board[i][j] == 9)
					{
						

						if (i + 1 == sqRow && j + 2 == sqCol)
						{
							return true;
						}

						if (i + 2 == sqRow && j + 1 == sqCol)
						{
							return true;
						}

						if (i + 2 == sqRow && j - 1 == sqCol)
						{
							return true;
						}

						if (i + 1 == sqRow && j - 2 == sqCol)
						{
							return true;
						}

						

					}
					// if the piece is a black bishop
					else if (board[i][j] == 10)
					{

						// integer to hold the number of rows
						int b_bishop_n_rows = 0;


						// validating the lower right diagonal
						if (i < sqRow && j < sqCol)
						{
							b_bishop_n_rows = sqRow - i;


							if ((i + b_bishop_n_rows == sqRow) && (j + b_bishop_n_rows == sqCol))
							{

								if (b_bishop_n_rows == 1)
								{

									for (int k = 1; k <= b_bishop_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_bishop_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}



						// validating the lower left diagonal
						if (i < sqRow && j > sqCol)
						{
							b_bishop_n_rows = sqRow - i;

							if ((i + b_bishop_n_rows == sqRow) && (j - b_bishop_n_rows == sqCol))
							{

								if (b_bishop_n_rows == 1)
								{

									for (int k = 1; k <= b_bishop_n_rows; ++k)
									{

										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_bishop_n_rows; ++k)
									{

										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a black queen
					else if (board[i][j] == 11)
					{

						// integer to hold the number of the rows
						int b_queen_n_rows = 0;


						// validating whether the lower squares on the column are empty
						if (i < sqRow && j == sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

						
						// validating the lower right diagonal
						if (i < sqRow && j < sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j + b_queen_n_rows == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower left diagonal
						if (i < sqRow && j > sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j - b_queen_n_rows == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}

				}

			}

		}
		// validating the 1st square on the left
		else if (side == 0)
		{
			// locating the black owner`s pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					// setting is_sq_empty to true
					is_sq_empty = true;

					// if the piece is a black pawn
					if (board[i][j] == 7)
					{
						if ((i + 1 == sqRow) && (j + 1 == sqCol))
						{
							return true;
						}
						else if ((i + 1 == sqRow) && (j - 1 == sqCol))
						{
							return true;
						}
					}
					// if the piece is a black rook
					else if (board[i][j] == 8)
					{

						// integer to hold the number of rows
						int b_rook_n_row = 0;


						// validating whether the lower squares on the column are empty
						if (i < sqRow && j == sqCol)
						{
							b_rook_n_row = sqRow - i;

							if ((i + b_rook_n_row == sqRow) && (j == sqCol))
							{

								if (b_rook_n_row == 1)
								{

									for (int k = 1; k <= b_rook_n_row; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < b_rook_n_row; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a black night
					else if (board[i][j] == 9)
					{


						if (i + 1 == sqRow && j + 2 == sqCol)
						{
							return true;
						}

						if (i + 2 == sqRow && j + 1 == sqCol)
						{
							return true;
						}

						if (i + 2 == sqRow && j - 1 == sqCol)
						{
							return true;
						}

						if (i + 1 == sqRow && j - 2 == sqCol)
						{
							return true;
						}



					}
					// if the piece is a black bishop
					else if (board[i][j] == 10)
					{

						// integer to hold the number of rows
						int b_bishop_n_rows = 0;


						// validating the lower right diagonal

						if (i < sqRow && j < sqCol)
						{
							b_bishop_n_rows = sqRow - i;


							if ((i + b_bishop_n_rows == sqRow) && (j + b_bishop_n_rows == sqCol))
							{

								if (b_bishop_n_rows == 1)
								{

									for (int k = 1; k <= b_bishop_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_bishop_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower left diagonal
						if (i < sqRow && j > sqCol)
						{
							b_bishop_n_rows = sqRow - i;

							if ((i + b_bishop_n_rows == sqRow) && (j - b_bishop_n_rows == sqCol))
							{

								if (b_bishop_n_rows == 1)
								{

									for (int k = 1; k <= b_bishop_n_rows; ++k)
									{

										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_bishop_n_rows; ++k)
									{

										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a black queen
					else if (board[i][j] == 11)
					{

						// integer to hold the number of the rows
						int b_queen_n_rows = 0;



						// validating whether the lower squares on the column are empty
						if (i < sqRow && j == sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower right diagonal
						if (i < sqRow && j < sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j + b_queen_n_rows == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower left diagonal
						if (i <  sqRow && j > sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j - b_queen_n_rows == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{

									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}

								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}

				}

			}

		}

	}
	// if it`s black`s turn
	else if (owner == 1)
	{
		// validating the 1st square on the right
		if (side == 1)
		{
			// locating the white owner`s pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					// setting is_sq_empty to true
					is_sq_empty = true;

					// if the piece is a white pawn
					if (board[i][j] == 1)
					{
						if ((i - 1 == sqRow) && (j + 1 == sqCol))
						{
							return true;
						}
						else if ((i - 1 == sqRow) && (j - 1 == sqCol))
						{
							return true;
						}

					}
					// if the piece is a white rook
					else if (board[i][j] == 2)
					{


						// integer to hold the number of rows
						int w_rook_n_row = 0;


						// validating whether the upper squares on the column are empty
						if (i > sqRow && j == sqCol)
						{
							w_rook_n_row = i - sqRow;

							if (i - w_rook_n_row == sqRow && j == sqCol)
							{

								if (w_rook_n_row == 1)
								{
									for (int k = 1; k <= w_rook_n_row; ++k)
									{

										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < w_rook_n_row; ++k)
									{

										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a white knight
					else if (board[i][j] == 3)
					{
						if (i - 2 == sqRow && j + 1 == sqCol)
						{
							return true;
						}

						if (i - 2 == sqRow && j - 1 == sqCol)
						{
							return true;
						}

						if (i - 1 == sqRow && j + 2 == sqCol)
						{
							return true;
						}

						if (i - 1 == sqRow && j - 2 == sqCol)
						{
							return true;
						}


					}
					// if the piece is a white bishop
					else if (board[i][j] == 4)
					{

						// integer to hold the number of rows
						int w_bishop_n_rows = 0;


						// validating the upper right diagonal
						if (i > sqRow && j < sqCol)
						{
							w_bishop_n_rows = i - sqRow;

							if ((i - w_bishop_n_rows == sqRow) && (j + w_bishop_n_rows == sqCol))
							{

								if (w_bishop_n_rows == 1)
								{

									for (int k = 1; k <= w_bishop_n_rows; ++k)
									{

										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_bishop_n_rows; ++k)
									{

										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}


						// validating the upper left diagonal
						if (i > sqRow && j > sqCol)
						{
							w_bishop_n_rows = i - sqRow;

							if ((i - w_bishop_n_rows == sqRow) && (j - w_bishop_n_rows == sqCol))
							{

								if (w_bishop_n_rows == 1)
								{

									for (int k = 1; k <= w_bishop_n_rows; ++k)
									{

										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_bishop_n_rows; ++k)
									{

										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}
					}
					// if the piece is a white queen
					else if (board[i][j] == 5)
					{


						// integer to hold the number of the rows
						int w_queen_n_rows = 0;


						// validating whether the upper squares on the column are empty
						if (i > sqRow && j == sqCol)
						{
							w_queen_n_rows = i - sqRow;

							if ((i - w_queen_n_rows == sqRow) && (j == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}

								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}


						// validating the upper right diagonal
						if (i > sqRow && j < sqCol)
						{
							w_queen_n_rows = i - sqRow;


							if ((i - w_queen_n_rows == sqRow) && (j + w_queen_n_rows == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}



						// validating the upper left diagonal
						if (i > sqRow && j > sqCol)
						{
							w_queen_n_rows = i - sqRow;

							if ((i - w_queen_n_rows == sqRow) && (j - w_queen_n_rows == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}
					}
				}
			}

		}
		// validating the 1st square on the left
		else if (side == 0)
		{
			// locating the white owner`s pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					// setting is_sq_empty to true
					is_sq_empty = true;

					// if the piece is a white pawn
					if (board[i][j] == 1)
					{
						if ((i - 1 == sqRow) && (j + 1 == sqCol))
						{
							return true;
						}
						else if ((i - 1 == sqRow) && (j - 1 == sqCol))
						{
							return true;
						}

					}
					// if the piece is a white rook
					else if (board[i][j] == 2)
					{


						// integer to hold the number of rows
						int w_rook_n_row = 0;


						// validating whether the upper squares on the column are empty
						if (i > sqRow && j == sqCol)
						{
							w_rook_n_row = i - sqRow;

							if (i - w_rook_n_row == sqRow && j == sqCol)
							{

								if (w_rook_n_row == 1)
								{

									for (int k = 1; k <= w_rook_n_row; ++k)
									{

										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < w_rook_n_row; ++k)
									{

										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a white knight
					else if (board[i][j] == 3)
					{
						if (i - 2 == sqRow && j + 1 == sqCol)
						{
							return true;
						}

						if (i - 2 == sqRow && j - 1 == sqCol)
						{
							return true;
						}

						if (i - 1 == sqRow && j + 2 == sqCol)
						{
							return true;
						}

						if (i - 1 == sqRow && j - 2 == sqCol)
						{
							return true;
						}


					}
					// if the piece is a white bishop
					else if (board[i][j] == 4)
					{

						// integer to hold the number of rows
						int w_bishop_n_rows = 0;


						// validating the upper right diagonal
						if (i > sqRow && j < sqCol)
						{
							w_bishop_n_rows = i - sqRow;

							if ((i - w_bishop_n_rows == sqRow) && (j + w_bishop_n_rows == sqCol))
							{

								if (w_bishop_n_rows == 1)
								{

									for (int k = 1; k <= w_bishop_n_rows; ++k)
									{

										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_bishop_n_rows; ++k)
									{

										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}


								if (is_sq_empty)
								{
									return true;
								}
							}
						}


						// validating the upper left diagonal
						if (i > sqRow && j > sqCol)
						{
							w_bishop_n_rows = i - sqRow;

							if ((i - w_bishop_n_rows == sqRow) && (j - w_bishop_n_rows == sqCol))
							{

								if (w_bishop_n_rows == 1)
								{

									for (int k = 1; k <= w_bishop_n_rows; ++k)
									{

										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_bishop_n_rows; ++k)
									{

										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}
					}
					// if the piece is a white queen
					else if (board[i][j] == 5)
					{


						// integer to hold the number of the rows
						int w_queen_n_rows = 0;


						// validating whether the upper squares on the column are empty
						if (i > sqRow && j == sqCol)
						{
							w_queen_n_rows = i - sqRow;

							if ((i - w_queen_n_rows == sqRow) && (j == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}


						// validating the upper right diagonal
						if (i > sqRow && j < sqCol)
						{
							w_queen_n_rows = i - sqRow;


							if ((i - w_queen_n_rows == sqRow) && (j + w_queen_n_rows == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{

									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}


						// validating the upper left diagonal
						if (i > sqRow && j > sqCol)
						{
							w_queen_n_rows = i - sqRow;

							if ((i - w_queen_n_rows == sqRow) && (j - w_queen_n_rows == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}


	return false;
}


bool King::is_sq2_in_check(int owner, int side, int sqRow, int sqCol, int board[8][8])
{
	// boolean for the squares
	bool is_sq_empty = false;


	// if it is white`s turn
	if (owner == 0)
	{

		// validating the 2nd square on the right
		if (side == 1)
		{

			// locating the black owner`s pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					// setting is_sq_empty to true
					is_sq_empty = true;

					// if the piece is a black pawn
					if (board[i][j] == 7)
					{
						if ((i + 1 == sqRow) && (j + 1 == sqCol))
						{
							return true;
						}
						else if ((i + 1 == sqRow) && (j - 1 == sqCol))
						{
							return true;
						}
					}
					// if the piece is a black rook
					else if (board[i][j] == 8)
					{

						// integer to hold the number of rows
						int b_rook_n_row = 0;


						// validating whether the lower squares on the column are empty
						if (i < sqRow && j == sqCol)
						{

							b_rook_n_row = sqRow - i;

							if ((i + b_rook_n_row == sqRow) && (j == sqCol))
							{

								if (b_rook_n_row == 1)
								{

									for (int k = 1; k <= b_rook_n_row; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < b_rook_n_row; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a black night
					else if (board[i][j] == 9)
					{


						if (i + 1 == sqRow && j + 2 == sqCol)
						{
							return true;
						}

						if (i + 2 == sqRow && j + 1 == sqCol)
						{
							return true;
						}

						if (i + 2 == sqRow && j - 1 == sqCol)
						{
							return true;
						}

						if (i + 1 == sqRow && j - 2 == sqCol)
						{
							return true;
						}


					}
					// if the piece is a black bishop
					else if (board[i][j] == 10)
					{

						// integer to hold the number of rows
						int b_bishop_n_rows = 0;



						// validating the lower right diagonal
						if (i < sqRow && j < sqCol)
						{
							b_bishop_n_rows = sqRow - i;

							if ((i + b_bishop_n_rows == sqRow) && (j + b_bishop_n_rows == sqCol))
							{

								if (b_bishop_n_rows == 1)
								{

									for (int k = 1; k <= b_bishop_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_bishop_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower left diagonal
						if (i < sqRow && j > sqCol)
						{
							b_bishop_n_rows = sqRow - i;

							if ((i + b_bishop_n_rows == sqRow) && (j - b_bishop_n_rows == sqCol))
							{

								if (b_bishop_n_rows == 1)
								{

									for (int k = 1; k <= b_bishop_n_rows; ++k)
									{

										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_bishop_n_rows; ++k)
									{

										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a black queen
					else if (board[i][j] == 11)
					{

						// integer to hold the number of the rows
						int b_queen_n_rows = 0;


						// validating whether the lower squares on the column are empty
						if (i < sqRow && j == sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{

									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower right diagonal
						if (i < sqRow && j < sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j + b_queen_n_rows == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower left diagonal
						if (i < sqRow && j > sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j - b_queen_n_rows == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}
					}
				}
			}

		}
		// validating the 2nd square on the left
		else if (side == 0)
		{
			// locating the black owner`s pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					// setting is_sq_empty to true
					is_sq_empty = true;

					// if the piece is a black pawn
					if (board[i][j] == 7)
					{
						if ((i + 1 == sqRow) && (j + 1 == sqCol))
						{
							return true;
						}
						else if ((i + 1 == sqRow) && (j - 1 == sqCol))
						{
							return true;
						}
					}
					// if the piece is a black rook
					else if (board[i][j] == 8)
					{

						// integer to hold the number of rows
						int b_rook_n_row = 0;


						// validating whether the lower squares on the column are empty
						if (i < sqRow && j == sqCol)
						{
							b_rook_n_row = sqRow - i;

							if ((i + b_rook_n_row == sqRow) && (j == sqCol))
							{

								if (b_rook_n_row == 1)
								{

									for (int k = 1; k <= b_rook_n_row; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < b_rook_n_row; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a black night
					else if (board[i][j] == 9)
					{


						if (i + 1 == sqRow && j + 2 == sqCol)
						{
							return true;
						}

						if (i + 2 == sqRow && j + 1 == sqCol)
						{
							return true;
						}

						if (i + 2 == sqRow && j - 1 == sqCol)
						{
							return true;
						}

						if (i + 1 == sqRow && j - 2 == sqCol)
						{
							return true;
						}



					}
					// if the piece is a black bishop
					else if (board[i][j] == 10)
					{

						// integer to hold the number of rows
						int b_bishop_n_rows = 0;


						// validating the lower right diagonal
						if (i < sqRow && j < sqCol)
						{
							b_bishop_n_rows = sqRow - i;

							if ((i + b_bishop_n_rows == sqRow) && (j + b_bishop_n_rows == sqCol))
							{

								if (b_bishop_n_rows == 1)
								{

									for (int k = 1; k <= b_bishop_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_bishop_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower left diagonal
						if (i < sqRow && i > sqCol)
						{
							b_bishop_n_rows = sqRow - i;

							if ((i + b_bishop_n_rows == sqRow) && (j - b_bishop_n_rows == sqCol))
							{

								if (b_bishop_n_rows == 1)
								{

									for (int k = 1; k <= b_bishop_n_rows; ++k)
									{

										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_bishop_n_rows; ++k)
									{

										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a black queen
					else if (board[i][j] == 11)
					{

						// integer to hold the number of the rows
						int b_queen_n_rows = 0;


						// validating whether the lower squares on the column are empty
						if (i < sqRow && j == sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower right diagonal
						if (i < sqRow && j < sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j + b_queen_n_rows == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}


						// validating the lower left diagonal
						if (i < sqRow && j > sqCol)
						{
							b_queen_n_rows = sqRow - i;

							if ((i + b_queen_n_rows == sqRow) && (j - b_queen_n_rows == sqCol))
							{

								if (b_queen_n_rows == 1)
								{

									for (int k = 1; k <= b_queen_n_rows; ++k)
									{
										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < b_queen_n_rows; ++k)
									{
										if (board[i + k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}
					}
				}
			}
		}

	}
	// if it is black`s turn
	else if (owner == 1)
	{
		// validating the 2nd square on the right
		if (side == 1)
		{
			// locating the white owner`s pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					// setting is_sq_empty to true
					is_sq_empty = true;

					// if the piece is a white pawn
					if (board[i][j] == 1)
					{
						if ((i - 1 == sqRow) && (j + 1 == sqCol))
						{
							return true;
						}
						else if ((i - 1 == sqRow) && (j - 1 == sqCol))
						{
							return true;
						}

					}
					// if the piece is a white rook
					else if (board[i][j] == 2)
					{


						// integer to hold the number of rows
						int w_rook_n_row = 0;


						// validating whether the upper squares on the column are empty
						if (i > sqRow && j == sqCol)
						{
							w_rook_n_row = i - sqRow;

							if (i - w_rook_n_row == sqRow && j == sqCol)
							{

								if (w_rook_n_row == 1)
								{

									for (int k = 1; k <= w_rook_n_row; ++k)
									{

										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < w_rook_n_row; ++k)
									{

										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a white knight
					else if (board[i][j] == 3)
					{
						if (i - 2 == sqRow && j + 1 == sqCol)
						{
							return true;
						}

						if (i - 2 == sqRow && j - 1 == sqCol)
						{
							return true;
						}

						if (i - 1 == sqRow && j + 2 == sqCol)
						{
							return true;
						}

						if (i - 1 == sqRow && j - 2 == sqCol)
						{
							return true;
						}


					}
					// if the piece is a white bishop
					else if (board[i][j] == 4)
					{

						// integer to hold the number of rows
						int w_bishop_n_rows = 0;


						// validating the upper right diagonal
						if (i > sqRow && j < sqCol)
						{
							w_bishop_n_rows = i - sqRow;

							if ((i - w_bishop_n_rows == sqRow) && (j + w_bishop_n_rows == sqCol))
							{

								if (w_bishop_n_rows == 1)
								{

									for (int k = 1; k <= w_bishop_n_rows; ++k)
									{

										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_bishop_n_rows; ++k)
									{

										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}



						// validating the upper left diagonal
						if (i > sqRow && j > sqCol)
						{
							w_bishop_n_rows = i - sqRow;

							if ((i - w_bishop_n_rows == sqRow) && (j - w_bishop_n_rows == sqCol))
							{
								
								if (w_bishop_n_rows == 1)
								{

									for (int k = 1; k <= w_bishop_n_rows; ++k)
									{

										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_bishop_n_rows; ++k)
									{

										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}
					}
					// if the piece is a white queen
					else if (board[i][j] == 5)
					{


						// integer to hold the number of the rows
						int w_queen_n_rows = 0;


						// validating whether the upper squares on the column are empty
						if (i > sqRow && j == sqCol)
						{
							w_queen_n_rows = i - sqRow;

							if ((i - w_queen_n_rows == sqRow) && (j == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}


						// validating the upper right diagonal
						if (i > sqRow && j < sqCol)
						{
							w_queen_n_rows = i - sqRow;


							if ((i - w_queen_n_rows == sqRow) && (j + w_queen_n_rows == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}


						// validating the upper left diagonal
						if (i > sqRow && j > sqCol)
						{
							w_queen_n_rows = i - sqRow;

							if ((i - w_queen_n_rows == sqRow) && (j - w_queen_n_rows == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}
					}
				}
			}

		}
		// validating the 2nd square on the left
		else if (side == 0)
		{
			// locating the white owner`s pieces
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					// setting is_sq_empty to true
					is_sq_empty = true;

					// if the piece is a white pawn
					if (board[i][j] == 1)
					{
						if ((i - 1 == sqRow) && (j + 1 == sqCol))
						{
							return true;
						}
						else if ((i - 1 == sqRow) && (j - 1 == sqCol))
						{
							return true;
						}

					}
					// if the piece is a white rook
					else if (board[i][j] == 2)
					{


						// integer to hold the number of rows
						int w_rook_n_row = 0;


						// validating whether the upper squares on the column are empty
						if (i > sqRow && j == sqCol)
						{
							w_rook_n_row = i - sqRow;

							if (i - w_rook_n_row == sqRow && j == sqCol)
							{

								if (w_rook_n_row == 1)
								{

									for (int k = 1; k <= w_rook_n_row; ++k)
									{

										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < w_rook_n_row; ++k)
									{

										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}

							}
						}

					}
					// if the piece is a white knight
					else if (board[i][j] == 3)
					{
						if (i - 2 == sqRow && j + 1 == sqCol)
						{
							return true;
						}

						if (i - 2 == sqRow && j - 1 == sqCol)
						{
							return true;
						}

						if (i - 1 == sqRow && j + 2 == sqCol)
						{
							return true;
						}

						if (i - 1 == sqRow && j - 2 == sqCol)
						{
							return true;
						}


					}
					// if the piece is a white bishop
					else if (board[i][j] == 4)
					{

						// integer to hold the number of rows
						int w_bishop_n_rows = 0;



						// validating the upper right diagonal
						if (i > sqRow && j < sqCol)
						{
							w_bishop_n_rows = i - sqRow;

							if ((i - w_bishop_n_rows == sqRow) && (j + w_bishop_n_rows == sqCol))
							{

								if (w_bishop_n_rows == 1)
								{

									for (int k = 1; k <= w_bishop_n_rows; ++k)
									{

										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_bishop_n_rows; ++k)
									{

										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}



						// validating the upper left diagonal
						if (i > sqRow && j > sqCol)
						{
							w_bishop_n_rows = i - sqRow;

							if ((i - w_bishop_n_rows == sqRow) && (j - w_bishop_n_rows == sqCol))
							{

								if (w_bishop_n_rows == 1)
								{

									for (int k = 1; k <= w_bishop_n_rows; ++k)
									{

										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_bishop_n_rows; ++k)
									{

										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}
					}
					// if the piece is a white queen
					else if (board[i][j] == 5)
					{


						// integer to hold the number of the rows
						int w_queen_n_rows = 0;


						// validating whether the upper squares on the column are empty
						if (i > sqRow && j == sqCol)
						{
							w_queen_n_rows = i - sqRow;

							if ((i - w_queen_n_rows == sqRow) && (j == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j] != 0)
										{
											is_sq_empty = false;
										}
									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}


						// validating the upper right diagonal
						if (i > sqRow && j < sqCol)
						{
							w_queen_n_rows = i - sqRow;


							if ((i - w_queen_n_rows == sqRow) && (j + w_queen_n_rows == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j + k] != 0)
										{
											is_sq_empty = false;
										}

									}

								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}


						// validating the upper left diagonal
						if (i > sqRow && j > sqCol)
						{
							w_queen_n_rows = i - sqRow;

							if ((i - w_queen_n_rows == sqRow) && (j - w_queen_n_rows == sqCol))
							{

								if (w_queen_n_rows == 1)
								{

									for (int k = 1; k <= w_queen_n_rows; ++k)
									{
										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}
								else
								{
									for (int k = 1; k < w_queen_n_rows; ++k)
									{
										if (board[i - k][j - k] != 0)
										{
											is_sq_empty = false;
										}

									}
								}

								if (is_sq_empty)
								{
									return true;
								}
							}
						}
					}
				}
			}
		}
	}


	return false;
}




