#ifndef KING_H
#define KING_H

#include "Piece.h"


class King :public Piece
{

private:

	int owner_king = 0;

	int piece_id_king = 0;



public:

	King(int owner, int piece_id);

	bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]) override;

	bool castling(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

	virtual bool are_right_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]) override;
	
	virtual bool are_left_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]) override;

	bool are_right_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8]);

	bool are_left_castling_sqs_in_check(int owner, int startRow, int startCol, int board[8][8]);

	bool is_sq1_in_check(int owner, int side, int sqRow, int sqCol, int board[8][8]);
	
	bool is_sq2_in_check(int owner, int side, int sqRow, int sqCol, int board[8][8]);



	



};


#endif
