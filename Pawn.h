#ifndef PAWN_H
#define PAWN_H

// including header file Piece.h
#include "Piece.h"


class Pawn :public Piece
{

private:

	// integer to hold the owner
	int owner_pawn = 0;

	// integer to hold the id
	int piece_id_pawn = 0;



public:



	// constructor with parameters for the owner color and the piece id
	Pawn(int owner, int piece_id);


	// validating the pawns move
	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;

	// validating en pasant move
	bool en_passant(int startRow, int startCol, int endRow, int endCol, int board[8][8]);
	
	// returning is_en_passant true/false
	bool is_pawn_en_passant();


	// validating piece promotion
	bool pawn_promotion(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

};


#endif