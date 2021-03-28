#ifndef PIECE_H
#define PIECE_H

// including Board.h
#include "Board.h"

class Piece
{

protected:



	// integer for the owner set to 0
	int owner;

	// integer to hold the piece id set to 0
	int piece_id = 0;


	// constructor with parameters for the owner and the piece id
	Piece(int owner, int piece_id);

	// boolean to hold true if en_passant is executed, false otherwise
	bool is_en_passant = false;



public:


	// default constructor
	Piece();

	// returns the owner of the piece
	int get_owner();

	// returns the id of the piece
	int get_piece_id();


	// virtual method for validation of the move/ returns true if valid, false if not
	virtual bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

	// method for block-move validation
	bool is_move_blocked(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

	// virtual methods for castling squares validation
	virtual bool are_right_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]);
	virtual bool are_left_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]);



};



#endif
