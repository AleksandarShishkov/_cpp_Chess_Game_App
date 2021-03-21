#ifndef BISHOP_H
#define BISHOP_H

// including header file Piece.h
#include "Piece.h"

class Bishop :public Piece
{

private:

	// integer to hold the owner
	int owner_bishop = 0;

	// integer to hold the id
	int piece_id_bishop = 0;

public:

	// constructor with parameters for the owner color and the piece id
	Bishop(int owner, int piece_id);

	// validating the bishop`s move
	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;



};



#endif
