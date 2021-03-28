#ifndef KING_H
#define KING_H

// including Piece.h
#include "Piece.h"


class King :public Piece
{

private:

	// integer to hold the owner set to 0
	int owner_king = 0;

	// integer to hold the id set to 0
	int piece_id_king = 0;



public:

	// constructor with parameters for the owner color and the piece id
	King(int owner, int piece_id);

	// overriding is_move_valid method defined in Piece.h
	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;

	// method for castling moves validation
	bool castling(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

	// overriding are_right_castling_sqs_valid defined in Piece.h
	virtual bool are_right_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]) override;
	
	// overriding are_left_castling_sqs_valid defined in Piece.h
	virtual bool are_left_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]) override;

	// method for in-check validation on the right castling squares
	bool are_right_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8]);

	// method for in-check validation on the left castling squares
	bool are_left_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8]);

	// method for in-check validation on the 1st castling square
	bool is_sq1_in_check(int owner, int side, int sqRow, int sqCol, int board[8][8]);
	
	// method for in-check validation on the 2nd castling square
	bool is_sq2_in_check(int owner, int side, int sqRow, int sqCol, int board[8][8]);



	



};


#endif
