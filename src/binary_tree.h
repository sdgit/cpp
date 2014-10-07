
#include <string>
#include <memory>
#include <queue>
#include "time.h"


namespace kc {
	class BinarySearchTree
	{
	public:
		class Node;
		typedef std::shared_ptr<Node> NodePtr;

		class Node{
		public:
			Node(const int val);
			~Node() {}
			int m_data;
			NodePtr m_left;
			NodePtr m_right;
		};


		BinarySearchTree();
		BinarySearchTree(const int val);
		~BinarySearchTree();

		void insert(const int val);
		void remove(const int val);
		void print() const;
	protected:
		void append(NodePtr& curNode, const int val);
		void print_helper(NodePtr node) const;
		void remove_helper(NodePtr& node, const int val);
		NodePtr m_root;
	};
}

namespace sd 
{

	template<typename T> 
	class Node {
	public:
		T data;
		Node<T>* left;
		Node<T>* right;
		Node():left(NULL), right(NULL), data(NULL){}
		Node(int val):left(NULL), right(NULL), data(val){}
	} ;

	template<typename T>
	void GenNodeBinaryTree(Node<T> ** root,int size = 100)
	{
		if (size <= 0)
			return;

		srand (time(NULL));
		std::queue<Node<T> * > q;
		*root = new Node<T>(rand());
		q.push(*root);
		Node<T> * curr;


		for (int i = 0; i < size; i+=2)
		{
			curr = q.front();
			q.pop();

			if(i >= (size -1))
				break;
			curr->left = new Node<T>(rand());
			q.push(curr->left);
			if(i >= (size -2))
				break;
			curr->right = new Node<T>(rand());
			q.push(curr->right);
		}
	}


	template <typename T>
	void BreadthFirstTraversal(Node<T> * top)
	{
		if(!top)
			return;

		std::queue<Node<T> *> q;

		Node<T> * s = top;
		q.push(s);

		while(!q.empty())
		{
			s = q.front();
			q.pop();
			std::cout<<s->data<<std::endl;
			if(s->left)
				q.push(s->left);
			if(s->right)
			q.push(s->right);
		}

	}


}