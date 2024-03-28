#ifndef CGAME_H
#define CGAME_H


#include "Board.h"

#include "Piece.h"


#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"



class CGame :public Board, public Piece
{

protected:


	int is_owner_check;

	bool selected_start_sq;

	bool selected_end_sq;

	enum board_columns { A = 1, B, C, D, E, F, G, H };

	int count_user_input = 0;

	string user_input;

	int start_row_p;
	int start_col_p;
	int end_row_p;
	int end_col_p;



	friend class Pawn;
	friend class Rook;
	friend class Bishop;
	friend class Queen;
	friend class King;


	Pawn* pawn = nullptr;
	Rook* rook = nullptr;
	Knight* knight = nullptr;
	Bishop* bishop = nullptr;
	Queen* queen = nullptr;
	King* king = nullptr;





	bool game_over;

	bool game_running;

	bool is_game_saved;

	bool is_game_loaded;


	bool is_game_quit;
	
	
	int current_piece = 0;


	

public:

	CGame();
	

	void set_board();

	void clear_board();


	virtual void move_piece(int startRow, int startCol, int endRow, int endCol) override;

	virtual void game_play() override;

	int get_piece(int row, int col);

	bool is_piece_id_valid(int owner_turn, int startRow, int startCol);


	bool is_in_check();

	bool is_stalemate();

	bool is_checkmate();

	virtual bool is_game_over() override;

	void print_board();

	void menu_board();

	virtual bool new_game() override;

	virtual bool save_game() override;

	virtual bool load_game() override;

	~CGame();

};


#endif
