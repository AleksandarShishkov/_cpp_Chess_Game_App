#ifndef PIECE_H
#define PIECE_H

#include "Board.h"

class Piece
{

protected:



	int owner;

	int piece_id = 0;


	Piece(int owner, int piece_id);

	bool is_en_passant = false;



public:


	Piece();

	int get_owner();

	int get_piece_id();


	virtual bool is_move_valid(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

	bool is_move_blocked(int startRow, int startCol, int endRow, int endCol, int board[8][8]);

	virtual bool are_right_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]);
	virtual bool are_left_castling_sqs_valid(int owner, int startRow, int startCol, int board[8][8]);



};



#endif
