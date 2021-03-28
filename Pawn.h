#ifndef PAWN_H
#define PAWN_H

// including Piece.h
#include "Piece.h"


class Pawn :public Piece
{

private:

	// integer to hold the owner set to 0
	int owner_pawn = 0;

	// integer to hold the id set to 0
	int piece_id_pawn = 0;



public:



	// constructor with parameters for the owner and the piece id
	Pawn(int owner, int piece_id);


	// overriding is_move_valid method defined in Piece.h
	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;

	// method for en pasant move validation
	bool en_passant(int startRow, int startCol, int endRow, int endCol, int board[8][8]);
	
	// returning is_en_passant true/false
	bool is_pawn_en_passant();


	// method for piece promotion validation
	bool pawn_promotion(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

};


#endif
