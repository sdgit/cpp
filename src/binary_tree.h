
#include <string>
#include <memory>


namespace kc {
	class BinaryTree
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


		BinaryTree();
		BinaryTree(const int val);
		~BinaryTree();

		void insert(const int val);
		void remove(const int val);
		void print() const;
	private:
		void append(NodePtr& curNode, const int val);
		void print_helper(NodePtr node) const;
		void remove_helper(NodePtr& node, const int val);
		NodePtr m_root;
	};
}
