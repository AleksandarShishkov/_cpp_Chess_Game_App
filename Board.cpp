#include "Board.h"

Board::Board()
{

	for (int i = 0; i < size_r; ++i)
		for (int j = 0; j < size_c; ++j)
		{
			board[i][j] = sq_empty;
		}
			
}


void Board::print_piece(int sq_color, int row, int col)
{
	
	switch (board[row][col])
	{

	case w_pawn:
		cout << 'P';
		break;

	case w_rook:
		cout << 'R';
		break;

	case w_knight:
		cout << 'N';
		break;

	case w_bishop:
		cout << 'B';
		break;

	case w_queen:
		cout << 'Q';
		break;

	case w_king:
		cout << 'K';
		break;

	case b_pawn:
		cout << 'p';
		break;

	case b_rook:
		cout << 'r';
		break;

	case b_knight:
		cout << 'n';
		break;

	case b_bishop:
		cout << 'b';
		break;

	case b_queen:
		cout << 'q';
		break;

	case b_king:
		cout << 'k';
		break;

	default:
		if (sq_color == 0)
		{
			cout << sq_white;
		}
		else
		{
			cout << sq_black;
		}
		break;
	}
}

void Board::move_piece(int startRow, int startCol, int endRow, int endCol)
{
	if ((startRow >= 0 && startRow <= size_r - 1) && (startCol >= 0 && startCol <= size_c - 1) &&
		(endRow >= 0 && endRow <= size_r - 1) && (endCol >= 0 && endCol <= size_c - 1))
	{

		int current_piece = board[startRow][startCol];

		if (board[endRow][endCol] == sq_empty)
		{
			board[endRow][endCol] = current_piece;
			board[startRow][startCol] = sq_empty;
		}
	}
}

void Board::game_play()
{
	// message
	// menu
	// start game
	// overriden in CGame class
}


bool Board::is_game_over()
{
	return false;
}

void Board::print_score()
{

	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\tScore:\n";
	cout << "\n\t\t  White " << this->games_won_white << " : " << this->games_won_black << " Black\n";
	cout << "\n\t\t\tDraw: " << this->games_draw << '\n';
}

void Board::print_save_exit()
{
	cout << "\t\t\t\t\t(S)ave     (Q)uit\n";
}
void Board::print_count_moves()
{
	cout << "\n";
	cout << "\nMoves 'White' - " << count_moves_white << "\n" << "Moves 'Black' - " << count_moves_black << "\n\n";
}

void Board::print_last_move()
{
	cout << "\Previous moves: \n\tWhite - " << this->last_move_white << "\n\tBlack - " << this->last_move_black;
	cout << '\n';
}


void Board::reset_score()
{
	this->games_won_white = 0;
	this->games_won_black = 0;
	this->games_draw = 0;
	this->count_moves_white = 0;
	this->count_moves_black = 0;
	this->last_move_white.clear();
	this->last_move_black.clear();
	this->count_castling_white = 0;
	this->count_castling_black = 0;
}

bool Board::new_game()
{
	return true;
}


bool Board::save_game()
{
	return true;
}


bool Board::load_game()
{
	return true;
}
