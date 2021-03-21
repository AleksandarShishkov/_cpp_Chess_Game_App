#ifndef PIECE_H
#define PIECE_H

// including header file Board.h
#include "Board.h"

class Piece
{

protected:



	// integer for the owner - white = 0, black = 1
	int owner;

	// integer to hold the piece id
	int piece_id = 0;


	// constructor with parameters
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


	// generic validation of the move/ returns true if valid, false if not
	virtual bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

	// returns true if the squares towards destination are blocked/ false if not
	bool is_move_blocked(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

	// virtual bool functions for handling the castling squares
	virtual bool are_right_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]);
	virtual bool are_left_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]);



};



#endif