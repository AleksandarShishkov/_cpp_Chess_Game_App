#include "CGame.h"

CGame::CGame()
{

}

void CGame::set_board()
{


	
	board[7][0] = w_rook;
	board[7][1] = w_knight;
	board[7][2] = w_bishop;
	board[7][3] = w_queen;
	board[7][4] = w_king;
	board[7][5] = w_bishop;
	board[7][6] = w_knight;
	board[7][7] = w_rook;



	for (int i = 0; i < size_r; ++i)
	{
		board[6][i] = w_pawn;
	}


	board[0][0] = b_rook;
	board[0][1] = b_knight;
	board[0][2] = b_bishop;
	board[0][3] = b_queen;
	board[0][4] = b_king;
	board[0][5] = b_bishop;
	board[0][6] = b_knight;
	board[0][7] = b_rook;


	for (int i = 0; i < size_r; ++i)
	{
		board[1][i] = b_pawn;
	}


	for (int i = 0; i < size_r; ++i)
	{
		for (int j = 0; j < size_c; ++j)
		{
			if (board[i][j] != w_pawn && board[i][j] != w_rook && board[i][j] != w_knight &&
				board[i][j] != w_bishop && board[i][j] != w_queen && board[i][j] != w_king &&
				board[i][j] != b_pawn && board[i][j] != b_rook && board[i][j] != b_knight &&
				board[i][j] != b_bishop && board[i][j] != b_queen && board[i][j] != b_king)
			{
				board[i][j] = sq_empty;
			}
		}
	}
}


void CGame::move_piece(int startRow, int startCol, int endRow, int endCol)
{

	if (board[startRow - 1][startCol - 1] == 1 || board[startRow - 1][startCol - 1] == 7)
	{

		if (pawn->pawn_promotion(startRow, startCol, endRow, endCol, board))
		{
			board[startRow - 1][startCol - 1] = sq_empty;
		}
		else if (board[startRow - 1][startCol - 1] == 1 && pawn->is_pawn_en_passant())
		{
			
			board[startRow - 1][startCol - 1] = sq_empty;
			this->last_move_white += "_/_captures_black_'p'_awn";
			board[endRow - 1][endCol - 1] = get_piece_id();
			
		}
		else if (board[startRow - 1][startCol - 1] == 7 && pawn->is_pawn_en_passant())
		{
			board[startRow - 1][startCol - 1] = sq_empty;
			this->last_move_black += "_/_captures_white_'P'_awn";

			board[endRow - 1][endCol - 1] = get_piece_id();

		}
		else
		{
			board[startRow - 1][startCol - 1] = sq_empty;
			
			if (board[endRow - 1][endCol - 1] == 1)
			{
				this->last_move_black += "_/_captures_white_'P'_awn";
			}
			else if (board[endRow - 1][endCol - 1] == 2)
			{
				this->last_move_black += "_/_captures_white_'R'_ook";
			}
			else if (board[endRow - 1][endCol - 1] == 3)
			{
				this->last_move_black += "_/_captures_white_K_'N'_ight";
			}
			else if (board[endRow - 1][endCol - 1] == 4)
			{
				this->last_move_black += "_/_captures_white_'B'_ishop";
			}
			else if (board[endRow - 1][endCol - 1] == 5)
			{
				this->last_move_black += "_/_captures_white_'Q'_ueen";
			}
			else if (board[endRow - 1][endCol - 1] == 6)
			{
				this->last_move_black += "_/_captures_white_'K'_intg";
			}
			else if (board[endRow - 1][endCol - 1] == 7)
			{
				this->last_move_white += "_/_captures_black_'p'_awn";
			}
			else if (board[endRow - 1][endCol - 1] == 8)
			{
				this->last_move_white += "_/_captures_black_'r'_ook";
			}
			else if (board[endRow - 1][endCol - 1] == 9)
			{
				this->last_move_white += "_/_captures_black_k_'n'_ight";
			}
			else if (board[endRow - 1][endCol - 1] == 10)
			{
				this->last_move_white += "_/_captures_black_'b'_ishop";
			}
			else if (board[endRow - 1][endCol - 1] == 11)
			{
				this->last_move_white += "_/_captures_black_'q'_een";
			}
			else if (board[endRow - 1][endCol - 1] == 12)
			{
				this->last_move_white += "_/_captures black_'k'_ing";
			}

			board[endRow - 1][endCol - 1] = get_piece_id();

		}

	}
	else if (board[startRow - 1][startCol - 1 == w_king] && endRow - 1 == 7 && endCol - 1 == 6)
	{
		board[startRow - 1][startCol - 1] = sq_empty;
	}
	else if (board[startRow - 1][startCol - 1] == w_king && endRow - 1 == 7 && endCol - 1 == 2)
	{
		board[startRow - 1][startCol - 1] = sq_empty;
	}
	else if (board[startRow - 1][startCol - 1] == b_king && endRow - 1 == 0 && endCol - 1 == 6)
	{
		board[startRow - 1][startCol - 1] = sq_empty;
	}
	else if(board[startRow - 1][startCol - 1] == b_king && endRow - 1 == 0 && endCol - 1 == 2)
	{
		board[startRow - 1][startCol - 1] = sq_empty;
	}
	else
	{

		board[startRow - 1][startCol - 1] = sq_empty;

		if (board[endRow - 1][endCol - 1] == 1)
		{
			this->last_move_black += "_/_captures_white_'P'_awn";
		}
		else if (board[endRow - 1][endCol - 1] == 2)
		{
			this->last_move_black += "_/_captures_white_'R'_ook";
		}
		else if (board[endRow - 1][endCol - 1] == 3)
		{
			this->last_move_black += "_/_captures_white_K_'N'_ight";
		}
		else if (board[endRow - 1][endCol - 1] == 4)
		{
			this->last_move_black += "_/_captures_white_'B'_ishop";
		}
		else if (board[endRow - 1][endCol - 1] == 5)
		{
			this->last_move_black += "_/_captures_white_'Q'_ueen";
		}
		else if (board[endRow - 1][endCol - 1] == 6)
		{
			this->last_move_black += "_/_captures_white_'K'_intg";
		}
		else if (board[endRow - 1][endCol - 1] == 7)
		{
			this->last_move_white += "_/_captures_black_'p'_awn";
		}
		else if (board[endRow - 1][endCol - 1] == 8)
		{
			this->last_move_white += "_/_captures_black_'r'_ook";
		}
		else if (board[endRow - 1][endCol - 1] == 9)
		{
			this->last_move_white += "_/_captures_black_k_'n'_ight";
		}
		else if (board[endRow - 1][endCol - 1] == 10)
		{
			this->last_move_white += "_/_captures_black_'b'_ishop";
		}
		else if (board[endRow - 1][endCol - 1] == 11)
		{
			this->last_move_white += "_/_captures_black_'q'_een";
		}
		else if (board[endRow - 1][endCol - 1] == 12)
		{
			this->last_move_white += "_/_captures black_'k'_ing";
		}

		board[endRow - 1][endCol - 1] = get_piece_id();

	}
	

	print_score();
	print_save_exit();
	print_count_moves();
	print_last_move();
	print_board();

}

int CGame::get_piece(int row, int col)
{

	if (board[row - 1][col - 1] == w_pawn)
	{
		this->piece_id = 1;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == w_rook)
	{
		this->piece_id = 2;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == w_knight)
	{
		this->piece_id = 3;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == w_bishop)
	{
		this->piece_id = 4;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == w_queen)
	{
		this->piece_id = 5;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == w_king)
	{
		this->piece_id = 6;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == b_pawn)
	{
		this->piece_id = 7;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == b_rook)
	{
		this->piece_id = 8;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == b_knight)
	{
		this->piece_id = 9;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == b_bishop)
	{
		this->piece_id = 10;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == b_queen)
	{
		this->piece_id = 11;
		return get_piece_id();
	}
	else if (board[row - 1][col - 1] == b_king)
	{
		this->piece_id = 12;
		return get_piece_id();
	}

	return 0;
}


