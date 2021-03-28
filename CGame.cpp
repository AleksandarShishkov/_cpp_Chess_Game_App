#include "CGame.h"




CGame::CGame()
{

}


void CGame::set_board()
{


	
	// placing the white pieces on the board
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


	// placing the black pieces on the board
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


	// setting the rest of the squares to sq_empty
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

	// validating the pawns movement
	if (board[startRow - 1][startCol - 1] == 1 || board[startRow - 1][startCol - 1] == 7)
	{

		// validating pawn promotion
		if (pawn->pawn_promotion(startRow, startCol, endRow, endCol, board))
		{
			board[startRow - 1][startCol - 1] = sq_empty;
		}
		// validating white pawn`s en_passant
		else if (board[startRow - 1][startCol - 1] == 1 && pawn->is_pawn_en_passant())
		{
			
			board[startRow - 1][startCol - 1] = sq_empty;
			// adding the captured piece to last_move_white
			this->last_move_white += "_/_captures_black_'p'_awn";
			board[endRow - 1][endCol - 1] = get_piece_id();
			
		}
		// validating the black pawn`s en_passant
		else if (board[startRow - 1][startCol - 1] == 7 && pawn->is_pawn_en_passant())
		{
			board[startRow - 1][startCol - 1] = sq_empty;
			// adding the captured piece to last_move_black
			this->last_move_black += "_/_captures_white_'P'_awn";

			board[endRow - 1][endCol - 1] = get_piece_id();

		}
		// validating the standard pawn movement
		else
		{
			board[startRow - 1][startCol - 1] = sq_empty;
			
			// if white pawn is captured
			if (board[endRow - 1][endCol - 1] == 1)
			{
				// adding the captured piece to last_move_black
				this->last_move_black += "_/_captures_white_'P'_awn";
			}
			// if white rook is captured
			else if (board[endRow - 1][endCol - 1] == 2)
			{
				// adding the captured piece to last_move_black
				this->last_move_black += "_/_captures_white_'R'_ook";
			}
			// if white knight is captured
			else if (board[endRow - 1][endCol - 1] == 3)
			{
				// adding the captured piece to last_move_black
				this->last_move_black += "_/_captures_white_K_'N'_ight";
			}
			// if white bishop is captured
			else if (board[endRow - 1][endCol - 1] == 4)
			{
				// adding the captured piece to last_move_black
				this->last_move_black += "_/_captures_white_'B'_ishop";
			}
			// if white queen is captured
			else if (board[endRow - 1][endCol - 1] == 5)
			{
				// adding the captured piece to last_move_black
				this->last_move_black += "_/_captures_white_'Q'_ueen";
			}
			// if white king is captured
			else if (board[endRow - 1][endCol - 1] == 6)
			{
				// adding the captured piece to last_move_black
				this->last_move_black += "_/_captures_white_'K'_intg";
			}
			// if black pawn is captured
			else if (board[endRow - 1][endCol - 1] == 7)
			{
				// adding the captured piece to last_move_white
				this->last_move_white += "_/_captures_black_'p'_awn";
			}
			// if black rook is captured
			else if (board[endRow - 1][endCol - 1] == 8)
			{
				// adding the captured piece to last_move_white
				this->last_move_white += "_/_captures_black_'r'_ook";
			}
			// if black knight is captured
			else if (board[endRow - 1][endCol - 1] == 9)
			{
				// adding the captured piece to last_move_white
				this->last_move_white += "_/_captures_black_k_'n'_ight";
			}
			// if black bishop is captured
			else if (board[endRow - 1][endCol - 1] == 10)
			{
				// adding the captured piece to last_move_white
				this->last_move_white += "_/_captures_black_'b'_ishop";
			}
			// if black queen is captured
			else if (board[endRow - 1][endCol - 1] == 11)
			{
				// adding the captured piece to last_move_white
				this->last_move_white += "_/_captures_black_'q'_een";
			}
			// if black king is captured
			else if (board[endRow - 1][endCol - 1] == 12)
			{
				// adding the captured piece to last_move_white
				this->last_move_white += "_/_captures black_'k'_ing";
			}

			board[endRow - 1][endCol - 1] = get_piece_id();

		}

	}
	// validating the white king`s casling on the right
	else if (board[startRow - 1][startCol - 1 == w_king] && endRow - 1 == 7 && endCol - 1 == 6)
	{
		board[startRow - 1][startCol - 1] = sq_empty;
	}
	// validating the white king`s castling on the left
	else if (board[startRow - 1][startCol - 1] == w_king && endRow - 1 == 7 && endCol - 1 == 2)
	{
		board[startRow - 1][startCol - 1] = sq_empty;
	}
	// validating the black king`s castlig on the right
	else if (board[startRow - 1][startCol - 1] == b_king && endRow - 1 == 0 && endCol - 1 == 6)
	{
		board[startRow - 1][startCol - 1] = sq_empty;
	}
	// validating the black king`s caslitng on the left
	else if(board[startRow - 1][startCol - 1] == b_king && endRow - 1 == 0 && endCol - 1 == 2)
	{
		board[startRow - 1][startCol - 1] = sq_empty;
	}
	// validating the movement of the rest of the pieces
	else
	{

		board[startRow - 1][startCol - 1] = sq_empty;

		// if white pawn is captured
		if (board[endRow - 1][endCol - 1] == 1)
		{
			// adding the captured piece to last_move_black
			this->last_move_black += "_/_captures_white_'P'_awn";
		}
		// if white rook is captured
		else if (board[endRow - 1][endCol - 1] == 2)
		{
			// adding the captured piece to last_move_black
			this->last_move_black += "_/_captures_white_'R'_ook";
		}
		// if white knight is captured
		else if (board[endRow - 1][endCol - 1] == 3)
		{
			// adding the captured piece to last_move_black
			this->last_move_black += "_/_captures_white_K_'N'_ight";
		}
		// if white bishop is captured
		else if (board[endRow - 1][endCol - 1] == 4)
		{
			// adding the captured piece to last_move_black
			this->last_move_black += "_/_captures_white_'B'_ishop";
		}
		// if white queen is captured
		else if (board[endRow - 1][endCol - 1] == 5)
		{
			// adding the captured piece to last_move_black
			this->last_move_black += "_/_captures_white_'Q'_ueen";
		}
		// if white king is captured
		else if (board[endRow - 1][endCol - 1] == 6)
		{
			// adding the captured piece to last_move_black
			this->last_move_black += "_/_captures_white_'K'_intg";
		}
		// if black pawn is captured
		else if (board[endRow - 1][endCol - 1] == 7)
		{
			// adding the captured piece to last_move_white
			this->last_move_white += "_/_captures_black_'p'_awn";
		}
		// if black rook is captured
		else if (board[endRow - 1][endCol - 1] == 8)
		{
			// adding the captured piece to last_move_white
			this->last_move_white += "_/_captures_black_'r'_ook";
		}
		// if black knight is captured
		else if (board[endRow - 1][endCol - 1] == 9)
		{
			// adding the captured piece to last_move_white
			this->last_move_white += "_/_captures_black_k_'n'_ight";
		}
		// if black bishop is captured
		else if (board[endRow - 1][endCol - 1] == 10)
		{
			// adding the captured piece to last_move_white
			this->last_move_white += "_/_captures_black_'b'_ishop";
		}
		// if black queen is captured
		else if (board[endRow - 1][endCol - 1] == 11)
		{
			// adding the captured piece to last_move_last
			this->last_move_white += "_/_captures_black_'q'_een";
		}
		// if black king is captured
		else if (board[endRow - 1][endCol - 1] == 12)
		{
			//adding the captured piece to last_move_white
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

	// if the piece is a white pawn
	if (board[row - 1][col - 1] == w_pawn)
	{
		this->piece_id = 1;
		return get_piece_id();
	}
	// if the piece is a white rook
	else if (board[row - 1][col - 1] == w_rook)
	{
		this->piece_id = 2;
		return get_piece_id();
	}
	// if the piece is a white knight
	else if (board[row - 1][col - 1] == w_knight)
	{
		this->piece_id = 3;
		return get_piece_id();
	}
	// if the piece is a white bishop
	else if (board[row - 1][col - 1] == w_bishop)
	{
		this->piece_id = 4;
		return get_piece_id();
	}
	// if the piece is a white queen
	else if (board[row - 1][col - 1] == w_queen)
	{
		this->piece_id = 5;
		return get_piece_id();
	}
	// if the piece is a white king
	else if (board[row - 1][col - 1] == w_king)
	{
		this->piece_id = 6;
		return get_piece_id();
	}
	// if the piece is a black pawn
	else if (board[row - 1][col - 1] == b_pawn)
	{
		this->piece_id = 7;
		return get_piece_id();
	}
	// if the piece is a black rook
	else if (board[row - 1][col - 1] == b_rook)
	{
		this->piece_id = 8;
		return get_piece_id();
	}
	// if the piece is a black knight
	else if (board[row - 1][col - 1] == b_knight)
	{
		this->piece_id = 9;
		return get_piece_id();
	}
	// if the piece is a black bishop
	else if (board[row - 1][col - 1] == b_bishop)
	{
		this->piece_id = 10;
		return get_piece_id();
	}
	// if the piece is a black queen
	else if (board[row - 1][col - 1] == b_queen)
	{
		this->piece_id = 11;
		return get_piece_id();
	}
	// if the piece is a black king
	else if (board[row - 1][col - 1] == b_king)
	{
		this->piece_id = 12;
		return get_piece_id();
	}

	return 0;
}


bool CGame::is_in_check()
{
	// integers for the kings 'x' and 'y' coordiantes
	int w_xK = 0, w_yK = 0, b_xK = 0, b_yK = 0;

	// boolean for the empty squares
	bool is_sq_empty;

	// if it`s white owner`s turn
	if (current_turn == white_owner)
	{

		// locating the white king on the board
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


		// locating the black owner`s pieces
		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{

				// setting is_sq_empty to true
				is_sq_empty = true;

				// if the piece is a black pawn
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
				// if the piece is a black rook
				else if (board[i][j] == b_rook)
				{

					// integer to hold the rows between the start and the end positions
					int b_rook_n_row = 0;


					// integer to hold the columns between the start and the end positions
					int b_rook_n_col = 0;


					// validating if the upper squares on the column are empty
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


					// validating if the lower squares on the column are empty
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


					// validating if the right squares on the row are empty
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


					// validating if the left squares on the row are empty
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
				// if the piece is a black knight
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
				// if the piece is a black bishop
				else if (board[i][j] == b_bishop)
				{

					// integer to hold the rows between the starting and the ending positions
					int b_bishop_n_rows = 0;




					// validating the lower right diagonal
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


					// validating the upper right diagonal
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


					// validating the lower left diagonal
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


					// validating the upper left diagonal
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
				// if the piece is a black queen
				else if (board[i][j] == b_queen)
				{

					// integer to hold the rows between the starting and the ending rows
					int b_queen_n_rows = 0;

					// integer to hold the columns bewteen the starting and the ending columns
					int b_queen_n_cols = 0;


					// validating if the upper squares on the column are empty
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


					// validating if the lower squares on the column are empty
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


					// validating if the right squares on the row are empty
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


					// validating if the left squares on the row are empty
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


					// validating the lower right diagonal
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


					// validating the upper right diagonal
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


					// validating the lower left diagonal
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


					// validating the upper left diagonal
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
	// if it`s black owner`s turn
	else if (current_turn == black_owner)
	{

		// locating the black king on the board
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


		// locating the white owner`s pieces
		for (int i = 0; i < size_r; ++i)
		{
			for (int j = 0; j < size_c; ++j)
			{

				// setting is_sq_empty to true
				is_sq_empty = true;

				// if the piece is a white pawn
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
				// if the piece is a white rook
				else if (board[i][j] == w_rook)
				{


					// integer to hold the rows between the starting and the ending rows
					int w_rook_n_row = 0;

					// integer to hold the columns betweent the starting and the ending columns
					int w_rook_n_col = 0;



					// validating if the upper squares on the column are empty
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


					// validating if the lower squares on the column are empty
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


					// validating if the right squares on the row are empty
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


					// validating if the left squares on the row are empty
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
				// if the piece is a white knight
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
				// if the piece is a white bishop
				else if (board[i][j] == w_bishop)
				{

					// integer to hold the rows between the starting and the ending positions
					int w_bishop_n_rows = 0;



					// validating the lower right diagonal
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


					// validating the upper right diagonal
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


					// validating the lower left diagonal
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


					// validating the upper left diagonal
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
				// if the piece is a white queen
				else if (board[i][j] == w_queen)
				{


					// integer to hold the number of the rows
					int w_queen_n_rows = 0;

					// integer to hold the number of the columns
					int w_queen_n_cols = 0;



					// validating if the upper squares on the column are empty
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


					// validating if the lower squares on the column are empty
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


					// validating if the right squares on the row are empty
					if (i == b_xK && j < b_yK)
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


					// validating if the left squares on the row are empty
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


					// validating the lower right diagonal
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



					// validating the upper right diagonal
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


					// validating the lower left diagonal
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


					// validating the upper left diagonal
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
	
	// integers kings 'x' and 'y' coordinates
	int w_xK = 0, w_yK = 0, b_xK = 0, b_yK = 0;
	
	
	// if it`s white owner`s turn
	if (current_turn == white_owner)
	{

		// locating the white king on the board
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



		// if the white king isn`t in check
		if (!is_in_check())
		{

			// validating the upper row
			if (w_xK - 1 != -1)
			{

				// validating the current column
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


				// validating the current column - 1
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


				// validating the current column + 1
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


			// validating the lower row
			if (w_xK + 1 != size_r)
			{
				// validating the same column on the lower row
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


				// validating the column -1
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


				// validating the column +1
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
			
			
		// validating the current row
			// validating the column -1
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


			// validating the column + 1
			if (w_yK + 1 != size_c)
			{
				if (board[w_xK][w_yK + 1] == sq_empty || (board[w_xK][w_yK + 1] >= b_pawn &&
					board[w_xK][w_yK + 1] <= b_queen))
				{
					current_piece = board[w_xK][w_yK + 1];
					board[w_xK][w_yK + 1] = w_king;
					board[w_xK][w_yK] = sq_empty;

					// validating the column +1
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
	// if it`s black`s turn
	else if (current_turn == black_owner)
	{

		// loacting the black king on the board
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

		
		// if the black king insn`t in check
		if (!is_in_check())
		{

			// validating the upper row
			if (b_xK - 1 != -1)
			{

				// validating the current column
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


				// validating the current column - 1
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


				// validating the current column + 1
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
			
			
			// validating the lower row
			if (b_xK + 1 < size_r)
			{
				// validating the current column on row +1
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


				// validating the column -1
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


				// validating the column +1
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


		// validating the same row
			// validating the coumn -1
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


			// validating the column +1
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

	// integers for the kings 'x' and 'y' coordinates
	int w_xK = 0, w_yK = 0, b_xK = 0, b_yK = 0;
		

	// if it`s white owner`s turn
	if (current_turn == white_owner)
	{

		// locating the white king on the board
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


		// if the white king`s in check
		if (is_in_check())
		{
			// validating the upper row
			if (w_xK - 1 != -1)
			{

				// validating the current column + 1
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


				// validating the current column - 1
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


				// validating the current column
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
			

			// validating the lower row
			if (w_xK + 1 != size_r)
			{
				// validating the current column + 1
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


				// validating the current column - 1
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


				// validating the current column
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
			

			// validating the current row
			// validating the current column + 1
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


			// validating the current column - 1
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
	// if it`s black owner`s turn
	else if (current_turn == black_owner)
	{


		// locating the black king on the board
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


		// if the black king`s in check
		if (is_in_check())
		{
			// validating the upper row
			if (b_xK - 1 != -1)
			{

				// validating the current column + 1
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


				// validating the current column - 1
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


				// validating the current column
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


			// validating the lower row
			if (b_xK + 1 != size_r)
			{
				// validating the current column + 1
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


				// validating the current column - 1
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


				// validating the current column
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
			
			
			// validating the current row
			// validating the current column + 1
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

			// validating the current column - 1
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


	// the main message

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
	
	// displaying the main board
	menu_board();

	cout << "\n\tAt the start, each player (one controlling the white pieces, the other\n\t";
	cout << "controlling the black pieces) controls sixteen pieces: one king, one queen,\n\t";
	cout << "two rooks, two knights, two bishops, and eight pawns" << "\n";


	cout << "\n\tPress <ENTER> to view the pieces\n";
	getchar();

	
	// displaying the pieces
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


	// message for the controls
	cout << "\n\n\tIn order to move a piece, the players should select the row and the column e.g. (B1, C2, etc. . .)";
	cout << "\n\tIf the piece is on the selected square, the players should point the destination square (A3, D5, etc. . .)";
	cout << "\n\tIf invalid square is selected, the player who`s turns is will be offered to re-try until\n\t";
	cout << "the destination square is valid!\n";

	
	// message for the S/Q options while in-game
	cout << "\n\n\tThe player whose turn is can save the game by selecting (S) or can\n\t";
	cout << "quit to the main menu by selecting (Q).\n\n\t";
	cout << "\n\tIf the game is being saved upon playing, the players will still be able to continue to play until the game is exited.\n";
	

	cout << "\n\n\tEnjoy your game!\n\n\n";

	cout << "\n\tPress <ENTER> to begin the game\n\n";
	getchar();



	// main menu

	// setting game_running to true
	this->game_running = true;

	// the main game-loop
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

			// validating the choice
			while (toupper(choice) != 'G' && toupper(choice) != 'L' && 
				   toupper(choice) != 'Q')
			{
				cout << "\t\n'" << choice << "' cannot be valid choice. Try again> ";
				cin >> choice;
			}

		}

		// setting is_new_game to true
		is_new_game = true;

		
		// the inner game-loop

		// if new game is selected
		if (toupper(choice) == 'G')
		{

			while (is_new_game)
			{

				// validating if the game was loaded
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


				// setting game_over to false
				game_over = false;

				while (!game_over)
				{

					// validating if the game is over, assigning the result to game_over
					if (is_game_over())
					{
						this->game_over = true;
						break;
					}


					// if the white is on the move
					if (current_turn == white_owner)
					{

						// setting is_game_saved to false
						this->is_game_saved = false;

						// setting is_game_quit to false
						this->is_game_quit = false;

						// setting selected_start_sq to false
						this->selected_start_sq = false;

						// setting selected_end_sq to false
						this->selected_end_sq = false;

						// validating if the white king is in check
						if (is_in_check())
						{
							cout << "\n\tWhite king in check!\n";
						}

						// validating if the white king`s checkmate
						if (is_checkmate())
						{
							this->games_won_black += 1;
						}
						
						// validating if the game is draw
						if (is_stalemate())
						{
							this->games_draw += 1;
						}

						cout << "\n\tThe white is on the move!\n";

						// validating the starting square
						while (!selected_start_sq)
						{

							cout << "\n\tSelect your piece ('A1', 'B2', etc...)>\n";
							cin >> user_input;


							// if the lenght is invalid printing error message
							if (user_input.length() < 2 || user_input.length() > 2)
							{
								// validating if the selected option is 'S' or 'Q'
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
							// else validating the starting row and column
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
								// switching user_input[0], assigning the value to start_col_p
								switch (toupper(user_input[0]))
								{
								// if the column is 'A'
								case 'A':
									// setting start_col_p to A
									this->start_col_p = A;
									break;

								// if the column is 'B'
								case 'B':
									// setting start_col_p to B
									this->start_col_p = B;
									break;

								// if the column is 'C'
								case 'C':
									// setting start_col_p to C
									this->start_col_p = C;
									break;

								// if the column is 'D'
								case 'D':
									// setting start_col_p to D
									this->start_col_p = D;
									break;

								// if the column is 'E'
								case 'E':
									// setting start_col_p to E
									this->start_col_p = E;
									break;

								// if the column is 'F'
								case 'F':
									// setting start_col_p to F
									this->start_col_p = F;
									break;

								// if the column is 'G'
								case 'G':
									// setting start_col_p to G
									this->start_col_p = G;
									break;

								// if the column is 'H'
								case 'H':
									// setting start_col_p to H
									this->start_col_p = H;
									break;

								}


								// swithing user_input[1], assigning the value to start_row_p
								switch (user_input[1])
								{
								// if the row is '1'
								case '1':
									// setting start_row_p to 8
									this->start_row_p = 8;
									break;

								// if the row is '2'
								case '2':
									// setting start_row_p to 7
									this->start_row_p = 7;
									break;

								// if the row is '3'
								case '3':
									// setting start_row_p to 6
									this->start_row_p = 6;
									break;

								// if the row is '4'
								case '4':
									// setting start_row_p to 5
									this->start_row_p = 5;
									break;

								// if the row is '5'
								case '5':
									// setting start_row_p to 4
									this->start_row_p = 4;
									break;

								// if the row is '6'
								case '6':
									// setting start_row_p to 3
									this->start_row_p = 3;
									break;

								// if the row is '7'
								case '7':
									// setting start_row_p to 2
									this->start_row_p = 2;
									break;

								// if the row is '8'
								case '8':
									// setting start_row_p to 1
									this->start_row_p = 1;
									break;
								}
							}

							// validating if the game was saved
							if (is_game_saved)
							{
								this->game_over = false;
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->current_turn = white_owner;
	
							}
							// validating if the game was exited
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
							// validating the selected piece
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


						// validating the destination square
						while (!selected_end_sq)
						{

							// re-setting the counter for the white owner`s previous move
							this->last_move_white.clear();

							switch (get_piece(start_row_p, start_col_p))
							{
							// if the piece is a white pawn
							case 1:
								cout << "\n\t'P' awn";
								// adding the piece to last_move_white
								this->last_move_white += "'P'_awn_to_";
								break;

							// if the piece is a white rook
							case 2:
								cout << "\n\t'R' ook";
								// adding the piece to last_move_white
								this->last_move_white += "'R'_ook_to_";
								break;

							// if the piece is a white knight
							case 3:
								cout << "\n\tK 'N' inght";
								// adding the piece to last_move_white
								this->last_move_white += "K_'N'_inght_to_";
								break;

							// if the piece is a white bishop
							case 4:
								cout << "\n\t'B' ishop";
								// adding the piece to ast_move_white
								this->last_move_white += "'B'_ishop_to_";
								break;

							// if the piece is a white queen
							case 5:
								cout << "\n\t'Q' ueen";
								// adding the piece to last_move_white
								this->last_move_white += "'Q'_ueen_to_";
								break;

							// if the piece is a white king
							case 6:
								cout << "\n\t'K' ing";
								// adding the piece to last_move_white
								this->last_move_white += "'K'_ing_to_";
								break;
							}

							cout << " - where to ('A3', 'C5', etc...)>\n";
							cin >> user_input;


							// if the lenght is invalid printing error message
							if (user_input.length() < 2 || user_input.length() > 2)
							{
								// validating if the selected option is 'S' or 'Q'
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
							// else validating the destination row and column
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

								// switching user_input[0], assigning the valur to end_col_p
								switch (toupper(user_input[0]))
								{
								// if the column is 'A'
								case 'A':
									// setting end_col_p to A
									end_col_p = A;
									// adding the column to last_move_white
									this->last_move_white += "A";
									break;

								// if the column is 'B'
								case 'B':
									// setting end_col_p to B
									end_col_p = B;
									// adding the column to last_move_white
									this->last_move_white += "B";
									break;

								// if the column is 'C'
								case 'C':
									// setting end_col_p to C
									end_col_p = C;
									// adding the column to last_move_white
									this->last_move_white += "C";
									break;

								// if the column is 'D'
								case 'D':
									// setting end_col_p to D
									end_col_p = D;
									// adding the column to last_move_white
									this->last_move_white += "D";
									break;

								// if the column is 'E'
								case 'E':
									// setting end_col_p to E
									end_col_p = E;
									// adding the column to last_move_white
									this->last_move_white += "E";
									break;

								// if the column is 'F'
								case 'F':
									// setting end_col_p to F
									end_col_p = F;
									// adding the column to last_move_white
									this->last_move_white += "F";
									break;

								// if the column is 'G'
								case 'G':
									// setting end_col_p to G
									end_col_p = G;
									// adding the column to last_move_white
									this->last_move_white += "G";
									break;

								// if the column is 'H'
								case 'H':
									// setting end_col_p to H
									end_col_p = H;
									// adding the column to last_move_white
									this->last_move_white += "H";
									break;

								}


								// switching user_input[1], assigning the value to end_row_p
								switch (user_input[1])
								{
								// if the row is '1'
								case '1':
									// setting end_row_p to 8
									end_row_p = 8;
									// adding the row to last_move_white
									this->last_move_white += "1";
									break;

								// if the row is '2'
								case '2':
									// setting end_row_p to 7
									end_row_p = 7;
									// adding the row to last_move_white
									this->last_move_white += "2";
									break;

								// if the row is '3'
								case '3':
									// setting end_row_p to 6
									end_row_p = 6;
									// adding the row to last_move_white
									this->last_move_white += "3";
									break;

								// if the row is '4'
								case '4':
									// setting end_row_p to 5
									end_row_p = 5;
									// adding the row to last_move_white
									this->last_move_white += "4";
									break;

								// if the row is '5'
								case '5':
									// setting end_row_p to 4
									end_row_p = 4;
									// adding the row to last_move_white
									this->last_move_white += "5";
									break;

								// if the row is '6'
								case '6':
									// setting end_row_p to 3
									end_row_p = 3;
									// adding the row to last_move_white
									this->last_move_white += "6";									
									break;

								// if the row is '7'
								case '7':
									// setting end_row_p to 2
									end_row_p = 2;
									// adding the row to last_move_white
									this->last_move_white += "7";
									break;

								// if the rowe is '8'
								case '8':
									// setting end_row_p to 1
									end_row_p = 1;
									// adding the row to last_move_white
									this->last_move_white += "8";
									break;
								}
							}

							// validating if the game was saved
							if (is_game_saved)
							{
								this->game_over = false;
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->current_turn = white_owner;

							}
							// validating if the game was exited
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
							// else switching the piece, validating the move
							else
							{

								// if the piece is a white pawn
								if (get_piece(start_row_p, start_col_p) == w_pawn)
								{

									pawn = new Pawn(white_owner, get_piece_id());

									// validating if the move is valid
									if (pawn->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								// if the piece is a white rook
								else if (get_piece(start_row_p, start_col_p) == w_rook)
								{

									rook = new Rook(white_owner, get_piece_id());

									// validating if the move is valid
									if (rook->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								// if the piece is a white knight
								else if (get_piece(start_row_p, start_col_p) == w_knight)
								{

									knight = new Knight(white_owner, get_piece_id());

									// validating if the move is valid
									if (knight->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								// if the piece is a white bishop
								else if (get_piece(start_row_p, start_col_p) == w_bishop)
								{

									bishop = new Bishop(white_owner, get_piece_id());

									// validating if the move is valid
									if (bishop->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								// if the piece is a white queen
								else if (get_piece(start_row_p, start_col_p) == w_queen)
								{

									queen = new Queen(white_owner, get_piece_id());

									// validating if the move is valid
									if (queen->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_white += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = black_owner;
									}

								}
								// if the piece is a white king
								else if (get_piece(start_row_p, start_col_p) == w_king)
								{


									king = new King(white_owner, get_piece_id());

									// validating if the white king castles
									if ((end_row_p - 1 == 7 && end_col_p - 1 == 6) || 
										(end_row_p - 1 == 7 && end_col_p - 1 == 2))
									{

										// adding one to the count_castling_white
										this->count_castling_white += 1;

										if (this->count_castling_white < 2)
										{
											// validating if the move is valid
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
										// validating if the move is valid
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
					// if the black is on the move
					else if (current_turn == black_owner)
					{

						// setting is_game_saved to false
						this->is_game_saved = false;

						// setting is_game_quit to false
						this->is_game_quit = false;

						// setting selected_start_sq to false
						this->selected_start_sq = false;

						// setting selected_end_sq to false
						this->selected_end_sq = false;

						// validating if the black king is in check
						if (is_in_check())
						{
							cout << "\n\tBlack king in check!\n";
						}
						
						// validating if the black king is in checkmate
						if (is_checkmate())
						{
							this->games_won_black += 1;
						}
						
						// validating if the game is draw
						if (is_stalemate())
						{
							this->games_draw += 1;
						}

						cout << "\n\tThe black is on the move!\n";

						// validating the starting square
						while (!selected_start_sq)
						{

							cout << "\n\tSelect your piece ('A8', 'B7', etc...)>\n";
							cin >> user_input;


							// if the lenght is invalid printing error message
							if (user_input.length() < 2 || user_input.length() > 2)
							{

								// validating if the selected option is 'S' or 'Q'
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
							// else validating the starting row and column
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
								// switching user_input[0], assigning the value to start_col_p
								switch (toupper(user_input[0]))
								{
								// if the column is 'A'
								case 'A':
									// setting start_col_p to A
									this->start_col_p = A;
									break;

								// if the column is 'B'
								case 'B':
									// setting start_col_p to B
									this->start_col_p = B;
									break;

								// if the column is 'C'
								case 'C':
									// setting start_col_p to C
									this->start_col_p = C;
									break;

								// if the column is 'D'
								case 'D':
									// setting start_col_p to D
									this->start_col_p = D;
									break;

								// if the column is 'E'
								case 'E':
									// setting start_col_p to E
									this->start_col_p = E;
									break;

								// if the column is 'F'
								case 'F':
									// setting start_col_p to F
									this->start_col_p = F;
									break;

								// if the column is 'G'
								case 'G':
									// setting start_col_p to G
									this->start_col_p = G;
									break;

								// if the column is 'H'
								case 'H':
									// setting start_col_p to H
									this->start_col_p = H;
									break;

								}


								// swithing user_input[1], assigning the value to start_row_p
								switch (user_input[1])
								{
								// if the row is '1'
								case '1':
									// setting start_row_p to 8
									this->start_row_p = 8;
									break;

								// if the row is '2'
								case '2':
									// setting start_row_p to 7
									this->start_row_p = 7;
									break;

								// if the row is '3'
								case '3':
									// setting start_row_p to 6
									this->start_row_p = 6;
									break;

								// if the row is '4'
								case '4':
									// setting start_row_p to 5
									this->start_row_p = 5;
									break;

								// if the row is '5'
								case '5':
									// setting start_row_p to 4
									this->start_row_p = 4;
									break;

								// if the row is '6'
								case '6':
									// setting start_row_p to 3
									this->start_row_p = 3;
									break;

								// if the row is '7'
								case '7':
									// setting start_row_p to 2
									this->start_row_p = 2;
									break;

								// if the row is '8'
								case '8':
									// setting start_row_p to 1
									this->start_row_p = 1;
									break;
								}
							}

							// validating if the game was saved
							if (is_game_saved)
							{
								this->game_over = false;
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->current_turn = black_owner;
							}
							// validating if the game was exited
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
								// validating the selected piece
								if (is_piece_id_valid(current_turn, start_row_p, start_col_p))
									this->selected_start_sq = true;
								else
								{
									cout << "\n\tInvalid piece. Try again!\n";
								}
							}

						}

						// validating the destination square
						while (!selected_end_sq)
						{

							// re-setting the counter for the black owner`s previous move
							this->last_move_black.clear();

							switch (get_piece(start_row_p, start_col_p))
							{
							// if the piece is a black pawn
							case 7:
								cout << "\n\t'p'_awn";
								// adding the piece to last_move_black
								this->last_move_black += "'p'_awn_to_";
								break;

							// if the piece is a black rook
							case 8:
								cout << "\n\t'r' ook";
								// adding the piece to last_move_black
								this->last_move_black += "'r'_ook_to_";
								break;

							// if the piece is a black knight
							case 9:
								cout << "\n\tk 'n' inght";
								// adding the piece to last_move_black
								this->last_move_black += "k_'n'_inght_to_";
								break;

							// if the piece is a black bishop
							case 10:
								cout << "\n\t'b' ishop";
								// adding the piece to last_move_black
								this->last_move_black += "'b'_ishop_to_";
								break;

							// if the piece is a black queen
							case 11:
								cout << "\n\t'q' ueen";
								// adding the piece to last_move_black
								this->last_move_black += "'q'_ueen_to_";
								break;

							// if the piece is a black king
							case 12:
								cout << "\n\t'k' ing";
								// adding the piece to last_move_black
								this->last_move_black += "'k'_ing_to_";
								break;
							}

							cout << " - where to ('C6', 'E5', etc...)>\n";
							cin >> user_input;



							// if the lenght is invalid printing error message
							if (user_input.length() < 2 || user_input.length() > 2)
							{

								// validating if the selected option is 'S' or 'Q'
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
							// else validating the destination row and column
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

								// switching user_input[0], assigning the valur to end_col_p
								switch (toupper(user_input[0]))
								{
								// if the column is 'A'
								case 'A':
									// setting end_col_p to A
									end_col_p = A;
									// addiing the column to last_move_black
									this->last_move_black += "A";
									break;

								// if the column is 'B'
								case 'B':
									// setting end_col_p to B
									end_col_p = B;
									// adding the column to last_move_black
									this->last_move_black += "B";
									break;

								// if the column is 'C'
								case 'C':
									// setting end_col_p to C
									end_col_p = C;
									// adding the column to last_move_black
									this->last_move_black += "C";
									break;

								// if the column is 'D'
								case 'D':
									// setting end_col_p to D
									end_col_p = D;
									// adding the column to last_move_black
									this->last_move_black += "D";
									break;

								// if the column is 'E'
								case 'E':
									// setting end_col_p to E
									end_col_p = E;
									// adding the column to last_move_black
									this->last_move_black += "E";
									break;

								// if the column is 'F'
								case 'F':
									// setting end_col_p to F
									end_col_p = F;
									// adding the column to last_move_black
									this->last_move_black += "F";
									break;

								// if the column is 'G'
								case 'G':
									// setting end_col_p to G
									end_col_p = G;
									// adding the column to last_move_black
									this->last_move_black += "G";
									break;

								// if the column is 'H'
								case 'H':
									// setting end_col_p to H
									end_col_p = H;
									// adding the column to last_move_black
									this->last_move_black += "H";
									break;

								}


								// switching user_input[1], assigning the value to end_row_p
								switch (user_input[1])
								{
								// if the row is '1'
								case '1':
									// setting end_row_p to 8
									end_row_p = 8;
									// adding the row to last_move_black
									this->last_move_black += "1";
									break;

								// if the row is '2'
								case '2':
									// setting end_row_p to 7
									end_row_p = 7;
									// adding the row to last_move_black
									this->last_move_black += "2";
									break;

								// if the row is '3'
								case '3':
									// setting end_row_p to 6
									end_row_p = 6;
									// adding the row to last_move_black
									this->last_move_black += "4";
									break;

								// if the row is '4'
								case '4':
									// setting end_row_p to 5
									end_row_p = 5;
									// adding the row to last_move_black
									this->last_move_black += "4";
									break;

								// if the row is '5'
								case '5':
									// setting end_row_p to 4
									end_row_p = 4;
									// adding the row to last_move_black
									this->last_move_black += "5";
									break;

								// if the row is '6'
								case '6':
									// setting end_row_p to 3
									end_row_p = 3;
									// adding the ow to last_move_black
									this->last_move_black += "6";
									break;

								// if the row is '7'
								case '7':
									// setting end_row_p to 2
									end_row_p = 2;
									// adding the row to last_move_black
									this->last_move_black += "7";
									break;

								// if the row is '8'
								case '8':
									// setting end_row_p to 1
									end_row_p = 1;
									// adding the row to last_move_black
									this->last_move_black += "8";
									break;
								}
							}



							// validating if the game was saved 
							if (is_game_saved)
							{
								this->game_over = false;
								this->selected_start_sq = true;
								this->selected_end_sq = true;
								this->current_turn = black_owner;

							}
							// validating if the game was exited
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
							// switching the piece, validating the move
							else
							{

								// if the piece is a black pawn
								if (get_piece(start_row_p, start_col_p) == b_pawn)
								{

									pawn = new Pawn(black_owner, get_piece_id());

									// validating if the move is valid
									if (pawn->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								// if the piece is a black rook
								else if (get_piece(start_row_p, start_col_p) == b_rook)
								{

									rook = new Rook(black_owner, get_piece_id());

									// validating if the move is valid
									if (rook->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								// if the piece is a black knight
								else if (get_piece(start_row_p, start_col_p) == b_knight)
								{

									knight = new Knight(black_owner, get_piece_id());

									// validating if the move is valid
									if (knight->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								// if the piece is a black bishop
								else if (get_piece(start_row_p, start_col_p) == b_bishop)
								{

									bishop = new Bishop(black_owner, get_piece_id());

									// validating if the move is valid
									if (bishop->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								// if the piece is a black queen
								else if (get_piece(start_row_p, start_col_p) == b_queen)
								{

									queen = new Queen(black_owner, get_piece_id());

									// validating if the move is valid
									if (queen->is_move_valid(start_row_p, start_col_p, end_row_p, end_col_p, board))
									{
										this->count_moves_black += 1;
										move_piece(start_row_p, start_col_p, end_row_p, end_col_p);
										this->selected_end_sq = true;
										this->current_turn = white_owner;
									}

								}
								// if the piece is a black king
								else if (get_piece(start_row_p, start_col_p) == b_king)
								{

									king = new King(black_owner, get_piece_id());

									// validating if the black king castles
									if ((end_row_p - 1 == 0 && end_col_p - 1 == 6) ||
										(end_row_p - 1 == 0 && end_col_p - 1 == 2))
									{

										// adding 1 to count_castling_black
										this->count_castling_black += 1;

										if (this->count_castling_black < 2)
										{
											// validating if the move is valid
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
										// validating if the move is valid
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
		// if '(L)oad from file' is selected
		else if (toupper(choice) == 'L')
		{
			
			// validating if the game was loaded successfully
			if (load_game())
			{
				
				cout << "\n\tLoading. \n\tPress <Enter> to continue . . .\n";
				cin.ignore(10, '\n');

				getchar();

				// setting the choice to New (G)ame
				choice = 'G';

				// setting is_game_loaded to true
				this->is_game_loaded = true;

			}
			else
			{
				cout << "\n\tNo saved games loacated. Try to save a game first.\n";
			}

		}
		// if '(Q)uit game' is selected
		else if(toupper(choice) == 'Q')
		{
			
			// printing the end-game message/ exiting the program
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
	// if the white is on the move
	if (owner_turn == white_owner)
	{
		// validating if the piece is a white piece
		if (board[startRow - 1][startCol - 1] >= w_pawn && board[startRow - 1][startCol - 1] <= w_king)
		{
			return true;
		}
			return false;
	}
	// if the black is on the move
	else if (owner_turn == black_owner)
	{
		// validating if the piece is a black piece
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


	// integer to hold the current column
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

	// boolean for the white king set to false
	bool is_white_king_on_board = false;

	// boolean for the black king set to false
	bool is_black_king_on_board = false;

	// locating the white king on the board
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
	
	// locating the black king on the board
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

	// if the white king is not located
	if (!is_white_king_on_board)
	{
		cout << "\n\tThe white king is captured. The black won the game!\n";
		this->games_won_black += 1;
		this->is_new_game = new_game();
		return true;
	}
	// if the black king is not located
	else if (!is_black_king_on_board)
	{
		cout << "\n\tThe black king is captured. The white won the game!\n";
		this->games_won_white += 1;
		this->is_new_game = new_game();
		return true;
	}
	// if checkmate
	else if (is_checkmate())
	{
		// if the white is on the move
		if (current_turn == white_owner)
		{
			cout << "\nWhite king checkmate!\n";
			cout << "\nThe black won the game!\n";
			this->games_won_black += 1;
			this->is_new_game = new_game();
			return true;
		}
		// if the black is on the move
		else if(current_turn == black_owner)
		{
			cout << "\nBlack king checkmate!\n";
			cout << "\nThe white won the game!\n";
			this->games_won_white += 1;
			this->is_new_game = new_game();
			return true;
		}
	}
	// if the game is draw
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
	// character to hold the user`s input;
	char yes_no = ' ';

	cout << "\n\tNew Game?(y/n)> ";
	cin >> yes_no;

	// validating the input
	while (tolower(yes_no) != 'y' && tolower(yes_no) != 'n')
	{
		cout << "\n\t" << yes_no << " cannot be a valid input. Try again> ";
		cin >> yes_no;
	}

	// if new_game is selected
	if (tolower(yes_no) == 'y')
	{
		this->count_moves_white = 0;
		this->count_moves_black = 0;
		this->choice = 'G';
		this->current_turn = white_owner;
		clear_board();

		return true;
	}
	
	// assigning the white player`s score to end_games_won_white
	this->end_games_won_white = this->games_won_white;

	// assigning the black player`s score to end_game_won_black
	this->end_games_won_black = this->games_won_black;
		
	// ressetting the counters for the score and the moves
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

	// an instance of the ofstream class
	ofstream save_game;

	// creating file for the saved game
	save_game.open("CHess_C_save_game.txt");

	// validating if the file was created
	if (save_game.fail())
	{
		cout << "\n\tFailed to save the game. Try again!\n";
	}
	else
	{

		// adding the data to the 'CHess_C_save_game.txt' file
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

	// an instance of the istream class
	ifstream load_game;
	
	// oppening 'CHess_C_save_game.txt' file
	load_game.open("CHess_C_save_game.txt");

	// validating if the file was oppened successfully
	if (load_game.is_open())
	{

		// temporary variables to hold the data from the file
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


		// assigning the data from the file to the variables
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


		// assigning the data from the temporary variables to the game variables
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
	// clearing the board
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
	// freeing the alocated memory
	delete pawn;
	delete rook;
	delete knight;
	delete bishop;
	delete queen;
	delete king;
}


