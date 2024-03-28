#include "King.h"


King::King(int owner, int piece_id) : Piece(owner, piece_id)
{
	this->owner_king = owner;

}



bool King::is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8])
{
	if (get_owner() == 0)
	{


		if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol - 1))
		{
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
		else if ((endRow - 1 == startRow) && (endCol - 1 == startCol - 1))
		{
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
		else if ((endRow - 1 == startRow - 1) && (endCol - 1 == startCol))
		{
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
		else if ((endRow - 1 == startRow - 1) && (endCol - 1 == startCol - 2))
		{
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
		else if (castling(startRow, startCol, endRow, endCol, board))
		{

			return true;

		}

				

	}
	else if (get_owner() == 1)
	{

	
		if ((endRow - 1 == startRow - 2) && (endCol - 1 == startCol - 1))
		{
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
		else if ((endRow - 1 == startRow) && (endCol - 1 == startCol - 1))
		{
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
		else if ((endRow - 1 == startRow - 1) && (endCol - 1 == startCol))
		{
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
		else if ((endRow - 1 == startRow - 1) && (endCol - 1 == startCol - 2))
		{
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

	if (get_owner() == 0)
	{

		if (endRow - 1 == 7 && endCol - 1 == 6)
		{
			if (are_right_castling_sqs_valid(get_owner(), startRow, startCol, board))
			{
				board[endRow - 1][endCol - 1] = 6;
				board[endRow - 1][endCol] = 0;
				board[endRow - 1][endCol - 2] = 2;

				return true;
			}

		}
		else if (endRow - 1 == 7 && endCol - 1 == 2)
		{
			if (are_left_castling_sqs_valid(get_owner(), startRow, startCol, board))
			{
				board[endRow - 1][endCol - 1] = 6;
				board[endRow - 1][endCol - 3] = 0;
				board[endRow - 1][endCol] = 2;

				return true;
			}

		}


	}
	else if (get_owner() == 1)
	{
		if (endRow - 1 == 0 && endCol - 1 == 6)
		{
			if (are_right_castling_sqs_valid(1, startRow, startCol, board))
			{
				board[endRow - 1][endCol - 1] = 12;
				board[endRow - 1][endCol] = 0;
				board[endRow - 1][endCol - 2] = 8;

				return true;
			}

		}
		else if (endRow - 1 == 0 && endCol - 1 == 2)
		{
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
	if (owner == 0)
	{
		for (int i = 1; i < 3; ++i)
		{
			if (board[startRow - 1][startCol - 1 + i] != 0)
			{
				return false;
			}
			
		}

		if (are_right_castling_sqs_in_check(owner, startRow, startCol, board))
		{
			return false;
		}
	}
	else if (owner == 1)
	{
		for (int i = 1; i < 2; ++i)
		{
			if (board[startRow - 1][startCol - 1 + i] != 0)
			{
				return false;
			}
		}

		if (are_right_castling_sqs_in_check(owner, startRow, startCol, board))
		{
			return false;
		}

	}

	return true;
}

bool King::are_right_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8])
{

	int right = 1;

	if (owner == 0)
	{
		if (is_sq1_in_check(owner, right, startRow - 1, startCol, board) || is_sq2_in_check(owner, right, startRow - 1, startCol + 1, board))
		{
			return true;
		}
	}
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

	if (owner == 0)
	{
		for (int i = 1; i < 2; ++i)
		{
			if (board[startRow - 1][startCol - 1 - i] != 0)
			{
				return false;
			}

		}

		if (are_left_castling_sqs_in_check(owner, startRow, startCol, board))
		{
			return false;
		}
	}
	else if (owner == 1)
	{
		for (int i = 1; i < 2; ++i)
		{
			if (board[startRow - 1][startCol - 1 - i] != 0)
			{
				return false;
			}
		}

		if (are_left_castling_sqs_in_check(owner, startRow, startCol, board))
		{
			return false;
		}

	}

	return true;

}


bool King::are_left_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8])
{
	int left = 0;

	if (owner == 0)
	{
		if (is_sq1_in_check(owner, left, startRow - 1, startCol - 2, board) || is_sq2_in_check(owner, left, startRow - 1, startCol - 3, board))
		{
			return true;
		}
	}
	else if (owner == 1)
	{
		if (is_sq1_in_check(owner, left, startRow - 1, startCol - 2, board) || is_sq2_in_check(owner, left, startRow - 1, startCol - 3, board))
		{
			return true;
		}
	}


	return false;
}



bool King::is_sq1_in_check(int owner, int side, int sqRow, int sqCol, int board[8][8])
{
	
	bool is_sq_empty = false;


	if (owner == 0)
	{

		if (side == 1)
		{

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					is_sq_empty = true;

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
					else if (board[i][j] == 8)
					{

						int b_rook_n_row = 0;


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
					else if (board[i][j] == 10)
					{

						int b_bishop_n_rows = 0;


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
					else if (board[i][j] == 11)
					{

						int b_queen_n_rows = 0;


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
		else if (side == 0)
		{
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					is_sq_empty = true;

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
					else if (board[i][j] == 8)
					{

						int b_rook_n_row = 0;


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
					else if (board[i][j] == 10)
					{

						int b_bishop_n_rows = 0;



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
					else if (board[i][j] == 11)
					{

						int b_queen_n_rows = 0;



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
	else if (owner == 1)
	{
		if (side == 1)
		{
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					is_sq_empty = true;

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
					else if (board[i][j] == 2)
					{


						int w_rook_n_row = 0;


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
					else if (board[i][j] == 4)
					{

						int w_bishop_n_rows = 0;


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
					else if (board[i][j] == 5)
					{


						int w_queen_n_rows = 0;


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
		else if (side == 0)
		{
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					is_sq_empty = true;

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
					else if (board[i][j] == 2)
					{


						int w_rook_n_row = 0;


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
					else if (board[i][j] == 4)
					{

						int w_bishop_n_rows = 0;


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
					else if (board[i][j] == 5)
					{


						int w_queen_n_rows = 0;


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
	bool is_sq_empty = false;


	if (owner == 0)
	{

		if (side == 1)
		{

			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					is_sq_empty = true;

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
					else if (board[i][j] == 8)
					{

						int b_rook_n_row = 0;


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
					else if (board[i][j] == 10)
					{

						int b_bishop_n_rows = 0;



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
					else if (board[i][j] == 11)
					{

						int b_queen_n_rows = 0;


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
		else if (side == 0)
		{
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					is_sq_empty = true;

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
					else if (board[i][j] == 8)
					{

						int b_rook_n_row = 0;


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
					else if (board[i][j] == 10)
					{

						int b_bishop_n_rows = 0;


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
					else if (board[i][j] == 11)
					{

						int b_queen_n_rows = 0;


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
	else if (owner == 1)
	{
		if (side == 1)
		{
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					is_sq_empty = true;

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
					else if (board[i][j] == 2)
					{


						int w_rook_n_row = 0;


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
					else if (board[i][j] == 4)
					{

						int w_bishop_n_rows = 0;


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
					else if (board[i][j] == 5)
					{


						int w_queen_n_rows = 0;


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
		else if (side == 0)
		{
			for (int i = 0; i < 8; ++i)
			{
				for (int j = 0; j < 8; ++j)
				{

					is_sq_empty = true;

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
					else if (board[i][j] == 2)
					{


						int w_rook_n_row = 0;


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
					else if (board[i][j] == 4)
					{

						int w_bishop_n_rows = 0;



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
					else if (board[i][j] == 5)
					{


						int w_queen_n_rows = 0;


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




