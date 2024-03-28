#ifndef BOARD_H
#define BOARD_H


#include <iostream>
#include <cctype>
#include <string>

#include <fstream>

using namespace std;

class Board
{

protected:


	int current_turn = 0;

	unsigned char sq_white = 0xDB;
	unsigned char sq_black = 0xFF;

	int sq_empty = 0;

	int size_r = 8;
	int size_c = 8;

	int sq_lenght = 7;
	int sq_height = 3;


	enum pieces_p {
		w_pawn = 1, w_rook, w_knight, w_bishop, w_queen, w_king,
		b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king
	};

	enum owner_p { white_owner, black_owner };


	int count_moves_white = 0;
	int count_moves_black = 0;

	string last_move_white = "---";

	string last_move_black = "---";

	int games_won_white = 0;
	int games_won_black = 0;

	int games_draw = 0;

	int end_games_won_white = 0;
	int end_games_won_black = 0;

	int end_games_draw = 0;
	
	int count_castling_white = 0;
	int count_castling_black = 0;
	
public:


	int board[8][8];

	Board();

	void print_piece(int sq_color, int row, int col);

	virtual void move_piece(int startRow, int startCol, int endRow, int endCol);

	virtual void game_play();

	virtual bool is_game_over();

	void print_count_moves();

	void print_last_move();

	void print_score();

	void reset_score();

	void print_save_exit();

	virtual bool new_game();

	virtual bool save_game();

	virtual bool load_game();

};

#endif
