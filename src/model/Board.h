/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#pragma once

#include <array>
#include <cstddef>
#include <memory>
#include <vector>
#include <list>

#include <model/Card.h>

template<size_t Row, size_t Peak>
class Board
{
public:
	Board (void)
	{
		gen_dependencies ();
	}

	static constexpr size_t body_size = Row * (Row - 1) * Peak / 2;
	static constexpr size_t leaf_size = Peak * Row - Peak + 1;

	static constexpr size_t size = body_size + leaf_size;

	using deck_type = std::vector<Card>;
	deck_type deck;

	class Node
	{
	public:
		Card card;
		std::list<size_t> node_ids_to_unlock;
	};

	using content_type = std::array<Node, size>;
	content_type content;

	friend std::istream& operator>> (std::istream& _is, Board& _rhs)
	{
		for (Node& node : _rhs.content)
			_is >> node.card;
		
		return _is;
	}
	
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
		size_t i = Peak;
		size_t t = 0;
		
		// Process body nodes.
		
		for (size_t row = 1; row < (Row - 1); ++row)
			for (size_t peak = 0; peak < Peak; ++peak)
				gen_dependencies_row (i, t, row - 1);
		
		// Process leaf nodes.
		
		gen_dependencies_row (i, t, leaf_size - 2);
	}
};
