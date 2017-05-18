/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#include <cstdlib>
#include <memory>

#include <model/Board.h>
#include <model/State.h>

int main (void)
{
	Board<4, 3> board;
	
	size_t i = 0;
	
	board.content[i++].card = Card (Card::SPADE | 1);
	board.content[i++].card = Card (Card::SPADE | 1);
	board.content[i++].card = Card (Card::SPADE | 1);
	
	board.content[i++].card = Card (Card::SPADE | 2);
	board.content[i++].card = Card (Card::SPADE | 2);
	board.content[i++].card = Card (Card::SPADE | 2);
	board.content[i++].card = Card (Card::SPADE | 2);
	board.content[i++].card = Card (Card::SPADE | 2);
	board.content[i++].card = Card (Card::SPADE | 2);
	
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 3);
	
	board.content[i++].card = Card (Card::SPADE | 5);
	board.content[i++].card = Card (Card::SPADE | 5);
	board.content[i++].card = Card (Card::SPADE | 4);
	board.content[i++].card = Card (Card::SPADE | 4);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 3);
	board.content[i++].card = Card (Card::SPADE | 2);
	board.content[i++].card = Card (Card::SPADE | 2);
	board.content[i++].card = Card (Card::SPADE | 1);
	board.content[i++].card = Card (Card::SPADE | 1);
	
	board.deck.push_back (Card (Card::SPADE | 1));
	board.deck.push_back (Card (Card::SPADE | 2));
	board.deck.push_back (Card (Card::SPADE | 3));
	board.deck.push_back (Card (Card::SPADE | 4));
	board.deck.push_back (Card (Card::SPADE | 5));
	
	State<4, 3> state (board);

	state.current = Card (Card::SPADE | 3);
	
	std::vector<std::shared_ptr<State<4, 3>>> db = state.childs (nullptr);
	std::cout << "Childs: " << db.size () << std::endl;
	
	for (std::shared_ptr<State<4, 3>> state : db)
	{
		std::cout << *state << std::endl << std::endl;
	}
	
	return EXIT_SUCCESS;
}
