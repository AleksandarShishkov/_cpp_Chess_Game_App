#ifndef ROOK_H
#define ROOK_H

// including Piece.h
#include "Piece.h"


class Rook :public Piece
{


private:

	// integer to hold the owner
	int owner_rook = 0;

	// integer to hold the piece id
	int piece_id_rook = 0;

public:

	// constructor with parameters for the owner color and the piece id
	Rook(int owner, int piece_id);

	// overriding is_move_valid method defined in Piece.h
	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;

};


#endif
