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
	
	board.content[i++].card = Card (Card::SPADE | 2);
	board.content[i++].card = Card (Card::SPADE | 10);
	board.content[i++].card = Card (Card::SPADE | 6);
	
	board.content[i++].card = Card (Card::SPADE | 7);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 10);
	board.content[i++].card = Card (Card::SPADE | 4);
	board.content[i++].card = Card (Card::SPADE | Card::QUEEN);
	board.content[i++].card = Card (Card::SPADE | 4);
	
	board.content[i++].card = Card (Card::SPADE | Card::ACE);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 7);
	board.content[i++].card = Card (Card::SPADE | 10);
	board.content[i++].card = Card (Card::SPADE | Card::QUEEN);
	board.content[i++].card = Card (Card::SPADE | Card::ACE);
	board.content[i++].card = Card (Card::SPADE | Card::KING);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 8);
	
	board.content[i++].card = Card (Card::SPADE | 8);
	board.content[i++].card = Card (Card::SPADE | Card::ACE);
	board.content[i++].card = Card (Card::SPADE | Card::JACK);
	board.content[i++].card = Card (Card::SPADE | 6);
	board.content[i++].card = Card (Card::SPADE | 9);
	board.content[i++].card = Card (Card::SPADE | Card::ACE);
	board.content[i++].card = Card (Card::SPADE | Card::QUEEN);
	board.content[i++].card = Card (Card::SPADE | 9);
	board.content[i++].card = Card (Card::SPADE | 6);
	board.content[i++].card = Card (Card::SPADE | 5);
	
	board.deck.push_back (Card (Card::SPADE | 5));
	board.deck.push_back (Card (Card::SPADE | 7));
	board.deck.push_back (Card (Card::SPADE | Card::JACK));
	board.deck.push_back (Card (Card::SPADE | 5));
	board.deck.push_back (Card (Card::SPADE | 6));
	board.deck.push_back (Card (Card::SPADE | Card::KING));
	board.deck.push_back (Card (Card::SPADE | 2));
	board.deck.push_back (Card (Card::SPADE | 2));
	board.deck.push_back (Card (Card::SPADE | Card::KING));
	board.deck.push_back (Card (Card::SPADE | 4));
	board.deck.push_back (Card (Card::SPADE | 3));
	board.deck.push_back (Card (Card::SPADE | Card::QUEEN));
	board.deck.push_back (Card (Card::SPADE | 10));
	board.deck.push_back (Card (Card::SPADE | 4));
	board.deck.push_back (Card (Card::SPADE | 9));
	board.deck.push_back (Card (Card::SPADE | Card::KING));
	board.deck.push_back (Card (Card::SPADE | Card::JACK));
	board.deck.push_back (Card (Card::SPADE | 5));
	board.deck.push_back (Card (Card::SPADE | 10));
	board.deck.push_back (Card (Card::SPADE | 8));
	board.deck.push_back (Card (Card::SPADE | Card::JACK));
	board.deck.push_back (Card (Card::SPADE | 9));
	board.deck.push_back (Card (Card::SPADE | 7));
	
	std::shared_ptr<State<4, 3>> state = std::make_shared<State<4, 3>> (board);

	state->current = Card (Card::SPADE | 8);
	
	// Solve.
	
	std::cout << "Solving... " << std::endl;
	std::shared_ptr<State<4, 3>> out = branch_bound (state);
	
	std::cout << "Solved. " << std::endl;
	
	// Solution.
	
	std::cout << std::endl << "Solution: " << std::endl;
	
	
	
	return EXIT_SUCCESS;
}
