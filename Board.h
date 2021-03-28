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

	// integers for the board rows and columns
	int size_r = 8;
	int size_c = 8;

	// integers for the lenght and the height of the board squares
	int sq_lenght = 7;
	int sq_height = 3;


	// enumerator for the pieces
	enum pieces_p {
		w_pawn = 1, w_rook, w_knight, w_bishop, w_queen, w_king,
		b_pawn, b_rook, b_knight, b_bishop, b_queen, b_king
	};

	// enumerator for the owners
	enum owner_p { white_owner, black_owner };


	// integers to kepp count of the players moves set to 0
	int count_moves_white = 0;
	int count_moves_black = 0;

	// string to hold the white owner`s last move
	string last_move_white = "---";

	// string to hold the black owner`s last move
	string last_move_black = "---";

	// integers to hold the number of wins per player set to 0
	int games_won_white = 0;
	int games_won_black = 0;

	// integer to hold the number of games draw set to 0
	int games_draw = 0;

	// intehers to hold the end-game number of wins per player set to 0
	int end_games_won_white = 0;
	int end_games_won_black = 0;

	// integer to hold the end-game number of draws set to 0
	int end_games_draw = 0;
	
	// integers to keep count of the kings casling moves set to 0
	int count_castling_white = 0;
	int count_castling_black = 0;
	


public:


	// 2d array of integers for the board
	int board[8][8];


	// default constructor 
	Board();


	// initialize a piece on the board, prints the piece id
	void print_piece(int sq_color, int row, int col);

	

	// virtual method for the move from start position to end position, returns 1 if successfull, 0 if not
	virtual void move_piece(int startRow, int startCol, int endRow, int endCol);


	// virtual method for the main game loop
	virtual void game_play();


	// virtual method for game-over validation	
	virtual bool is_game_over();


	// method for printing the number of the moves made by the players
	void print_count_moves();


	// method for printing the last moves
	void print_last_move();

	// method for printing the current score
	void print_score();

	// method for score re-set if the game is exited
	void reset_score();

	// method for the save and exit options
	void print_save_exit();

	// virtual method for new game validation
	virtual bool new_game();

	// virtual method for save game validation
	virtual bool save_game();

	// virtual method for load game validation
	virtual bool load_game();



};



#endif