bool CGame::is_in_check()
{
	int w_xK = 0, w_yK = 0, b_xK = 0, b_yK = 0;

	bool is_sq_empty;

	if (current_turn == white_owner)
	{
		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{
				if (board[i][j] == w_king)
				{
					w_xK = i;
					w_yK = j;

					break;
				}

			}

		}


		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{

				is_sq_empty = true;

				if (board[i][j] == b_pawn)
				{
					if ((i + 1 == w_xK) && (j + 1 == w_yK))
					{
						return true;
					}
					else if ((i + 1 == w_xK) && (j - 1 == w_yK))
					{
						return true;
					}
				}
				else if (board[i][j] == b_rook)
				{

					int b_rook_n_row = 0;


					int b_rook_n_col = 0;


					if (i > w_xK && j == w_yK)
					{
						b_rook_n_row = i - w_xK;

						
						if ((i - b_rook_n_row == w_xK) && (j == w_yK))
						{

							if (b_rook_n_row == 1)
							{

								for (int k = 1; k <= b_rook_n_row; ++k)
								{

									if (board[i - k][j] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < b_rook_n_row; ++k)
								{

									if (board[i - k][j] != sq_empty)
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


					if (i < w_xK && j == w_yK)
					{
						b_rook_n_row = w_xK - i;

						if ((i + b_rook_n_row == w_xK) && (j == w_yK))
						{

							if (b_rook_n_row == 1)
							{

								for (int k = 1; k <= b_rook_n_row; ++k)
								{
									if (board[i + k][j] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < b_rook_n_row; ++k)
								{
									if (board[i + k][j] != sq_empty)
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


					if (i == w_xK && j < w_yK)
					{
						b_rook_n_col = w_yK - j;

						if ((i == w_xK) && (j + b_rook_n_col == w_yK))
						{

							if (b_rook_n_col == 1)
							{

								for (int k = 1; k <= b_rook_n_col; ++k)
								{
									if (board[i][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < b_rook_n_col; ++k)
								{
									if (board[i][j + k] != sq_empty)
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


					if (i == w_xK && j > w_yK)
					{
						b_rook_n_col = i - w_yK;


						if ((i == w_xK) && (j - b_rook_n_col == w_yK))
						{

							if (b_rook_n_col == 1)
							{

								for (int k = 1; k <= b_rook_n_col; ++k)
								{
									if (board[i][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < b_rook_n_col; ++k)
								{
									if (board[i][j - k] != sq_empty)
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
				else if (board[i][j] == b_knight)
				{

					if (i - 2 == w_xK && j + 1 == w_yK)
					{
						return true;
					}

					if (i - 2 == w_xK && j - 1 == w_yK)
					{
						return true;
					}

					if (i - 1 == w_xK && j + 2 == w_yK)
					{
						return true;
					}

					if (i + 1 == w_xK && j + 2 == w_yK)
					{
						return true;
					}

					if (i + 2 == w_xK && j + 1 == w_yK)
					{
						return true;
					}

					if (i + 2 == w_xK && j - 1 == w_yK)
					{
						return true;
					}

					if (i + 1 == w_xK && j - 2 == w_yK)
					{
						return true;
					}

					if (i - 1 == w_xK && j - 2 == w_yK)
					{
						return true;
					}


				}
				else if (board[i][j] == b_bishop)
				{

					int b_bishop_n_rows = 0;

					if (i < w_xK && j < w_yK)
					{
						b_bishop_n_rows = w_xK - i;


						if ((i + b_bishop_n_rows == w_xK) && (j + b_bishop_n_rows == w_yK))
						{

							if (b_bishop_n_rows == 1)
							{

								for (int k = 1; k <= b_bishop_n_rows; ++k)
								{
									if (board[i + k][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < b_bishop_n_rows; ++k)
								{
									if (board[i + k][j + k] != sq_empty)
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


					if (i > w_xK && j < w_yK)
					{
						b_bishop_n_rows = i - w_xK;

						if ((i - b_bishop_n_rows == w_xK) && (j + b_bishop_n_rows == w_yK))
						{

							if (b_bishop_n_rows == 1)
							{

								for (int k = 1; k <= b_bishop_n_rows; ++k)
								{

									if (board[i - k][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < b_bishop_n_rows; ++k)
								{

									if (board[i - k][j + k] != sq_empty)
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


					if (i < w_xK && j > w_yK)
					{
						b_bishop_n_rows = w_xK - i;

						if ((i + b_bishop_n_rows == w_xK) && (j - b_bishop_n_rows == w_yK))
						{

							if (b_bishop_n_rows == 1)
							{

								for (int k = 1; k <= b_bishop_n_rows; ++k)
								{

									if (board[i + k][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < b_bishop_n_rows; ++k)
								{

									if (board[i + k][j - k] != sq_empty)
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


					if (i > w_xK && j > w_yK)
					{
						b_bishop_n_rows = i - w_xK;

						if ((i - b_bishop_n_rows == w_xK) && (j - b_bishop_n_rows == w_yK))
						{

							if (b_bishop_n_rows == 1)
							{

								for (int k = 1; k <= b_bishop_n_rows; ++k)
								{

									if (board[i - k][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < b_bishop_n_rows; ++k)
								{

									if (board[i - k][j - k] != sq_empty)
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
				else if (board[i][j] == b_queen)
				{

					int b_queen_n_rows = 0;

					int b_queen_n_cols = 0;


					if (i > w_xK && j == w_yK)
					{
						b_queen_n_rows = i - w_xK;

						
						if ((i - b_queen_n_rows == w_xK) && (j == w_yK))
						{
							if (b_queen_n_rows == 1)
							{
								for (int k = 1; k <= b_queen_n_rows; ++k)
								{
									if (board[i - k][j] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{

								for (int k = 1; k < b_queen_n_rows; ++k)
								{
									if (board[i - k][j] != sq_empty)
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


					if (i < w_xK && j == w_yK)
					{
						b_queen_n_rows = w_xK - i;

						if ((i + b_queen_n_rows == w_xK) && (j == w_yK))
						{

							if (b_queen_n_rows == 1)
							{

								for (int k = 1; k <= b_queen_n_rows; ++k)
								{
									if (board[i + k][j] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < b_queen_n_rows; ++k)
								{
									if (board[i + k][j] != sq_empty)
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


					if (i == w_xK && j < w_yK)
					{
						b_queen_n_cols = w_yK - i;


						if ((i == w_xK) && (j + b_queen_n_cols == w_yK))
						{

							if (b_queen_n_cols == 1)
							{

								for (int k = 1; k <= b_queen_n_rows; ++k)
								{
									if (board[i][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < b_queen_n_rows; ++k)
								{
									if (board[i][j + k] != sq_empty)
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


					if (i == w_xK && j > w_yK)
					{
						b_queen_n_cols = i - w_yK;

						
						if ((i == w_xK) && (j - b_queen_n_cols == w_yK))
						{

							if (b_queen_n_cols == 1)
							{
								for (int k = 1; k <= b_queen_n_cols; ++k)
								{
									if (board[i][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < b_queen_n_cols; ++k)
								{
									if (board[i][j - k] != sq_empty)
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


					if (i < w_xK && j < w_yK)
					{
						b_queen_n_rows = w_xK - i;


						if ((i + b_queen_n_rows == w_xK) && (j + b_queen_n_rows == w_yK))
						{

							if (b_queen_n_rows == 1)
							{

								for (int k = 1; k <= b_queen_n_rows; ++k)
								{
									if (board[i + k][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < b_queen_n_rows; ++k)
								{
									if (board[i + k][j + k] != sq_empty)
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


					if (i > w_xK && j > w_yK)
					{
						b_queen_n_rows = i - w_xK;


						if ((i - b_queen_n_rows == w_xK) && (j + b_queen_n_rows == w_yK))
						{
							if (b_queen_n_rows == 1)
							{

								for (int k = 1; k <= b_queen_n_rows; ++k)
								{
									if (board[i - k][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < b_queen_n_rows; ++k)
								{
									if (board[i - k][j + k] != sq_empty)
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


					if (i < w_xK && j > w_yK)
					{
						b_queen_n_rows = w_xK - i;


						if ((i + b_queen_n_rows == w_xK) && (j - b_queen_n_rows == w_yK))
						{

							if (b_queen_n_rows == 1)
							{
								for (int k = 1; k <= b_queen_n_rows; ++k)
								{
									if (board[i + k][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{

								for (int k = 1; k < b_queen_n_rows; ++k)
								{
									if (board[i + k][j - k] != sq_empty)
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


					if (i > w_xK && j > w_yK)
					{
						b_queen_n_rows = i - w_xK;


						if ((i - b_queen_n_rows == w_xK) && (j - b_queen_n_rows == w_yK))
						{
							if (b_queen_n_rows == 1)
							{

								for (int k = 1; k <= b_queen_n_rows; ++k)
								{
									if (board[i - k][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < b_queen_n_rows; ++k)
								{
									if (board[i - k][j - k] != sq_empty)
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
	else if (current_turn == black_owner)
	{

		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{
				if (board[i][j] == b_king)
				{
					b_xK = i;
					b_yK = j;

					break;
				}
			}
		}


		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{

				is_sq_empty = true;

				if (board[i][j] == w_pawn)
				{
					if ((i - 1 == b_xK) && (j + 1 == b_yK))
					{
						return true;
					}
					else if ((i - 1 == b_xK) && (j - 1 == b_yK))
					{
						return true;
					}

				}
				else if (board[i][j] == w_rook)
				{


					int w_rook_n_row = 0;

					int w_rook_n_col = 0;



					if (i > b_xK && j == b_yK)
					{
						w_rook_n_row = i - b_xK;


						if ((i - w_rook_n_row == b_xK) && (j == b_yK))
						{

							if (w_rook_n_row == 1)
							{

								for (int k = 1; k <= w_rook_n_row; ++k)
								{

									if (board[i - k][j] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{

								for (int k = 1; k < w_rook_n_row; ++k)
								{

									if (board[i - k][j] != sq_empty)
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


					if (i < b_xK && j == b_yK)
					{
						w_rook_n_row = b_xK - i;

						if ((i + w_rook_n_row == b_xK) && (j == b_yK))
						{

							if (w_rook_n_row == 1)
							{

								for (int k = 1; k <= w_rook_n_row; ++k)
								{
									if (board[i + k][j] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < w_rook_n_row; ++k)
								{
									if (board[i + k][j] != sq_empty)
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


					if (i == b_xK && j < b_yK)
					{
						w_rook_n_col = b_yK - j;

						if ((i == b_xK) && (j + w_rook_n_col == b_yK))
						{

							if (w_rook_n_col == 1)
							{

								for (int k = 1; k <= w_rook_n_col; ++k)
								{
									if (board[i][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < w_rook_n_col; ++k)
								{
									if (board[i][j + k] != sq_empty)
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


					if (i == b_xK && j > b_yK)
					{
						w_rook_n_col = j - b_yK;

						
						if ((i == b_xK) && (j - w_rook_n_col == b_yK))
						{

							if (w_rook_n_col == 1)
							{

								for (int k = 1; k <= w_rook_n_col; ++k)
								{
									if (board[i][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < w_rook_n_col; ++k)
								{
									if (board[i][j - k] != sq_empty)
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
				else if (board[i][j] == w_knight)
				{
					if (i - 2 == b_xK && j + 1 == b_yK)
					{
						return true;
					}
					
					if (i - 2 == b_xK && j - 1 == b_yK)
					{
						return true;
					}
					
					if (i - 1 == b_xK && j + 2 == b_yK)
					{
						return true;
					}
					
					if (i + 1 == b_xK && j + 2 == b_yK)
					{
						return true;
					}
					
					if (i + 2 == b_xK && j + 1 == b_yK)
					{
						return true;
					}
					
					if (i + 2 == b_xK && j - 1 == b_yK)
					{
						return true;
					}
					
					if (i + 1 == b_xK && j - 2 == b_yK)
					{
						return true;
					}
					
					if (i - 1 == b_xK && j - 2 == b_yK)
					{
						return true;
					}
					


				}
				else if (board[i][j] == w_bishop)
				{

					int w_bishop_n_rows = 0;



					if (i < b_xK && j < b_yK)
					{
						w_bishop_n_rows = b_xK - i;


						if ((i + w_bishop_n_rows == b_xK) && (j + w_bishop_n_rows == b_yK))
						{

							if (w_bishop_n_rows == 1)
							{

								for (int k = 1; k <= w_bishop_n_rows; ++k)
								{
									if (board[i + k][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < w_bishop_n_rows; ++k)
								{
									if (board[i + k][j + k] != sq_empty)
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


					if (i > b_xK && j < b_yK)
					{
						w_bishop_n_rows = i - b_xK;


						if ((i - w_bishop_n_rows == b_xK) && (j + w_bishop_n_rows == b_yK))
						{

							if (w_bishop_n_rows == 1)
							{

								for (int k = 1; k <= w_bishop_n_rows; ++k)
								{

									if (board[i - k][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < w_bishop_n_rows; ++k)
								{

									if (board[i - k][j + k] != sq_empty)
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


					if (i < b_xK && j > b_yK)
					{
						w_bishop_n_rows = b_xK - i;


						if ((i + w_bishop_n_rows == b_xK) && (j - w_bishop_n_rows == b_yK))
						{

							if (w_bishop_n_rows == 1)
							{

								for (int k = 1; k <= w_bishop_n_rows; ++k)
								{

									if (board[i + k][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < w_bishop_n_rows; ++k)
								{

									if (board[i + k][j - k] != sq_empty)
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


					if (i > b_xK && j > b_yK)
					{
						w_bishop_n_rows = i - b_xK;


						if ((i - w_bishop_n_rows == b_xK) && (j - w_bishop_n_rows == b_yK))
						{

							if (w_bishop_n_rows == 1)
							{

								for (int k = 1; k <= w_bishop_n_rows; ++k)
								{

									if (board[i - k][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < w_bishop_n_rows; ++k)
								{

									if (board[i - k][j - k] != sq_empty)
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
				else if (board[i][j] == w_queen)
				{


					int w_queen_n_rows = 0;

					int w_queen_n_cols = 0;



					if (i > b_xK && j == b_yK)
					{
						w_queen_n_rows = i - b_xK;

						
						if ((i - w_queen_n_rows == b_xK) && (j == b_yK))
						{

							if (w_queen_n_rows == 1)
							{

								for (int k = 1; k <= w_queen_n_rows; ++k)
								{
									if (board[i - k][j] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < w_queen_n_rows; ++k)
								{
									if (board[i - k][j] != sq_empty)
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


					if (i < b_xK && j == b_yK)
					{
						w_queen_n_rows = b_xK - i;

						if ((i + w_queen_n_rows == b_xK) && (j == b_yK))
						{

							if (w_queen_n_rows == 1)
							{

								for (int k = 1; k <= w_queen_n_rows; ++k)
								{
									if (board[i + k][j] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < w_queen_n_rows; ++k)
								{
									if (board[i + k][j] != sq_empty)
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


					{
						w_queen_n_cols = b_yK - j;

						if ((i == b_xK) && (j + w_queen_n_cols == b_yK))
						{

							if (w_queen_n_cols == 1)
							{

								for (int k = 1; k <= w_queen_n_cols; ++k)
								{
									if (board[i][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < w_queen_n_cols; ++k)
								{
									if (board[i][j + k] != sq_empty)
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


					if (i == b_xK && j > b_yK)
					{
						w_queen_n_cols = j - b_yK;



						if ((i == b_xK) && (j - w_queen_n_cols == b_yK))
						{

							if (w_queen_n_cols == 1)
							{

								for (int k = 1; k <= w_queen_n_cols; ++k)
								{
									if (board[i][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}
								}
							}
							else
							{
								for (int k = 1; k < w_queen_n_cols; ++k)
								{
									if (board[i][j - k] != sq_empty)
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


					if (i < b_xK && j < b_yK)
					{
						w_queen_n_rows = b_xK - i;


						if ((i + w_queen_n_rows == b_xK) && (j + w_queen_n_rows == b_yK))
						{

							if (w_queen_n_rows == 1)
							{

								for (int k = 1; k <= w_queen_n_rows; ++k)
								{
									if (board[i + k][j + k] != sq_empty)
									{
										is_sq_empty = false;

									}

								}
							}
							else
							{
								for (int k = 1; k < w_queen_n_rows; ++k)
								{
									if (board[i + k][j + k] != sq_empty)
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



					if (i > b_xK && j < b_yK)
					{
						w_queen_n_rows = i - b_xK;


						if ((i - w_queen_n_rows == b_xK) && (j + w_queen_n_rows == b_yK))
						{

							if (w_queen_n_rows == 1)
							{

								for (int k = 1; k <= w_queen_n_rows; ++k)
								{

									if (board[i - k][j + k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < w_queen_n_rows; ++k)
								{

									if (board[i - k][j + k] != sq_empty)
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


					if (i < b_xK && j > b_yK)
					{
						w_queen_n_rows = b_xK - i;


						if ((i + w_queen_n_rows == b_xK) && (j - w_queen_n_rows == b_yK))
						{

							if (w_queen_n_rows == 1)
							{

								for (int k = 1; k <= w_queen_n_rows; ++k)
								{
									if (board[i + k][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < w_queen_n_rows; ++k)
								{
									if (board[i + k][j - k] != sq_empty)
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


					if (i > b_xK && j > b_yK)
					{
						w_queen_n_rows = i - b_xK;


						if ((i - w_queen_n_rows == b_xK) && (j - w_queen_n_rows == b_yK))
						{

							if (w_queen_n_rows == 1)
							{

								for (int k = 1; k <= w_queen_n_rows; ++k)
								{
									if (board[i - k][j - k] != sq_empty)
									{
										is_sq_empty = false;
									}

								}
							}
							else
							{
								for (int k = 1; k < w_queen_n_rows; ++k)
								{
									if (board[i - k][j - k] != sq_empty)
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

	return false;

}


bool CGame::is_stalemate()
{
	
	int w_xK = 0, w_yK = 0, b_xK = 0, b_yK = 0;
	
	
	if (current_turn == white_owner)
	{

		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{
				if (board[i][j] == w_king)
				{
					w_xK = i;
					w_yK = j;

					break;
				}
			}
		}



		if (!is_in_check())
		{

			if (w_xK - 1 != -1)
			{

				if (board[w_xK - 1][w_yK] == sq_empty || (board[w_xK - 1][w_yK] >= b_pawn &&
					board[w_xK - 1][w_yK] <= b_queen))
				{
					current_piece = board[w_xK - 1][w_yK];
					board[w_xK - 1][w_yK] = w_king;
					board[w_xK][w_yK] = sq_empty;

					if (is_in_check())
					{
						board[w_xK - 1][w_yK] = current_piece;
						board[w_xK][w_yK] = w_king;
					}
					else
					{
						board[w_xK - 1][w_yK] = current_piece;
						board[w_xK][w_yK] = w_king;
						return false;
					}
				}


				if (w_yK - 1 != -1)
				{
					if (board[w_xK - 1][w_yK - 1] >= b_pawn && board[w_xK - 1][w_yK - 1] <= b_queen)
					{
						current_piece = board[w_xK - 1][w_yK - 1];
						board[w_xK - 1][w_yK - 1] = w_king;
						board[w_xK][w_yK] = sq_empty;

						if (is_in_check())
						{
							board[w_xK - 1][w_yK - 1] = current_piece;
							board[w_xK][w_yK] = w_king;
						}
						else
						{
							board[w_xK - 1][w_yK - 1] = current_piece;
							board[w_xK][w_yK] = w_king;
							return false;
						}
					}
				}


				if (w_yK + 1 != size_c)
				{
					if (board[w_xK - 1][w_yK + 1] >= b_pawn && board[w_xK - 1][w_yK + 1] <= b_queen)
					{
						current_piece = board[w_xK - 1][w_yK + 1];
						board[w_xK - 1][w_yK + 1] = w_king;
						board[w_xK][w_yK] = sq_empty;

						if (is_in_check())
						{
							board[w_xK - 1][w_yK + 1] = current_piece;
							board[w_xK][w_yK] = w_king;
						}
						else
						{
							board[w_xK - 1][w_yK + 1] = current_piece;
							board[w_xK][w_yK] = w_king;
							return false;
						}
					}
				}

			}


			if (w_xK + 1 != size_r)
			{
				if (board[w_xK + 1][w_yK] == sq_empty || (board[w_xK + 1][w_yK] >= b_pawn &&
					board[w_xK + 1][w_yK] <= b_queen))
				{
					current_piece = board[w_xK + 1][w_yK];
					board[w_xK + 1][w_yK] = w_king;
					board[w_xK][w_yK] = sq_empty;

					if (is_in_check())
					{
						board[w_xK + 1][w_yK] = current_piece;
						board[w_xK][w_yK] = w_king;
					}
					else
					{
						board[w_xK + 1][w_yK] = current_piece;
						board[w_xK][w_yK] = w_king;
						return false;
					}
				}


				if (w_yK - 1 != -1)
				{
					if (board[w_xK + 1][w_yK - 1] >= b_pawn && board[w_xK + 1][w_yK - 1] <= b_queen)
					{
						current_piece = board[w_xK + 1][w_yK - 1];
						board[w_xK + 1][w_yK - 1] = w_king;
						board[w_xK][w_yK] = sq_empty;


						if (is_in_check())
						{
							board[w_xK + 1][w_yK - 1] = current_piece;
							board[w_xK][w_yK] = w_king;

						}
						else
						{
							board[w_xK + 1][w_yK - 1] = current_piece;
							board[w_xK][w_yK] = w_king;
							return false;
						}
					}
				}


				if (w_yK + 1 != size_c)
				{
					if (board[w_xK + 1][w_yK + 1] >= b_pawn && board[w_xK + 1][w_yK + 1] <= b_queen)
					{
						current_piece = board[w_xK + 1][w_yK + 1];
						board[w_xK + 1][w_yK + 1] = w_king;
						board[w_xK][w_yK] = sq_empty;

						if (is_in_check())
						{
							board[w_xK + 1][w_yK + 1] = current_piece;
							board[w_xK][w_yK] = w_king;
						}
						else
						{
							board[w_xK + 1][w_yK + 1] = current_piece;
							board[w_xK][w_yK] = w_king;
							return false;
						}
					}
				}
			}
			
			
			if (w_yK - 1 != -1)
			{
				if (board[w_xK][w_yK - 1] == sq_empty || (board[w_xK][w_yK - 1] >= b_pawn &&
					board[w_xK][w_yK - 1] <= b_queen))
				{
					current_piece = board[w_xK][w_yK - 1];
					board[w_xK][w_yK - 1] = w_king;
					board[w_xK][w_yK] = sq_empty;

					if (is_in_check())
					{
						board[w_xK][w_yK - 1] = current_piece;
						board[w_xK][w_yK] = w_king;
					}
					else
					{
						board[w_xK][w_yK - 1] = current_piece;
						board[w_xK][w_yK] = w_king;
						return false;
					}
				}
			}


			if (w_yK + 1 != size_c)
			{
				if (board[w_xK][w_yK + 1] == sq_empty || (board[w_xK][w_yK + 1] >= b_pawn &&
					board[w_xK][w_yK + 1] <= b_queen))
				{
					current_piece = board[w_xK][w_yK + 1];
					board[w_xK][w_yK + 1] = w_king;
					board[w_xK][w_yK] = sq_empty;

					if (is_in_check())
					{
						board[w_xK][w_yK + 1] = current_piece;
						board[w_xK][w_yK] = w_king;
					}
					else
					{
						board[w_xK][w_yK + 1] = current_piece;
						board[w_xK][w_yK] = w_king;
						return false;
					}
				}
			}

		}
	}
	else if (current_turn == black_owner)
	{

		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{
				if (board[i][j] == b_king)
				{
					b_xK = i;
					b_yK = j;
				}
			}
		}

		
		if (!is_in_check())
		{

			if (b_xK - 1 != -1)
			{

				if (board[b_xK - 1][b_yK] == sq_empty || (board[b_xK - 1][b_yK] >= w_pawn &&
					board[b_xK - 1][b_yK] <= w_queen))
				{
					current_piece = board[b_xK - 1][b_yK];
					board[b_xK - 1][b_yK] = b_king;
					board[b_xK][b_yK] = sq_empty;

					if (is_in_check())
					{
						board[b_xK - 1][b_yK] = current_piece;
						board[b_xK][b_yK] = b_king;
					}
					else
					{
						board[b_xK - 1][b_yK] = current_piece;
						board[b_xK][b_yK] = b_king;
						return false;
					}
				}


				if (b_yK - 1 != -1)
				{
					if (board[b_xK - 1][b_yK - 1] >= w_pawn && board[b_xK - 1][b_yK - 1] <= w_queen)
					{
						current_piece = board[b_xK - 1][b_yK - 1];
						board[b_xK - 1][b_yK - 1] = b_king;
						board[b_xK][b_yK] = sq_empty;

						if (is_in_check())
						{
							board[b_xK - 1][b_yK - 1] = current_piece;
							board[b_xK][b_yK] = b_king;
						}
						else
						{
							board[b_xK - 1][b_yK - 1] = current_piece;
							board[b_xK][b_yK] = b_king;
							return false;
						}
					}
				}


				if (b_yK + 1 != size_c)
				{
					if (board[b_xK - 1][b_yK + 1] >= w_pawn && board[b_xK - 1][b_yK + 1] <= w_queen)
					{
						current_piece = board[b_xK - 1][b_yK + 1];
						board[b_xK - 1][b_yK + 1] = b_king;
						board[b_xK][b_yK] = sq_empty;

						if (is_in_check())
						{
							board[b_xK - 1][b_yK + 1] = current_piece;
							board[b_xK][b_yK] = b_king;
						}
						else
						{
							board[b_xK - 1][b_yK + 1] = current_piece;
							board[b_xK][b_yK] = b_king;
							return false;
						}
					}
				}

			}
			
			
			if (b_xK + 1 < size_r)
			{
				if (board[b_xK + 1][b_yK] == sq_empty || (board[b_xK + 1][b_yK] >= w_pawn &&
					board[b_xK + 1][b_yK - 1] <= w_queen))
				{
					current_piece = board[b_xK + 1][b_yK];
					board[b_xK + 1][b_yK] = b_king;
					board[b_xK][b_yK] = sq_empty;

					if (is_in_check())
					{
						board[b_xK + 1][b_yK] = current_piece;
						board[b_xK][b_yK] = b_king;
					}
					else
					{
						board[b_xK + 1][b_yK] = current_piece;
						board[b_xK][b_yK] = b_king;
						return false;
					}
				}


				if (b_yK - 1 != -1)
				{
					if (board[b_xK + 1][b_yK - 1] >= w_pawn && board[b_xK + 1][b_yK - 1] <= w_queen)
					{
						current_piece = board[b_xK + 1][b_yK - 1];
						board[b_xK + 1][b_yK - 1] = b_king;
						board[b_xK][b_yK] = sq_empty;

						if (is_in_check())
						{
							board[b_xK + 1][b_yK - 1] = current_piece;
							board[b_xK][b_yK] = b_king;
						}
						else
						{
							board[b_xK + 1][b_yK - 1] = current_piece;
							board[b_xK][b_yK] = b_king;
							return false;
						}
					}
				}


				if (b_yK + 1 != size_c)
				{
					if (board[b_xK + 1][b_yK + 1] >= w_pawn && board[b_xK + 1][b_yK + 1] <= w_queen)
					{
						current_piece = board[b_xK + 1][b_yK + 1];
						board[b_xK + 1][b_yK + 1] = b_king;
						board[b_xK][b_yK] = sq_empty;

						if (is_in_check())
						{
							board[b_xK + 1][b_yK + 1] = current_piece;
							board[b_xK][b_yK] = b_king;
						}
						else
						{
							board[b_xK + 1][b_yK + 1] = current_piece;
							board[b_xK][b_yK] = b_king;
							return false;
						}
					}
				}
			}


			if (b_yK - 1 != -1)
			{
				if (board[b_xK][b_yK - 1] == sq_empty || (board[b_xK][b_yK - 1] >= w_pawn &&
					board[b_xK][b_yK - 1] <= w_queen))
				{
					current_piece = board[b_xK][b_yK - 1];
					board[b_xK][b_yK - 1] = b_king;
					board[b_xK][b_yK] = sq_empty;

					if (is_in_check())
					{
						board[b_xK][b_yK - 1] = current_piece;
						board[b_xK][b_yK] = b_king;
					}
					else
					{
						board[b_xK][b_yK - 1] = current_piece;
						board[b_xK][b_yK] = b_king;
						return false;
					}
				}
			}


			if (b_yK + 1 != size_c)
			{
				if (board[b_xK][b_yK + 1] == sq_empty || (board[b_xK][b_yK + 1] >= w_pawn &&
					board[b_xK][b_yK + 1] <= w_queen))
				{
					current_piece = board[b_xK][b_yK + 1];
					board[b_xK][b_yK + 1] = b_king;
					board[b_xK][b_yK] = sq_empty;

					if (is_in_check())
					{
						board[b_xK][b_yK + 1] = current_piece;
						board[b_xK][b_yK] = b_king;
					}
					else
					{
						board[b_xK][b_yK + 1] = current_piece;
						board[b_xK][b_yK] = b_king;
						return false;
					}
				}
			}

		}

	}

	return false;
}


bool CGame::is_checkmate()
{

	int w_xK = 0, w_yK = 0, b_xK = 0, b_yK = 0;
		

	if (current_turn == white_owner)
	{

		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{
				if (board[i][j] == w_king)
				{
					w_xK = i;
					w_yK = j;
					break;
				}
			}
		}


		if (is_in_check())
		{
			if (w_xK - 1 != -1)
			{

				if (w_yK + 1 != size_c)
				{
					if (board[w_xK - 1][w_yK + 1] >= b_pawn && board[w_xK - 1][w_yK + 1] <= b_queen)
					{

						current_piece = board[w_xK - 1][w_yK + 1];
						board[w_xK - 1][w_yK + 1] = w_king;
						board[w_xK][w_yK] = sq_empty;

						if (is_in_check())
						{
							board[w_xK - 1][w_yK + 1] = current_piece;
							board[w_xK][w_yK] = w_king;
						}
						else
						{
							board[w_xK - 1][w_yK + 1] = current_piece;
							board[w_xK][w_yK] = w_king;
							return false;
						}

					}
				}


				if (w_yK - 1 != -1)
				{
					if (board[w_xK - 1][w_yK - 1] >= b_pawn && board[w_xK - 1][w_yK - 1] <= b_queen)
					{

						current_piece = board[w_xK - 1][w_yK - 1];
						board[w_xK - 1][w_yK - 1] = w_king;
						board[w_xK][w_yK] = sq_empty;

						if (is_in_check())
						{
							board[w_xK - 1][w_yK - 1] = current_piece;
							board[w_xK][w_yK] = w_king;
						}
						else
						{
							board[w_xK - 1][w_yK - 1] = current_piece;
							board[w_xK][w_yK] = w_king;
							return false;
						}

					}
				}


				if (board[w_xK - 1][w_yK] == sq_empty || (board[w_xK - 1][w_yK] >= b_pawn &&
					board[w_xK - 1][w_yK] <= b_queen))
				{

					current_piece = board[w_xK - 1][w_yK];
					board[w_xK - 1][w_yK] = w_king;
					board[w_xK][w_yK] = sq_empty;

					if (is_in_check())
					{
						board[w_xK - 1][w_yK] = current_piece;
						board[w_xK][w_yK] = w_king;
					}
					else
					{
						board[w_xK - 1][w_yK] = current_piece;
						board[w_xK][w_yK] = w_king;
						return false;
					}
					
				}

			}
			

			if (w_xK + 1 != size_r)
			{
				if (w_yK + 1 != size_c)
				{
					if (board[w_xK + 1][w_yK + 1] >= b_pawn && board[w_xK + 1][w_yK + 1] <= b_queen)
					{

						current_piece = board[w_xK + 1][w_yK + 1];
						board[w_xK + 1][w_yK + 1] = w_king;
						board[w_xK][w_yK] = sq_empty;

						if (is_in_check())
						{
							board[w_xK + 1][w_yK + 1] = current_piece;
							board[w_xK][w_yK] = w_king;
						}
						else
						{
							board[w_xK + 1][w_yK + 1] = current_piece;
							board[w_xK][w_yK] = w_king;
							return false;
						}

					}
				}


				if (w_yK - 1 != -1)
				{
					if (board[w_xK + 1][w_yK - 1] >= b_pawn && board[w_xK + 1][w_yK - 1] <= b_queen)
					{

						current_piece = board[w_xK + 1][w_yK - 1];
						board[w_xK + 1][w_yK - 1] = w_king;
						board[w_xK][w_yK] = sq_empty;

						if (is_in_check())
						{
							board[w_xK + 1][w_yK - 1] = current_piece;
							board[w_xK][w_yK] = w_king;
						}
						else
						{
							board[w_xK + 1][w_yK - 1] = current_piece;
							board[w_xK][w_yK] = w_king;
							return false;
						}

					}
				}


				if (board[w_xK + 1][w_yK] == sq_empty || (board[w_xK + 1][w_yK] >= b_pawn &&
					board[w_xK + 1][w_yK] <= b_queen))
				{
					current_piece = board[w_xK + 1][w_yK];
					board[w_xK + 1][w_yK] = w_king;
					board[w_xK][w_yK] = sq_empty;

					if (is_in_check())
					{
						board[w_xK + 1][w_yK] = current_piece;
						board[w_xK][w_yK] = w_king;
					}
					else
					{
						board[w_xK + 1][w_yK] = current_piece;
						board[w_xK][w_yK] = w_king;
						return false;
					}
				}

			}
			

			if (w_yK + 1 != size_c)
			{
				if (board[w_xK][w_yK + 1] == sq_empty || (board[w_xK][w_yK + 1] >= b_pawn &&
					board[w_xK][w_yK + 1] <= b_queen))
				{

					current_piece = board[w_xK][w_yK + 1];
					board[w_xK][w_yK + 1] = w_king;
					board[w_xK][w_yK] = sq_empty;

					if (is_in_check())
					{
						board[w_xK][w_yK + 1] = current_piece;
						board[w_xK][w_yK] = w_king;
					}
					else
					{
						board[w_xK][w_yK + 1] = current_piece;
						board[w_xK][w_yK] = w_king;
						return false;
					}

				}
			}


			if (w_yK - 1 != -1)
			{
				if (board[w_xK][w_yK - 1] == sq_empty || (board[w_xK][w_yK - 1] >= b_pawn &&
					board[w_xK][w_yK - 1] <= b_queen))
				{

					current_piece = board[w_xK][w_yK - 1];
					board[w_xK][w_yK - 1] = w_king;
					board[w_xK][w_yK] = sq_empty;

					if (is_in_check())
					{
						board[w_xK][w_yK - 1] = current_piece;
						board[w_xK][w_yK] = w_king;
					}
					else
					{
						board[w_xK][w_yK - 1] = current_piece;
						board[w_xK][w_yK] = w_king;
						return false;
					}
				}
			}
			

			return true;
		}


	}
	{


		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{
				if (board[i][j] == b_king)
				{
					b_xK = i;
					b_yK = j;
				}
			}
		}


		if (is_in_check())
		{
			if (b_xK - 1 != -1)
			{

				if(b_yK + 1 != size_c)
				{
					if (board[b_xK - 1][b_yK + 1] >= w_pawn && board[b_xK - 1][b_yK + 1] <= w_queen)
					{

						current_piece = board[b_xK - 1][b_yK + 1];
						board[b_xK - 1][b_yK + 1] = b_king;
						board[b_xK][b_yK] = sq_empty;

						if (is_in_check())
						{
							board[b_xK - 1][b_yK + 1] = current_piece;
							board[b_xK][b_yK] = b_king;
						}
						else
						{
							board[b_xK - 1][b_yK + 1] = current_piece;
							board[b_xK][b_yK] = b_king;
							return false;
						}

					}
				}


				if (b_yK - 1 != -1)
				{
					if (board[b_xK - 1][b_yK - 1] >= w_pawn && board[b_xK - 1][b_yK - 1] <= w_queen)
					{

						current_piece = board[b_xK - 1][b_yK - 1];
						board[b_xK - 1][b_yK - 1] = b_king;
						board[b_xK][b_yK] = sq_empty;

						if (is_in_check())
						{
							board[b_xK - 1][b_yK - 1] = current_piece;
							board[b_xK][b_yK] = b_king;
						}
						else
						{
							board[b_xK - 1][b_yK - 1] = current_piece;
							board[b_xK][b_yK] = b_king;
							return false;
						}

					}
				}


				if (board[b_xK - 1][b_yK] == sq_empty || (board[b_xK - 1][b_yK] >= w_pawn &&
					board[b_xK - 1][b_yK] <= w_queen))
				{
					current_piece = board[b_xK - 1][b_yK];
					board[b_xK - 1][b_yK] = b_king;
					board[b_xK][b_yK] = sq_empty;

					if (is_in_check())
					{
						board[b_xK - 1][b_yK] = current_piece;
						board[b_xK][b_yK] = b_king;
					}
					else
					{
						board[b_xK - 1][b_yK] = current_piece;
						board[b_xK][b_yK] = b_king;
						return false;
					}
				}

			}


			if (b_xK + 1 != size_r)
			{
				if (b_yK + 1 != size_c)
				{
					if (board[b_xK + 1][b_yK + 1] >= w_pawn && board[b_xK + 1][b_yK + 1] <= w_queen)
					{

						current_piece = board[b_xK + 1][b_yK + 1];
						board[b_xK + 1][b_yK + 1] = b_king;
						board[b_xK][b_yK] = sq_empty;

						if (is_in_check())
						{
							board[b_xK + 1][b_yK + 1] = current_piece;
							board[b_xK][b_yK] = b_king;
						}
						else
						{
							board[b_xK + 1][b_yK + 1] = current_piece;
							board[b_xK][b_yK] = b_king;
							return false;
						}

					}
				}


				if (b_yK - 1 != -1)
				{
					if (board[b_xK + 1][b_yK - 1] >= w_pawn && board[b_xK + 1][b_yK - 1] <= w_queen)
					{

						current_piece = board[b_xK + 1][b_yK - 1];
						board[b_xK + 1][b_yK - 1] = b_king;
						board[b_xK][b_yK] = sq_empty;

						if (is_in_check())
						{
							board[b_xK + 1][b_yK - 1] = current_piece;
							board[b_xK][b_yK] = b_king;
						}
						else
						{
							board[b_xK + 1][b_yK - 1] = current_piece;
							board[b_xK][b_yK] = b_king;
							return false;
						}

					}
				}


				if (board[b_xK + 1][b_yK] == sq_empty || (board[b_xK + 1][b_yK] >= w_pawn &&
					board[b_xK + 1][b_yK] <= w_queen))
				{
					current_piece = board[b_xK + 1][b_yK];
					board[b_xK + 1][b_yK] = b_king;
					board[b_xK][b_yK] = sq_empty;

					if (is_in_check())
					{
						board[b_xK + 1][b_yK] = current_piece;
						board[b_xK][b_yK] = b_king;
					}
					else
					{
						board[b_xK + 1][b_yK] = current_piece;
						board[b_xK][b_yK] = b_king;
						return false;
					}
				}

			}
			
			
			if (b_yK + 1 != size_c)
			{
				if (board[b_xK][b_yK + 1] == sq_empty || (board[b_xK][b_yK + 1] >= w_pawn &&
					board[b_xK][b_yK + 1] <= w_queen))
				{
					current_piece = board[b_xK][b_yK + 1];
					board[b_xK][b_yK + 1] = b_king;
					board[b_xK][b_yK] = sq_empty;

					if (is_in_check())
					{
						board[b_xK][b_yK + 1] = current_piece;
						board[b_xK][b_yK] = b_king;
					}
					else
					{
						board[b_xK][b_yK + 1] = current_piece;
						board[b_xK][b_yK] = b_king;
						return false;
					}

				}
			}

			if (b_yK - 1 != -1)
			{
				if (board[b_xK][b_yK - 1] == sq_empty || (board[b_xK][b_yK - 1] >= w_pawn &&
					board[b_xK][b_yK - 1] <= w_queen))
				{

					current_piece = board[b_xK][b_yK - 1];
					board[b_xK][b_yK - 1] = b_king;
					board[b_xK][b_yK] = sq_empty;

					if (is_in_check())
					{
						board[b_xK][b_yK - 1] = current_piece;
						board[b_xK][b_yK] = b_king;
					}
					else
					{
						board[b_xK][b_yK - 1] = current_piece;
						board[b_xK][b_yK] = b_king;
						return false;
					}

				}
			}
			

			return true;

		}
	}

	return false;

}


void CGame::game_play()
{



	cout << "\n\n\t\t\t\t\tC H E S S  -  G A M E\n\n";

	cout << "\n\tThis is game of chess, a recreational and competative board game played by two players.\n\t";
	cout << "The object of the game is to checkmate the opponent's king, whereby the king is under immediate attack\n\t(in 'check')";
	cout << "and there is no way to remove it from attack on the next move. There are also\n\tseveral ";
	cout << "ways a game can end in a draw.\n";
	cout << "\n\tChess is an abstract strategy game which involves no hidden information.\n\tIt is played on square ";
	cout << "chessboard with 64 squares arranged in an eight-by-eight grid. \n\n\t";

	cout << "\n\tPress <ENTER> to view the board\n";
	getchar();
	

	cout << "\n\tThe main board: \n";
	
	menu_board();

	cout << "\n\tAt the start, each player (one controlling the white pieces, the other\n\t";
	cout << "controlling the black pieces) controls sixteen pieces: one king, one queen,\n\t";
	cout << "two rooks, two knights, two bishops, and eight pawns" << "\n";


	cout << "\n\tPress <ENTER> to view the pieces\n";
	getchar();

	
	cout << "\n\tThe pieces (press <ENTER> to go trough each piece): \n\n";

	cout << "\n\tPawns:\n\n\t" << sq_white << " 'P'(white)\n\t" << sq_black << " 'p'(black)\n\n";
	cout << "\t'Pawns move vertically forward one square, with the option to move two squares if they\n\t";
	cout << "have not yet moved. Pawns capture one square diagonally in a forward direction.\n\t";
	cout << "Pawns are unable to move bachwards on captures or moves. Upon reaching the other side of the board\n\t";
	cout << "a pawn promotes in any other piece, except for a king.\n\n\t";
	cout << "Additionally, pawns can make a special move named 'En Passant'.'\n\n";

	cout << "\n\t<ENTER>";
	getchar();

	cout << "\n\n\tRooks:\n\n\t" << sq_white << " 'R'(white)\n\t" << sq_black << " 'r'(black)\n\n";

	cout << "\t'Rooks move horizontally or vertically any number of valid sqaures. They are unable to jump\n\t";
	cout << "over pieces.\n";
	cout << "\n\tRooks move when the king casles.'\n\n";

	cout << "\n\t<ENTER>";
	getchar();

	cout << "\n\n\tKnights:\n\n\t" << sq_white << " 'N'(white)\n\t" << sq_black << " 'n'(black)\n\n";
	cout << "\t'Knights move in an 'L' shape: two squares in a horizontal or vertical direction, then move\n\t";
	cout << "one square horizontally or vertically.\n\t";
	cout << "\n\tKnights are the only pieces able to jump over other pieces.'\n\n";

	cout << "\n\t<ENTER>";
	getchar();

	cout << "\n\n\tBishops:\n\n\t" << sq_white << " 'B'(white)\n\t" << sq_black << " 'b'(black)\n\n";
	cout << "\t'Bishops move diagonally any number of squares. They are unable to jump over pieces.'\n\n";

	cout << "\n\t<ENTER>";
	getchar();

	cout << "\n\n\tQueens:\n\n\t" << sq_white << " 'Q'(white)\n\t" << sq_black << " 'q'(black)\n\n";
	cout << "\t'Queens move diagonally, horizontally, or vertically any number of squares. They are unable\n";
	cout << "\tto jump over pieces.'\n\n";

	cout << "\n\t<ENTER>";
	getchar();

	cout << "\n\n\tKings:\n\n\t" << sq_white << " 'K'(white)\n\t" << sq_black << " 'k'(black)\n\n";
	cout << "\t'Kings move one square in any direction, so long as that square is not attacked\n\t";
	cout << "by an enemy piece.\n\n\tAdditionally, kings are able to make a special move, known as castling.'\n\n";

	cout << "\n\t<ENTER>";
	getchar();


	cout << "\n\n\tIn order to move a piece, the players should select the row and the column e.g. (B1, C2, etc. . .)";
	cout << "\n\tIf the piece is on the selected square, the players should point the destination square (A3, D5, etc. . .)";
	cout << "\n\tIf invalid square is selected, the player who`s turns is will be offered to re-try until\n\t";
	cout << "the destination square is valid!\n";

	
	cout << "\n\n\tThe player whose turn is can save the game by selecting (S) or can\n\t";
	cout << "quit to the main menu by selecting (Q).\n\n\t";
	cout << "\n\tIf the game is being saved upon playing, the players will still be able to continue to play until the game is exited.\n";
	

	cout << "\n\n\tEnjoy your game!\n\n\n";

	cout << "\n\tPress <ENTER> to begin the game\n\n";
	getchar();




	this->game_running = true;

	while (game_running)
	{
				
		if (!is_game_loaded)
		{
			cout << "\n\n\t\tNow select between the following: \n";
			cout << "\n\t\tNew (G)ame           ";
			cout << "\n\t\t(L)oad from file     ";
			cout << "\n\t\t(Q)uit game          ";

			cout << "\n\t> ";
			cin >> choice;

			while (toupper(choice) != 'G' && toupper(choice) != 'L' && 
				   toupper(choice) != 'Q')
			{
				cout << "\t\n'" << choice << "' cannot be valid choice. Try again> ";
				cin >> choice;
			}

		}

		is_new_game = true;

		

		if (toupper(choice) == 'G')
		{

			while (is_new_game)
			{

				if (!is_game_loaded)
				{
					set_board();
					print_score();
					print_save_exit();
					print_count_moves();
					print_board();

					current_turn = white_owner;
				}
				else
				{
					print_score();
					print_save_exit();
					print_count_moves();
					print_last_move();
					print_board();

					this->is_game_loaded = false;
				}


				game_over = false;

				while (!game_over)
				{

					if (is_game_over())
					{
						this->game_over = true;
						break;
					}


					if (current_turn == white_owner)
					{

						this->is_game_saved = false;

						this->is_game_quit = false;

						this->selected_start_sq = false;

						this->selected_end_sq = false;

						if (is_in_check())
						{
							cout << "\n\tWhite king in check!\n";
						}

						if (is_checkmate())
						{
							this->games_won_black += 1;
						}
						
						if (is_stalemate())
						{
							this->games_draw += 1;
						}

						cout << "\n\tThe white is on the move!\n";

						while (!selected_start_sq)
						{

							cout << "\n\tSelect your piece ('A1', 'B2', etc...)>\n";
							cin >> user_input;


							if (user_input.length() < 2 || user_input.length() > 2)
							{
								if (user_input.length() == 1)
								{
									if (toupper(user_input[0]) == 'S')
									{
										if (save_game())
										{
											cout << "\n\tThe game was saved successfully!\n";
											this->is_game_saved = true;

										}
										else
										{
											cout << "\n\tUnable to save game. Try again!\n";

										}
									}
									else if (toupper(user_input[0]) == 'Q')
									{
										cout << "\n\tYou have exited the game. Back to main. . .\n";
										this->is_game_quit = true;

									}
								}
								else
								{
									cout << "\n'" << user_input << "' cannot be a valid input. Try again.\n";
								}

							}
							else if (toupper(user_input[0]) < 'A' && toupper(user_input[0]) > 'H')
							{

								cout << "\n'" << user_input[0] << "' cannot be a valid column. Try again!\n";

							}
							else if (user_input[1] < '1' && user_input[1] > '8')
							{
								cout << "\n'" << user_input[1] << "' cannot be valid row. Try again!\n";
							}
							else
							{
								switch (toupper(user_input[0]))
								{
								case 'A':
									this->start_col_p = A;
									break;

								case 'B':
									this->start_col_p = B;
									break;

								case 'C':
									this->start_col_p = C;
									break;

								case 'D':
									this->start_col_p = D;
									break;

								case 'E':
									this->start_col_p = E;
									break;

								case 'F':
									this->start_col_p = F;
									break;

								case 'G':
									this->start_col_p = G;
									break;

								case 'H':
									this->start_col_p = H;
									break;

								}


								switch (user_input[1])
								{
								case '1':
									this->start_row_p = 8;
									break;

								case '2':
									this->start_row_p = 7;
									break;

								case '3':
									this->start_row_p = 6;
									break;

								case '4':
									this->start_row_p = 5;
									break;

								case '5':
									this->start_row_p = 4;
									break;

								case '6':
									this->start_row_p = 3;
									break;

								case '7':
									this->start_row_p = 2;
									break;

								case '8':
									this->start_row_p = 1;
									break;
								}
							}

							if (is_game_saved)
							{
								this->game_over = false;
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->current_turn = white_owner;
	
							}
							else if (is_game_quit)
							{
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->is_new_game = false;
								this->game_over = true;
								this->game_running = true;
								this->end_games_won_white = this->games_won_white;
								this->end_games_won_black = this->games_won_black;
								this->end_games_draw = this->games_draw;
								reset_score();
								clear_board();

								break;
							}
							else
							{
								if (is_piece_id_valid(current_turn, start_row_p, start_col_p))
									this->selected_start_sq = true;
								else
								{
									cout << "\n\tInvalid piece. Try again!\n";
								}
							}


						}


						while (!selected_end_sq)
						{

							this->last_move_white.clear();

							switch (get_piece(start_row_p, start_col_p))
							{
							case 1:
								cout << "\n\t'P' awn";
								this->last_move_white += "'P'_awn_to_";
								break;

							case 2:
								cout << "\n\t'R' ook";
								this->last_move_white += "'R'_ook_to_";
								break;

							case 3:
								cout << "\n\tK 'N' inght";
								this->last_move_white += "K_'N'_inght_to_";
								break;

							case 4:
								cout << "\n\t'B' ishop";
								this->last_move_white += "'B'_ishop_to_";
								break;

							case 5:
								cout << "\n\t'Q' ueen";
								this->last_move_white += "'Q'_ueen_to_";
								break;

							case 6:
								cout << "\n\t'K' ing";
								this->last_move_white += "'K'_ing_to_";
								break;
							}

							cout << " - where to ('A3', 'C5', etc...)>\n";
							cin >> user_input;


							if (user_input.length() < 2 || user_input.length() > 2)
							{
								if (user_input.length() == 1)
								{
									if (toupper(user_input[0]) == 'S')
									{
										if (save_game())
										{
											cout << "\n\tThe game was saved successfully!\n";
											this->is_game_saved = true;
										}
										else
										{
											cout << "\n\tUnable to save the game. Try again!\n";
										}

									}
									else if (toupper(user_input[0]) == 'Q')
									{
										cout << "\n\tYou have exited the game. Back to main. . .\n";
										this->is_game_quit = true;

									}

								}
								else
								{
									cout << "\n'" << user_input << "' cannot be a valid input. Try again.\n";
								}

							}
							else if (toupper(user_input[0]) < 'A' && toupper(user_input[0]) > 'H')
							{

								cout << "\n'" << user_input[0] << "' cannot be a valid column. Try again!\n";

							}
							else if (user_input[1] < '1' && user_input[1] > '8')
							{
								cout << "\n'" << user_input[1] << "' cannot be valid row. Try again!\n";
							}
							else
							{

								switch (toupper(user_input[0]))
								{
								case 'A':
									end_col_p = A;
									this->last_move_white += "A";
									break;

								case 'B':
									end_col_p = B;
									this->last_move_white += "B";
									break;

								case 'C':
									end_col_p = C;
									this->last_move_white += "C";
									break;

								case 'D':
									end_col_p = D;
									this->last_move_white += "D";
									break;

								case 'E':
									end_col_p = E;
									this->last_move_white += "E";
									break;

								case 'F':
									end_col_p = F;
									this->last_move_white += "F";
									break;

								case 'G':
									end_col_p = G;
									this->last_move_white += "G";
									break;

								case 'H':
									end_col_p = H;
									this->last_move_white += "H";
									break;

								}


								switch (user_input[1])
								{
								case '1':
									end_row_p = 8;
									this->last_move_white += "1";
									break;

								case '2':
									end_row_p = 7;
									this->last_move_white += "2";
									break;

								case '3':
									end_row_p = 6;
									this->last_move_white += "3";
									break;

								case '4':
									end_row_p = 5;
									this->last_move_white += "4";
									break;

								case '5':
									end_row_p = 4;
									this->last_move_white += "5";
									break;

								case '6':
									end_row_p = 3;
									this->last_move_white += "6";									
									break;

								case '7':
									end_row_p = 2;
									this->last_move_white += "7";
									break;

								case '8':
									end_row_p = 1;
									 adding the row to last_move_white
									this->last_move_white += "8";
									break;
								}
							}

							if (is_game_saved)
							{
								this->game_over = false;
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->current_turn = white_owner;

							}
							else if (is_game_quit)
							{
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->is_new_game = false;
								this->game_over = true;
								this->game_running = true;
								this->end_games_won_white = this->games_won_white;
								this->end_games_won_black = this->games_won_black;
								this->end_games_draw = this->games_draw;
								reset_score();
								clear_board();

								break;

							}
							else
							{

								if (get_piece(start_row_p, start_col_p) == w_pawn)
								{

									pawn = new Pawn(white_owner, get_piece_id());

									if (pawn->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == w_rook)
								{

									rook = new Rook(white_owner, get_piece_id());

									if (rook->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == w_knight)
								{

									knight = new Knight(white_owner, get_piece_id());

									if (knight->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == w_bishop)
								{

									bishop = new Bishop(white_owner, get_piece_id());

									if (bishop->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == w_queen)
								{

									queen = new Queen(white_owner, get_piece_id());

									if (queen->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == w_king)
								{


									king = new King(white_owner, get_piece_id());

									if ((end_row_p - 1 == 7 && end_col_p - 1 == 6) || 
										(end_row_p - 1 == 7 && end_col_p - 1 == 2))
									{

										this->count_castling_white += 1;

										if (this->count_castling_white < 2)
										{
											if (king->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
											{

												this->count_moves_white += 1;
												move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
												this->selected_end_sq = true;
												this->current_turn = black_owner;
											}
										}
										else
										{
											cout << "\n\tThe white king has already castled once!\n";
										}
									}
									else
									{
										if (king->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
										{

											this->count_moves_white += 1;
											move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
											this->selected_end_sq = true;
											this->current_turn = black_owner;
										}
									}

								}

							}

							if (!selected_end_sq)
							{
								this->selected_start_sq = false;
								break;
							}

						}


					}
					else if (current_turn == black_owner)
					{

						this->is_game_saved = false;

						this->is_game_quit = false;

						this->selected_start_sq = false;

						this->selected_end_sq = false;

						if (is_in_check())
						{
							cout << "\n\tBlack king in check!\n";
						}
						
						if (is_checkmate())
						{
							this->games_won_black += 1;
						}
						
						if (is_stalemate())
						{
							this->games_draw += 1;
						}

						cout << "\n\tThe black is on the move!\n";

						while (!selected_start_sq)
						{

							cout << "\n\tSelect your piece ('A8', 'B7', etc...)>\n";
							cin >> user_input;


							if (user_input.length() < 2 || user_input.length() > 2)
							{

								if (user_input.length() == 1)
								{
									if (toupper(user_input[0]) == 'S')
									{
										if (save_game())
										{
											cout << "\n\tThe game was saved successfully!\n";
											this->is_game_saved = true;
										}
										else
										{
											cout << "\n\tUnable to save the game. Try again!\n";
										}
									}
									else if (toupper(user_input[0]) == 'Q')
									{
										cout << "\n\tYou have exited the game. Back to main. . .\n";
										this->is_game_quit = true;

									}
								}
								else
								{
									cout << "\n'" << user_input << "' cannot be a valid input. Try again.\n";
								}

							}
							else if (toupper(user_input[0]) < 'A' && toupper(user_input[0]) > 'H')
							{

								cout << "\n'" << user_input[0] << "' cannot be a valid column. Try again!\n";

							}
							else if (user_input[1] < '1' && user_input[1] > '8')
							{
								cout << "\n'" << user_input[1] << "' cannot be valid row. Try again!\n";
							}
							else
							{
								switch (toupper(user_input[0]))
								{
								case 'A':
									this->start_col_p = A;
									break;

								case 'B':
									this->start_col_p = B;
									break;

								case 'C':
									this->start_col_p = C;
									break;

								case 'D':
									this->start_col_p = D;
									break;

								case 'E':
									this->start_col_p = E;
									break;

								case 'F':
									this->start_col_p = F;
									break;

								case 'G':
									this->start_col_p = G;
									break;

								case 'H':
									this->start_col_p = H;
									break;

								}


								switch (user_input[1])
								{
								case '1':
									this->start_row_p = 8;
									break;

								case '2':
									this->start_row_p = 7;
									break;

								case '3':
									this->start_row_p = 6;
									break;

								case '4':
									this->start_row_p = 5;
									break;

								case '5':
									this->start_row_p = 4;
									break;

								case '6':
									this->start_row_p = 3;
									break;

								case '7':
									this->start_row_p = 2;
									break;

								case '8':
									this->start_row_p = 1;
									break;
								}
							}

							if (is_game_saved)
							{
								this->game_over = false;
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->current_turn = black_owner;
							}
							else if (is_game_quit)
							{
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->is_new_game = false;
								this->game_over = true;
								this->game_running = true;
								this->end_games_won_white = this->games_won_white;
								this->end_games_won_black = this->games_won_black;
								this->end_games_draw = this->games_draw;
								reset_score();
								clear_board();

								break;
							}
							else
							{
								if (is_piece_id_valid(current_turn, start_row_p, start_col_p))
									this->selected_start_sq = true;
								else
								{
									cout << "\n\tInvalid piece. Try again!\n";
								}
							}

						}

						while (!selected_end_sq)
						{

							this->last_move_black.clear();

							switch (get_piece(start_row_p, start_col_p))
							{
							case 7:
								cout << "\n\t'p'_awn";
								this->last_move_black += "'p'_awn_to_";
								break;

							case 8:
								cout << "\n\t'r' ook";
								this->last_move_black += "'r'_ook_to_";
								break;

							case 9:
								cout << "\n\tk 'n' inght";
								this->last_move_black += "k_'n'_inght_to_";
								break;

							case 10:
								cout << "\n\t'b' ishop";
								this->last_move_black += "'b'_ishop_to_";
								break;

							case 11:
								cout << "\n\t'q' ueen";
								this->last_move_black += "'q'_ueen_to_";
								break;

							case 12:
								cout << "\n\t'k' ing";
								this->last_move_black += "'k'_ing_to_";
								break;
							}

							cout << " - where to ('C6', 'E5', etc...)>\n";
							cin >> user_input;



							if (user_input.length() < 2 || user_input.length() > 2)
							{

								if (user_input.length() == 1)
								{
									if (toupper(user_input[0]) == 'S')
									{
										if (save_game())
										{
											cout << "\n\tThe game was saved successfully!\n";
											this->is_game_saved = true;
										}
										else
										{
											cout << "\n\tUnable to save the game. Try again!\n";
										}
									}
									else if (toupper(user_input[0]) == 'Q')
									{
										cout << "\n\tYou have exited the game. Back to main. . .\n";
										this->is_game_quit = true;

									}
								}
								else
								{
									cout << "\n'" << user_input << "' cannot be a valid input. Try again.\n";
								}

							}
							else if (toupper(user_input[0]) < 'A' && toupper(user_input[0]) > 'H')
							{

								cout << "\n'" << user_input[0] << "' cannot be a valid column. Try again!\n";

							}
							else if (user_input[1] < '1' && user_input[1] > '8')
							{
								cout << "\n'" << user_input[1] << "' cannot be valid row. Try again!\n";
							}
							else
							{

								switch (toupper(user_input[0]))
								{
								case 'A':
									end_col_p = A;
									this->last_move_black += "A";
									break;

								case 'B':
									end_col_p = B;
									this->last_move_black += "B";
									break;

								case 'C':
									end_col_p = C;
									this->last_move_black += "C";
									break;

								case 'D':
									end_col_p = D;
									this->last_move_black += "D";
									break;

								case 'E':
									end_col_p = E;
									this->last_move_black += "E";
									break;

								case 'F':
									end_col_p = F;
									this->last_move_black += "F";
									break;

								case 'G':
									end_col_p = G;
									this->last_move_black += "G";
									break;

								case 'H':
									end_col_p = H;
									this->last_move_black += "H";
									break;

								}


								switch (user_input[1])
								{
								case '1':
									end_row_p = 8;
									this->last_move_black += "1";
									break;

								case '2':
									end_row_p = 7;
									this->last_move_black += "2";
									break;

								case '3':
									end_row_p = 6;
									this->last_move_black += "4";
									break;

								case '4':
									end_row_p = 5;
									this->last_move_black += "4";
									break;

								case '5':
									end_row_p = 4;
									this->last_move_black += "5";
									break;

								case '6':
									end_row_p = 3;
									this->last_move_black += "6";
									break;

								case '7':
									end_row_p = 2;
									this->last_move_black += "7";
									break;

								case '8':
									end_row_p = 1;
									this->last_move_black += "8";
									break;
								}
							}



							if (is_game_saved)
							{
								this->game_over = false;
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->current_turn = black_owner;

							}
							else if (is_game_quit)
							{
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->is_new_game = false;
								this->game_over = true;
								this->game_running = true;
								this->end_games_won_white = this->games_won_white;
								this->end_games_won_black = this->games_won_black;
								this->end_games_draw = this->games_draw;
								reset_score();
								clear_board();

								break;
							}
							else
							{

								if (get_piece(start_row_p, start_col_p) == b_pawn)
								{

									pawn = new Pawn(black_owner, get_piece_id());

									if (pawn->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == b_rook)
								{

									rook = new Rook(black_owner, get_piece_id());

									if (rook->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == b_knight)
								{

									knight = new Knight(black_owner, get_piece_id());

									if (knight->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == b_bishop)
								{

									bishop = new Bishop(black_owner, get_piece_id());

									if (bishop->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == b_queen)
								{

									queen = new Queen(black_owner, get_piece_id());

									if (queen->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								else if (get_piece(start_row_p, start_col_p) == b_king)
								{

									king = new King(black_owner, get_piece_id());

									if ((end_row_p - 1 == 0 && end_col_p - 1 == 6) ||
										(end_row_p - 1 == 0 && end_col_p - 1 == 2))
									{

										this->count_castling_black += 1;

										if (this->count_castling_black < 2)
										{
											if (king->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
											{
												this->count_moves_black += 1;
												move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
												this->selected_end_sq = true;
												this->current_turn = white_owner;
											}
											else
											{
												cout << "\n\tThe black king has already casletd once!\n";
											}
										}
									}
									else
									{
										if (king->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
										{
											this->count_moves_black += 1;
											move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
											this->selected_end_sq = true;
											this->current_turn = white_owner;
										}

									}

								}

							}

							if (!selected_end_sq)
							{
								selected_start_sq = false;
								break;
							}

						}
					}

				}

			}

		}
		else if (toupper(choice) == 'L')
		{
			
			if (load_game())
			{
				
				cout << "\n\tLoading. \n\tPress <Enter> to continue . . .\n";
				cin.ignore(10, '\n');

				getchar();

				choice = 'G';

				this->is_game_loaded = true;

			}
			else
			{
				cout << "\n\tNo saved games loacated. Try to save a game first.\n";
			}

		}
		else if(toupper(choice) == 'Q')
		{
			
			cout << "\n\n\n\n\n\n\n\tThe game`s over!\n";
			cout << "\n\n\tEnd score:\n\n\t\t\t\t\tWhite " << this->end_games_won_white << " : " << this->end_games_won_black << " Black\n";
			cout << "\t\t\t\t\t     Draw: " << this->end_games_draw << "\n";
			cout << "\n\n\tBetter luck next time!\n\n\n\n\n";
			exit(0);
		}


	}

}



bool CGame::is_piece_id_valid(int owner_turn, int startRow, int startCol)
{
	if (owner_turn == white_owner)
	{
		if (board[startRow - 1][startCol - 1] >= w_pawn && board[startRow - 1][startCol - 1] <= w_king)
		{
			return true;
		}
			return false;
	}
	else if (owner_turn == black_owner)
	{
		if (board[startRow - 1][startCol - 1] >= b_pawn && board[startRow - 1][startCol - 1] <= b_king)
		{
			return true;
		}
			return false;
	}

	return false;
}


void CGame::print_board()
{
	

	cout << "\n      A      B      C      D      E      F      G      H\n\n";


	int k_col = 0;


	for (int i = 0; i < size_r; ++i)
	{


		if (i % 2 == 0)
		{
			for (int j = 0; j < sq_height; ++j)
			{
				if (j == 1)
				{
					cout << size_r - i;
					cout << "  ";
				}
				else
					cout << "   ";

				for (int k = 0; k < (size_c / 2); ++k)
				{

					for (int sub_col = 0; sub_col < sq_lenght; ++sub_col)
					{

						if (sub_col == 3 && j == 1)
						{
							
							print_piece(0, i, k_col);
							++k_col;

							if (k_col == 8)
							{
								k_col = 0;
							}
							
						}
						else
						{
							cout << sq_white;
							
						}
					}

					for (int sub_col = 0; sub_col < sq_lenght; ++sub_col)
					{


						if (sub_col == 3 && j == 1)
						{
							
							print_piece(1, i, k_col);
							++k_col;

							if (k_col == 8)
							{
								k_col = 0;
							}
														
						}
						else
						{
							cout << sq_black;
							
						}
							
					}
				}

				cout << '\n';
			}
		}
		else
		{
			for (int j = 0; j < sq_height; ++j)
			{
				if (j == 1)
				{
					cout << size_r - i;
					cout << "  ";
				}
				else
					cout << "   ";

				for (int k = 0; k < (size_c / 2); ++k) 
				{
					for (int sub_col = 0; sub_col < sq_lenght; ++sub_col)
					{


						if (sub_col == 3 && j == 1)
						{
							print_piece(1, i, k_col);
							++k_col;

							if (k_col == 8)
							{
								k_col = 0;
							}
							
							
						}
						else
						{
							cout << sq_black;
							
						}
							
					}

					for (int sub_col = 0; sub_col < sq_lenght; ++sub_col)
					{

						
						if (sub_col == 3 && j == 1)
						{

							print_piece(0, i, k_col);
							++k_col;

							if (k_col == 8)
							{
								k_col = 0;
							}
							
							
						}
						else
						{
							cout << sq_white;
							
						}
							
					}
				}

				cout << '\n';
			}
		}

	}

	cout << "\n      A      B      C      D      E      F      G      H\n\n";


}




void CGame::menu_board()
{
	cout << "\n    A    B   C   D   E   F   G   H\n\n";


	for (int i = 0; i < size_r; ++i)
	{


		if (i % 2 == 0)
		{
			for (int j = 0; j < 2; ++j)
			{
				if (j == 1)
				{
					cout << size_r - i;
					cout << "  ";
				}
				else
					cout << "   ";

				for (int k = 0; k < (size_c / 2); ++k)
				{

					for (int sub_col = 0; sub_col < 4; ++sub_col)
					{
						cout << sq_white;
					}

					for (int sub_col = 0; sub_col < 4; ++sub_col)
					{
						cout << sq_black;

					}
				}

				cout << '\n';
			}
		}
		else
		{
			for (int j = 0; j < 2; ++j)
			{
				if (j == 1)
				{
					cout << size_r - i;
					cout << "  ";
				}
				else
					cout << "   ";

				for (int k = 0; k < (size_c / 2); ++k)
				{
					for (int sub_col = 0; sub_col < 4; ++sub_col)
					{
						cout << sq_black;
					}

					for (int sub_col = 0; sub_col < 4; ++sub_col)
					{
						cout << sq_white;

					}
				}

				cout << '\n';
			}
		}

	}

	cout << "\n    A    B   C   D   E   F   G   H\n\n";
}




bool CGame::is_game_over()
{

	bool is_white_king_on_board = false;

	bool is_black_king_on_board = false;

	for (int i = 0; i < size_r; ++i)
	{
		for (int j = 0; j < size_c; ++j)
		{
			if (board[i][j] == 6)
			{
				is_white_king_on_board = true;
				break;
			}
		}
	}
	
	for (int i = 0; i < size_r; ++i)
	{
		for (int j = 0; j < size_c; ++j)
		{
			if (board[i][j] == 12)
			{
				is_black_king_on_board = true;
				break;
			}
		}
	}

	if (!is_white_king_on_board)
	{
		cout << "\n\tThe white king is captured. The black won the game!\n";
		this->games_won_black += 1;
		this->is_new_game = new_game();
		return true;
	}
	else if (!is_black_king_on_board)
	{
		cout << "\n\tThe black king is captured. The white won the game!\n";
		this->games_won_white += 1;
		this->is_new_game = new_game();
		return true;
	}
	else if (is_checkmate())
	{
		if (current_turn == white_owner)
		{
			cout << "\nWhite king checkmate!\n";
			cout << "\nThe black won the game!\n";
			this->games_won_black += 1;
			this->is_new_game = new_game();
			return true;
		}
		else if(current_turn == black_owner)
		{
			cout << "\nBlack king checkmate!\n";
			cout << "\nThe white won the game!\n";
			this->games_won_white += 1;
			this->is_new_game = new_game();
			return true;
		}
	}
	else if (is_stalemate())
	{
		cout << "\n\tStalemate! The game is draw!\n";
		this->is_new_game = new_game();
		this->games_draw += 1;
		return true;
	}

	return false;
}


bool CGame::new_game()
{
	char yes_no = ' ';

	cout << "\n\tNew Game?(y/n)> ";
	cin >> yes_no;

	while (tolower(yes_no) != 'y' && tolower(yes_no) != 'n')
	{
		cout << "\n\t" << yes_no << " cannot be a valid input. Try again> ";
		cin >> yes_no;
	}

	if (tolower(yes_no) == 'y')
	{
		this->count_moves_white = 0;
		this->count_moves_black = 0;
		this->choice = 'G';
		this->current_turn = white_owner;
		clear_board();

		return true;
	}
	
	this->end_games_won_white = this->games_won_white;

	this->end_games_won_black = this->games_won_black;
		
	reset_score();


	cout << "\n\tBack to main!";
	cin.ignore(10, '\n');
	clear_board();

	cout << "\n\tPress <Enter> to continue. . . ";
	getchar();

	return false;
	

}



bool CGame::save_game()
{

	ofstream save_game;

	save_game.open("CHess_C_save_game.txt");

	if (save_game.fail())
	{
		cout << "\n\tFailed to save the game. Try again!\n";
	}
	else
	{

		save_game << current_turn << '\n';
		save_game << games_won_white << '\n';
		save_game << games_won_black << '\n';
		save_game << games_draw << '\n';
		save_game << count_moves_white << '\n';
		save_game << count_moves_black << '\n';
		save_game << last_move_white << '\n';
		save_game << last_move_black << '\n';
		save_game << count_castling_white << '\n';
		save_game << count_castling_black << '\n';

		


		for (int i = 0; i < 8; ++i)
		{
			for (int j = 0; j < 8; ++j)
			{
				save_game << board[i][j] << '\n';
			}
		}
		return true;
	}

	return false;
}


bool CGame::load_game()
{

	ifstream load_game;
	
	load_game.open("CHess_C_save_game.txt");

	if (load_game.is_open())
	{

		int current_turn_load = 0;
		int games_won_white_load = 0;
		int games_won_black_load = 0;
		int games_draw_load = 0;
		int count_moves_white_load = 0;
		int count_moves_black_load = 0;
		string last_move_white_load = " ";
		string last_move_black_load = " ";
		int count_castling_white_load = 0;
		int count_castling_black_load = 0;


		load_game >> current_turn_load;
		load_game >> games_won_white_load;
		load_game >> games_won_black_load;
		load_game >> games_draw_load;
		load_game >> count_moves_white_load;
		load_game >> count_moves_black_load;
		load_game >> last_move_white_load;
		load_game >> last_move_black_load;
		load_game >> count_castling_white_load;
		load_game >> count_castling_black_load;


		current_turn = current_turn_load;
		games_won_white = games_won_white_load;
		games_won_black = games_won_black_load;
		games_draw = games_draw_load;
		count_moves_white = count_moves_white_load;
		count_moves_black = count_moves_black_load;
		last_move_white = last_move_white_load;
		last_move_black = last_move_black_load;
		count_castling_white = count_castling_white_load;
		count_castling_black = count_castling_black_load;

		



		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{
				load_game >> board[i][j];

			}
		}
		

		return true;
		
	}

	return false;
}


void CGame::clear_board()
{
	for (int i = 0; i < size_r; ++i)
	{
		for (int j = 0; j < size_c; ++j)
		{
			board[i][j] = 0;
		}
	}
}


CGame::~CGame()
{
	delete pawn;
	delete rook;
	delete knight;
	delete bishop;
	delete queen;
	delete king;
}


