/**
 * Tugas Makalah - IF2211 Strategi Algoritma
 */

#pragma once

#include <algorithm>
#include <memory>

#include <model/Board.h>
#include <model/Card.h>


// State

template<size_t Row, size_t Peak>
class State
{
public:
	using board_type = Board<Row, Peak>;

	State (const board_type& _board)
		: board (_board)
	{
		std::fill (locks.begin (), locks.end (), 0);

		for (size_t i = 0; i < size; i++)
		{
			for (size_t id : board.content[i].node_ids_to_unlock)
				locks[id]++;
		}
		
		deck_iterator = board.deck.begin ();
	}
	
	// Cost Calc.
	
	using cost_type = uint32_t;
	
	cost_type cost (void) const
	{
		int cost = 0;
		
		for (size_t i = 0; i < size; i++)
		{
			if (locks[i] != -1)
				cost += 2;
			
			if (locks[i] != 0)
				cost += 2;
		}
		
		return cost;
	}
	
	// Is Goal?
	
	bool goal (void) const
	{
		for (size_t i = 0; i < size; i++)
		{
			if (locks[i] != -1)
				return false;
		}
		
		return true;
	}
	
	// Childs Enumeration
	
	const std::vector<std::shared_ptr<State>> childs
		(std::shared_ptr<State> _parent) const
	{
		std::vector<std::shared_ptr<State>> db;
		
		// A
		
		for (size_t i = 0; i < size; i++)
		{
			// Iterate over unlocked cards.
			
			const typename board_type::Node& node = board.content[i];
			
			if ((locks[i] == 0) && is_adjacent (current, node.card))
			{
				// Move card to specified node.
				
				std::shared_ptr<State> child = std::make_shared<State> (*this);
				child->parent = _parent;
				
				// Remove current card.
				
				child->current = node.card;
				child->locks[i] = -1;
				
				// Unlock cards.
				
				for (size_t id : node.node_ids_to_unlock)
					--child->locks[id];
				
				db.push_back (child);
			}
		}
		
		// B
		
		if (deck_iterator != board.deck.end ())
		{
			std::shared_ptr<State> child = std::make_shared<State> (*this);
			child->parent = _parent;
			
			child->current = *child->deck_iterator++;
			
			db.push_back (child);
		}
		
		return db;
	}

	// Misc. Methods
	
	friend std::ostream& operator<< (std::ostream& _os, const State& _rhs)
	{
		size_t i = 0;
		
		// Body.
		
		for (size_t row = 0; row < (Row - 1); ++row)
		{
			for (size_t peak = 0; peak < Peak; ++peak)
			{
				const size_t pad1 = Row - row - 1;
				const size_t pad2 = Row - row - 2;
				
				_os << std::string (2 * pad1, ' ');
				
				for (size_t cc = 0; cc <= row; cc++)
				{
					const size_t id = i++;
					
					if (_rhs.locks[id] == -1)
						_os << std::string (2, ' ');
					else
						_os << _rhs.board.content[id].card;
					
					if (cc != row)
						_os << std::string (2, ' ');
				}
				
				_os << std::string (2 * pad2, ' ');
			}
			
			_os << std::endl;
		}
		
		// Leaf.
		
		for (size_t cc = 0; cc < board_type::leaf_size; cc++)
		{
			const size_t id = i++;
			
			if (_rhs.locks[id] == -1)
				_os << std::string (2, ' ');
			else
				_os << _rhs.board.content[id].card;
			
			_os << std::string (2, ' ');
		}
		
		_os << std::endl;
		
		// Metadata.
		
		_os << "Current: " << _rhs.current << std::endl;
		
		return _os;
	}
	
	Card current;
	std::shared_ptr<State> parent;
	
	static constexpr size_t size = board_type::size;
	
private:
	const board_type& board;

	using locks_type = std::array<int8_t, size>;
	locks_type locks;

	typename board_type::deck_type::const_iterator deck_iterator;
};
