#ifndef QUEEN_H
#define QUEEN_H


#include "Piece.h"

class Queen :public Piece
{


private:


	// integer to hold the owner
	int owner_queen = 0;

	// integer to hold the id
	int piece_id_queen = 0;

public:

	// constructor with parameters for the owner color and the piece id
	Queen(int owner, int piece_id);

	// validating the queen`s move
	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;


};



#endif