#ifndef BOARD_H
#define BOARD_H


#include <iostream>
#include <cctype>
#include <string>

// including library for writing/reading data into/from files
#include <fstream>


using namespace std;



class Board
{

protected:


	// integer for the current turn = 0-white, 1-black
	int current_turn = 0;


	// chars for the white and the black squares
	unsigned char sq_white = 0xDB;
	unsigned char sq_black = 0xFF;

	// integer set to 0 for the empty squares
	int sq_empty = 0;

	// the sizes for rows and cols
	int size_r = 8;
	int size_c = 8;

	// the size for the squares
	int sq_lenght = 7;
	int sq_height = 3;


	// enumerator for the pieces
	enum pieces_p {
		w_pawn = 1, w_rook, w_knight, w_bishop, w_queen, w_king,
		b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king
	};

	// enumerator for the owners
	enum owner_p { white_owner, black_owner };


	// static integers to hold the number of the moves made by the players
	int count_moves_white = 0;
	int count_moves_black = 0;

	// string to hold the white owner`s last move
	string last_move_white = "---";

	// string to hold the black owner`s last move
	string last_move_black = "---";

	// integers to hold the number of wins per player
	int games_won_white = 0;
	int games_won_black = 0;

	// integer to hold the number of games draw
	int games_draw = 0;

	// intehers to hold the end-game number of wins per player
	int end_games_won_white = 0;
	int end_games_won_black = 0;

	// integer to hold the end-game number of draws
	int end_games_draw = 0;
	
	// integers to count the kings casling moves
	int count_castling_white = 0;
	int count_castling_black = 0;
	


public:


	// 2d array of integers for the board
	int board[8][8];


	// default constructor for the initial values
	Board();


	// initialize piece on the board, prints the piece id
	void print_piece(int sq_color, int row, int col);

	

	// performs move from start position to end position, returns 1 if successfull, 0 if not
	virtual void move_piece(int startRow, int startCol, int endRow, int endCol);


	// the main game loop
	virtual void game_play();


	// validates whether the game is over
	virtual bool is_game_over();


	// printing the number of the moves made by the players
	void print_count_moves();


	// printing the last move
	void print_last_move();

	// printing the current score
	void print_score();

	// resetting the score if the game quited
	void reset_score();




	// printing save and exit options
	void print_save_exit();

	// virtual boolean functon for new game validation
	virtual bool new_game();

	// virtual boolean for saving game validation
	virtual bool save_game();

	// virtual boolean function for loading game validation
	virtual bool load_game();





};



#endif