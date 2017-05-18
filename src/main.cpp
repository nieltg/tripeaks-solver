/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#include <iostream>
#include <memory>

#include <algorithm/branch_bound.h>
#include <model/Board.h>
#include <model/State.h>

int main (void)
{
	Board<4, 3> board;
	
	// Input.
	
	std::cout << "Enter " << board.size << " card info:" << std::endl;
	std::cin >> board;
	
	size_t deck_size;
	
	std::cout << "Deck size: ";
	std::cin >> deck_size;
	
	std::cout << "Enter " << deck_size << " card info:" << std::endl;
	
	for (size_t i = 0; i < deck_size; i++)
	{
		Card card;
		
		std::cin >> card;
		board.deck.push_back (card);
	}
	
	std::shared_ptr<State<4, 3>> state = std::make_shared<State<4, 3>> (board);
	
	std::cout << "Enter current card info:" << std::endl;
	std::cin >> state->current;
	
	// Output.
	
	std::cout << "Deck: ";
	for (const Card& card : board.deck)
		std::cout << card << ' ';
	std::cout << std::endl;
	
	std::cout << "Initial state: " << std::endl;
	std::cout << *state << std::endl << std::endl;
	
	// Solve.
	
	std::cout << "Solving... " << std::endl;
	std::shared_ptr<State<4, 3>> out = branch_bound (state);
	
	std::cout << "Solved. " << std::endl;
	
	// Solution.
	
	std::cout << std::endl << "Solution: " << std::endl;
	size_t i = 0;
	
	while (out)
	{
		std::cout << "Step " << ++i << std::endl;
		std::cout << *out << std::endl << std::endl;
		
		out = out->parent;
	}
	
	return EXIT_SUCCESS;
}
