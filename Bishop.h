#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"

class Bishop :public Piece
{

private:

	int owner_bishop = 0;

	int piece_id_bishop = 0;

public:

	Bishop(int owner, int piece_id);

	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;
};

#endif
