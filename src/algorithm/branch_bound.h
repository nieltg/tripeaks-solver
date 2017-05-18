/*
 * Tugas Besar 3 - IF2211 Strategi Algoritma
 */

#pragma once

#include <functional>
#include <queue>
#include <utility>

/**
 * @brief Branch and bound algorithm.
 * @param  _node First node.
 * @return  Pair of search status and final node.
 */
template
	<typename Node>
std::pair<bool, Node> branch_bound (Node _node)
{
	using cost_type = typename Node::cost_type;
	
	return branch_bound<Node> (_node, std::greater<cost_type> ());
}

/**
 * @brief Branch and bound algorithm with compare function.
 * @param  _node First node.
 * @param  _comp Compare function.
 * @return  Pair of search status and final node.
 */
template
	<typename Node,
	 class Compare>
std::pair<bool, Node> branch_bound (Node _node, Compare _comp)
{
	class node_wrapper
	{
	public:
		using cost_type = typename Node::cost_type;
		
		node_wrapper (Node _node)
			: node (_node) {}
		
		operator cost_type (void) const
		{ return node.cost (); }
		
		Node node;
	};
	
	std::priority_queue<node_wrapper, std::vector<node_wrapper>, Compare> tasks;

	bool is_not_ok = true;
	Node candidate;
	
	size_t active_node = 0;

	tasks.push (_node);

	while (!tasks.empty ())
	{
		Node task = tasks.top ().node;
		tasks.pop ();
		
		active_node++;
		
		// Do not compare if candidate node is not ok.

		if (is_not_ok || !_comp (task.cost (), candidate.cost ()))
		{
			if (task)
			{
				is_not_ok = false;
				candidate = task;
			}

			for (Node child : task.childs ())
				tasks.push (node_wrapper (child));
		}
	}
	
	std::cout << "Active node: " << active_node << std::endl;

	return std::make_pair (!is_not_ok, candidate);
}
