/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#include <cstdlib>
#include <memory>

#include <algorithm/branch_bound.h>
#include <model/Board.h>
#include <model/State.h>

int main (void)
{
	Board<4, 3> board;
	
	size_t i = 0;
	
	board.content[i++].card = Card (Card::SPADE | 6);
	board.content[i++].card = Card (Card::SPADE | 2);
	board.content[i++].card = Card (Card::SPADE | 11);
	
	board.content[i++].card = Card (Card::SPADE | 7);
	board.content[i++].card = Card (Card::SPADE | 10);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 6);
	board.content[i++].card = Card (Card::SPADE | 12);
	board.content[i++].card = Card (Card::SPADE | 2);
	
	board.content[i++].card = Card (Card::SPADE | 8);
	board.content[i++].card = Card (Card::SPADE | 11);
	board.content[i++].card = Card (Card::SPADE | 13);
	board.content[i++].card = Card (Card::SPADE | 4);
	board.content[i++].card = Card (Card::SPADE | 7);
	board.content[i++].card = Card (Card::SPADE | 9);
	board.content[i++].card = Card (Card::SPADE | 13);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 5);
	
	board.content[i++].card = Card (Card::SPADE | 9);
	board.content[i++].card = Card (Card::SPADE | 12);
	board.content[i++].card = Card (Card::SPADE | 1);
	board.content[i++].card = Card (Card::SPADE | 5);
	board.content[i++].card = Card (Card::SPADE | 8);
	board.content[i++].card = Card (Card::SPADE | 10);
	board.content[i++].card = Card (Card::SPADE | 1);
	board.content[i++].card = Card (Card::SPADE | 4);
	board.content[i++].card = Card (Card::SPADE | 6);
	board.content[i++].card = Card (Card::SPADE | 7);
	
	board.deck.push_back (Card (Card::SPADE | 10));
	board.deck.push_back (Card (Card::SPADE | 11));
	board.deck.push_back (Card (Card::SPADE | 1));
	
	std::shared_ptr<State<4, 3>> state = std::make_shared<State<4, 3>> (board);

	state->current = Card (Card::SPADE | 8);
	
	std::shared_ptr<State<4, 3>> out = branch_bound (state);
	
	return EXIT_SUCCESS;
}
