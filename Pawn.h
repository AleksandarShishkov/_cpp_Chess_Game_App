#ifndef PAWN_H
#define PAWN_H

#include "Piece.h"


class Pawn :public Piece
{

private:

	int owner_pawn = 0;

	int piece_id_pawn = 0;



public:



	Pawn(int owner, int piece_id);


	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;

	bool en_passant(int startRow, int startCol, int endRow, int endCol, int board[8][8]);
	
	bool is_pawn_en_passant();


	bool pawn_promotion(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

};


#endif
