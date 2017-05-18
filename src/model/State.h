/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#pragma once

#include <algorithm>

#include <model/Board.h>
#include <model/Card.h>

template<size_t N_ROW, size_t N_PEAK>
class State
{
public:
	State (void)
		: board (*(Board<N_ROW, N_PEAK>*) nullptr) {}

	State (const Board<N_ROW, N_PEAK>& _board)
		: board (_board)
	{
		std::fill (locks, locks + size, 0);

		for (size_t i = 0; i < size; i++)
		{
			for (size_t id : board.content[i].node_ids_to_unlock)
				locks[id]++;
		}
	}

	static constexpr size_t size = Board<N_ROW, N_PEAK>::size;

private:
	const Board<N_ROW, N_PEAK>& board;

	int8_t locks[size];

	Card current;
	size_t deck_id;
};
