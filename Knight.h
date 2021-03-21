#ifndef KNIGHT_H
#define KNIGHT_H

// including header file Piece.h
#include "Piece.h"

class Knight :public Piece
{


private:

	// integer to hold the owner
	int owner_knight = 0;

	// integer to hold the id
	int piece_id_knight = 0;

public:

	// constructor with parameters for the owner color and the piece id
	Knight(int owner, int piece_id);

	// validating the knight`s move
	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;



};



#endif