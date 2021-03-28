#ifndef KNIGHT_H
#define KNIGHT_H

// including Piece.h
#include "Piece.h"

class Knight :public Piece
{


private:

	// integer to hold the owner set to 0
	int owner_knight = 0;

	// integer to hold the id set to 0
	int piece_id_knight = 0;

public:

	// constructor with parameters for the owner color and the piece id
	Knight(int owner, int piece_id);

	// overriding is_move_valid method defined in Piece.h
	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;



};



#endif
