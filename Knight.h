#ifndef KNIGHT_H
#define KNIGHT_H

//test commupdang the knight_h file

#include "Piece.h"

class Knight :public Piece
{


private:

	int owner_knight = 0;

	int piece_id_knight = 0;

public:

	Knight(int owner, int piece_id);

	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;



};



#endif
