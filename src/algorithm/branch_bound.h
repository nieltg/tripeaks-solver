/*
 * Tugas Besar 3 - IF2211 Strategi Algoritma
 */

#pragma once

#include <iostream>
#include <functional>
#include <queue>
#include <utility>

/**
 * @brief Branch and bound algorithm.
 * @param  _node First node.
 * @return  Final node.
 */
template
	<typename Node>
std::shared_ptr<Node> branch_bound (std::shared_ptr<Node> _node)
{
	using cost_type = typename Node::cost_type;
	
	return branch_bound (_node, std::greater<cost_type> ());
}

/**
 * @brief Branch and bound algorithm with compare function.
 * @param  _node First node.
 * @param  _comp Compare function.
 * @return  Final node.
 */
template
	<typename Node,
	 class Compare>
std::shared_ptr<Node> branch_bound (std::shared_ptr<Node> _node, Compare _comp)
{
	class cost_compare
	{
	public:
		cost_compare (Compare _comp)
			: compare (_comp) {}
	
		bool operator()
			(std::shared_ptr<Node> _lhs, std::shared_ptr<Node> _rhs) const
		{ return compare (_lhs->cost (), _rhs->cost ()); }
		
	private:
		Compare compare;
	};
	
	cost_compare comp (_comp);
	std::priority_queue
		<std::shared_ptr<Node>, std::vector<std::shared_ptr<Node>>,
		 cost_compare> tasks (_comp);
	
	tasks.push (_node);

	std::shared_ptr<Node> candidate;
	
	while (!tasks.empty ())
	{
		std::shared_ptr<Node> task = tasks.top ();
		tasks.pop ();
		
		//std::cout << ++i << std::endl;
		//std::cout << *task << std::endl;
		
		// Do not compare if candidate node is not exist yet.

		if (!candidate || !_comp (task->cost (), candidate->cost ()))
		{
			if (task->goal ())
				candidate = task;

			size_t j = 0;
			
			for (std::shared_ptr<Node> child : task->childs (task))
			{
				tasks.push (child);
				++j;
			}
			
			//std::cout << "Childs: " << j << std::endl;
		}
	}

	return candidate;
}
