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
Node* branch_bound (Node* _node)
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
Node* branch_bound (Node* _node, Compare _comp)
{
	class cost_compare
	{
	public:
		cost_compare (Compare _comp)
			: compare (_comp) {}

		bool operator() (Node* _lhs, Node* _rhs) const
		{ return compare (_lhs->cost (), _rhs->cost ()); }

	private:
		Compare compare;
	};

	cost_compare comp (_comp);
	std::priority_queue<Node*, std::vector<Node*>, cost_compare> tasks (_comp);

	tasks.push (_node);

	Node* candidate;

	while (!tasks.empty ())
	{
		Node* task = tasks.top ();
		tasks.pop ();

		// Do not compare if candidate node is not exist yet.

		if (!candidate || !_comp (task->cost (), candidate->cost ()))
		{
			if (task->goal ())
				candidate = task;

			for (Node* child : task->childs ())
				tasks.push (child);
		}
	}

	return candidate;
}
