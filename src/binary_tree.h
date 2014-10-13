
#include <string>
#include <memory>
#include <queue>
#include "time.h"

//http://codercareer.blogspot.com/p/binary-tree-interview-questions.html


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
		bool breadth_first_search(const int val);
		bool breadth_first_traversal() const;
	private:
		void print_helper(NodePtr node) const;

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
		*root = new BTNode<T>(rand());
		q.push(*root);
		BTNode<T> * curr;


		for (int i = 0; i < size; i += 2)
		{
			curr = q.front();
			q.pop();

			if (i >= (size - 1))
				break;
			curr->left = new BTNode<T>(rand());
			q.push(curr->left);
			if (i >= (size - 2))
				break;
			curr->right = new BTNode<T>(rand());
			q.push(curr->right);
		}
	}


	template <typename T>
	void BreadthFirstTraversal(BTNode<T> * top)
	{
		if (!top)
			return;

		std::queue<BTNode<T> *> q;

		BTNode<T> * s = top;
		q.push(s);

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


}