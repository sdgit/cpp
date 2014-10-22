#pragma once 

#include <string>
#include <memory>
#include <queue>
#include "time.h"
#include <stack>

//http://codercareer.blogspot.com/p/binary-tree-interview-questions.html

#if __cplusplus > 199711L
namespace kc {
	class Node;
	typedef std::shared_ptr<Node> NodePtr;

	class Node{
	public:
		Node(const int val);
		~Node() {}
		int m_data;
		NodePtr m_left;
		NodePtr m_right;
		NodePtr m_parent;
	};

	class BinaryTree {
	public:
		BinaryTree() {}
		virtual ~BinaryTree(){}
		bool insert(const int val);
		void remove(const int val);
		void print() const;

		void pre_order_traversal() const;
		void in_order_traversal() const;
		void post_order_traversal() const;
		bool breadth_first_search(const int val);
		bool breadth_first_traversal() const;
		void depth_first_traversal() const;
	private:
		void print_helper(NodePtr node) const;
		void depth_first_traversal_helper(NodePtr node) const;

	protected:
		NodePtr m_root;
	};


	class BinarySearchTree : public BinaryTree
	{
	public:
		BinarySearchTree();
		BinarySearchTree(const int val);
		virtual ~BinarySearchTree() {}

		void insert(const int val);
		void remove(const int val);

	private:
		bool append(NodePtr& curNode, const int val);
		void remove_helper(NodePtr& node, const int val);
		NodePtr find_largest_node(NodePtr root);
	};
}
#endif

namespace sd
{

	template<typename T>
	class BTNode {
	public:
		typedef BTNode<T> * NodePtr;
		T data;
		NodePtr left;
		NodePtr right;
		BTNode() :left(nullptr), right(nullptr), data(NULL){}
		BTNode(T val) :left(nullptr), right(nullptr), data(val){}
	};

	template<typename T>
	void GenNodeBinaryTree(typename BTNode<T>::NodePtr* root, int size = 100)
	{
		if (size <= 0)
			return;

		srand(time(NULL));
		std::queue<BTNode<T> * > q;
		*root = new BTNode<T>(rand()%100);
		q.push(*root);
		BTNode<T> * curr;


		for (int i = 0; i < size; i += 2)
		{
			curr = q.front();
			q.pop();

			if (i >= (size - 1))
				break;
			curr->left = new BTNode<T>(rand()%100);
			q.push(curr->left);
			if (i >= (size - 2))
				break;
			curr->right = new BTNode<T>(rand()%100);
			q.push(curr->right);
		}
	}

	//pre order
	template <typename T>
	void BreadthFirstTraversalPreOrder(BTNode<T> * top)
	{
		if (!top)
			return;

		std::queue<BTNode<T> *> q;

		BTNode<T> * s;
		q.push(top);

		while (!q.empty())
		{
			s = q.front();
			q.pop();
			std::cout << s->data << std::endl;
			if (s->left)
				q.push(s->left);
			if (s->right)
				q.push(s->right);
		}

	}

	template <typename T>
	void DepththFirstTraversal(BTNode<T> * top)
	{
		if (!top)
			return;

		std::stack<BTNode<T> *> s;

		BTNode<T> * n;
		s.push(top);

		while (!s.empty())
		{
			n = s.top();
			std::cout << n->data << std::endl;
			s.pop();
			if (n->left)
				DepththFirstTraversal(n->left);
			if (n->right)
				DepththFirstTraversal(n->right);

		}

	}

	template <typename T>
	void DepththFirstTraversalInOrder(BTNode<T> * top)
	{
		if (!top)
			return;

		std::stack<BTNode<T> *> s;

		BTNode<T> * n;
		s.push(top);

		while (!s.empty())
		{
			n = s.top();
			if (n->left)
				DepththFirstTraversalInOrder(n->left);
			std::cout << n->data << std::endl;
			s.pop();
			if (n->right)
				DepththFirstTraversalInOrder(n->right);
			
		}

	}

	//no recursion
	template <typename T>
	void DepththFirstTraversalInOrderNR(BTNode<T> * top)
	{
		if (!top)
			return;

		std::stack<BTNode<T> *> s;
		BTNode<T> * n = top;

		while (!s.empty() || n != NULL)
		{
			if (n != NULL)
			{
				s.push(n);
				n = n->left;
			}
			else
			{
				n = s.top();
				s.pop();
				std::cout << n->data << std::endl;
				n = n->right;

			}
		}

	}

	template <typename T>
	void DepththFirstTraversalInOrderNR2(BTNode<T> * top)
	{
		if (!top)
			return;

		std::stack<BTNode<T> *> s;
		BTNode<T> * n = top;
		s.push(n);

		while (!s.empty())
		{
			while (n->left != NULL)
			{
				n = n->left;
				s.push(n);
			}
			while (!s.empty())
			{
				n = s.top();
				s.pop();
				std::cout << n->data << std::endl;
				if (n->right != NULL)
				{
					n = n->right;
					s.push(n);
					break;
				}

			}
		}

	}

	//easiest to memorize?
	template <typename T>
	void DepththFirstTraversalInOrderNR3(BTNode<T> * top)
	{
		if (!top)
			return;

		std::stack<BTNode<T> *> s;
		BTNode<T> * n = top;
		s.push(n);

		while (!s.empty())
		{
			while (n->left != NULL)
			{
				n = n->left;
				s.push(n);
			}
			n = s.top();
			s.pop();
			std::cout << n->data << std::endl;

			if (n->right != NULL)
			{
				n = n->right;
				s.push(n);
			}
			
		}

	}

	template <typename T>
	void DepththFirstTraversalPostOrderNR(BTNode<T> * top)
	{
		if (!top)
			return;

		std::stack<BTNode<T> *> s;
		BTNode<T> * n = top;
		s.push(n);

		while (!s.empty())
		{
			while (n->left != NULL)
			{
				n = n->left;
				s.push(n);
				if (n->left == NULL)
				{
					std::cout << n->data << std::endl;
					n = s.top();
				}
			}


			if (n->right != NULL)
			{
				n = n->right;
				s.push(n);
			}			

		}

	}
	
}
