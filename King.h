#ifndef KING_H
#define KING_H

// including header file Piece.h
#include "Piece.h"


class King :public Piece
{

private:

	// integer to hold the owner
	int owner_king = 0;

	// integer to hold the id
	int piece_id_king = 0;



public:

	// constructor with parameters for the owner color and the piece id
	King(int owner, int piece_id);

	// validating the king`s move
	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;

	// validating the castling move
	bool castling(int startRow, int startCol, int endRow, int endCol, int board[8][8]);



	// validating the right castling squares
	virtual bool are_right_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]) override;
	
	// validating the left castling squares
	virtual bool are_left_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]) override;

	// validating whether the right castling squares are in check
	bool are_right_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8]);

	// validating whether the left castling sqares are in check
	bool are_left_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8]);

	// validating the first castling square
	bool is_sq1_in_check(int owner, int side, int sqRow, int sqCol, int board[8][8]);
	
	// validating the second castling square
	bool is_sq2_in_check(int owner, int side, int sqRow, int sqCol, int board[8][8]);



	



};


#endif