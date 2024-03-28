#ifndef QUEEN_H
#define QUEEN_H

#include "Piece.h"

class Queen :public Piece
{


private:


	int owner_queen = 0;

	int piece_id_queen = 0;

public:

	Queen(int owner, int piece_id);

	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;


};



#endif
