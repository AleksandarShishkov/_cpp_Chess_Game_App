#ifndef CGAME_H
#define CGAME_H


#include "Board.h"

// including Piece.h
#include "Piece.h"


// including the headers for the pieces
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"



class CGame :public Board, public Piece
{

protected:


	// an integer set to 0 if white-checked, 1 if black-checked, -1 if neither
	int is_owner_check;

	// booleans for the starting square
	bool selected_start_sq;

	// boolean for the destination square
	bool selected_end_sq;

	// enumerator for the board columns
	enum board_columns { A = 1, B, C, D, E, F, G, H };

	// integer to hold the number of characters inputted
	int count_user_input = 0;

	// string to hold the user`s input
	string user_input;

	// integers to hold the users start rows, start columns, end rows and end columns
	int start_row_p;
	int start_col_p;
	int end_row_p;
	int end_col_p;



	// includding friend classes for the pieces
	friend class Pawn;
	friend class Rook;
	friend class Bishop;
	friend class Queen;
	friend class King;


	// friend classes pointers
	Pawn* pawn = nullptr;
	Rook* rook = nullptr;
	Knight* knight = nullptr;
	Bishop* bishop = nullptr;
	Queen* queen = nullptr;
	King* king = nullptr;



	// char to hold the choice for the game
	char choice = ' ';

	// boolean to hold the users input for new game set to true;
	bool is_new_game = true;

	// boolean to hold true if the game is over/ false if not
	bool game_over;

	// boolean for the outer game loop
	bool game_running;

	// boolean to hold true if the game was saved/ false if not
	bool is_game_saved;

	// boolean to hold true if the game was loaded/ false if not
	bool is_game_loaded;


	// boolean to hold true if the game was quited/ false if not
	bool is_game_quit;
	
	
	// integer to temporarily hold the current piece/empty square
	int current_piece = 0;


	

public:

	// default constructor
	CGame();
	

	// setting the board with it`s initial pieces
	void set_board();

	// clearing the board before set up if new game is selected
	void clear_board();


	// overriding the move_piece method defined in Board.h including is_in_check, is_checkmate and is_stalemate
	virtual void move_piece(int startRow, int startCol, int endRow, int endCol) override;

	// overriding run method defined in Board.h
	virtual void game_play() override;

	// returns integer to the piece if on the position, 0 otherwise
	int get_piece(int row, int col);

	// validating the piece upon selection
	bool is_piece_id_valid(int owner_turn, int startRow, int startCol);


	// returns 1 if in check, 0 if not
	bool is_in_check();

	// returns 1 if stalemate, 0 if not
	bool is_stalemate();

	// returns true if checkmate, false if not
	bool is_checkmate();

	// validates whether the game is over
	virtual bool is_game_over() override;

	// prints the board
	void print_board();

	// prints the minimized board in the game_play() method
	void menu_board();

	// promts the user to select whether new game will be played
	virtual bool new_game() override;

	// validates whether the game was saved successfully
	virtual bool save_game() override;

	// validates whether the game was loaded successfully
	virtual bool load_game() override;

	// destructor
	~CGame();

};


#endif
