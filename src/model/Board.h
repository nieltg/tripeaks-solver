/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#pragma once

#include <cstddef>
#include <vector>
#include <list>

#include <model/Card.h>

template<size_t N_ROW, size_t N_PEAK>
class Board
{
public:
	Board (void)
	{
		gen_dependencies ();
	}

	static constexpr size_t body_size = N_ROW * (N_ROW - 1) * N_PEAK / 2;
	static constexpr size_t leaf_size = N_PEAK * N_ROW - N_PEAK + 1;

	static constexpr size_t size = body_size + leaf_size;

	std::vector<Card> deck;

	class Node
	{
	public:
		Card card;
		std::list<size_t> node_ids_to_unlock;
	};

	Node content[size];

private:
	void gen_dependencies_row (size_t& i, size_t& t, size_t n_body)
	{
		// Begin.

		content[i++].node_ids_to_unlock.push_back (t);

		// Body.

		for (size_t body = 0; body < n_body; ++body)
		{
			std::list<size_t>& ntu = content[i++].node_ids_to_unlock;

			ntu.push_back (t++);
			ntu.push_back (t);
		}

		// End.

		content[i++].node_ids_to_unlock.push_back (t++);
	}

	void gen_dependencies (void)
	{
		size_t i = N_PEAK;
		size_t t = 0;

		// Process body nodes.

		for (size_t row = 1; row < N_ROW; ++row)
			for (size_t peak = 0; peak < N_PEAK; ++peak)
				gen_dependencies_row (i, t, row - 1);

		// Process leaf nodes.

		gen_dependencies_row (i, t, leaf_size - 2);
	}
};
