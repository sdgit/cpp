#include "binary_tree.h"

#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>


#include <stack>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>


namespace kc{
	using namespace std;

	Node::Node(const int val)
		: m_data(val) {}


	///********************Binary Tree Definitions*************************
	void BinaryTree::print() const {
		print_helper(m_root);
	}

	void BinaryTree::print_helper(NodePtr node) const {
		if (node) {
			if (node->m_left) {
				print_helper(node->m_left);
			}

			cout << node->m_data << endl;

			if (node->m_right) {
				print_helper(node->m_right);
			}
		}
	}

	void BinaryTree::pre_order_traversal() const{
		stack<NodePtr> nodes;
		nodes.push(m_root);
		stringstream ss;

		while (!nodes.empty()) {
			NodePtr node = nodes.top();
			nodes.pop();
			ss << node->m_data << ", ";

			if (node->m_right)
				nodes.push(node->m_right);

			if (node->m_left)
				nodes.push(node->m_left);
		}
		const string str = ss.str();;
		cout << "PreOrder Traversal: " << str.substr(0, str.size() - 2) << endl;
	}

	void BinaryTree::in_order_traversal() const {
		stack<NodePtr> nodes;
		NodePtr node = m_root;
		stringstream ss;

		while (!nodes.empty() || node) {
			if (node) {
				nodes.push(node);
				node = node->m_left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				ss << node->m_data << ", ";
				node = node->m_right;
			}
		}
		const string str = ss.str();;
		cout << "InOrder Traversal: " << str.substr(0, str.size() - 2) << endl;
	}

	void BinaryTree::post_order_traversal() const {
		stack<NodePtr> nodes;
		NodePtr node = m_root;
		stringstream ss;

		nodes.push(node);

		while (!nodes.empty() || node) {
			if (node) {
				nodes.push(node->m_right);
				nodes.push(node->m_left);
				node = node->m_left;
			}
			else {
				node = nodes.top();
				nodes.pop();
				if (node) {
					cout << node->m_data << endl;
					node = node->m_right;
				}
			}
		}
		const string str = ss.str();;
		cout << "PostOrder Traversal: " << str.substr(0, str.size() - 2) << endl;
	}

	bool BinaryTree::breadth_first_search(const int val) {
		queue<NodePtr> nodes;
		if (!m_root) {
			cout << "Cannot find '" << val << "' using breadth first search" << endl;
			return false;
		}
		nodes.push(m_root);

		while (!nodes.empty()) {
			NodePtr node = nodes.front();
			nodes.pop();
			if (node->m_data == val) {
				cout << "Found '" << val << "' using breadth first search" << endl;
				return true;
			}
			if (node->m_left)
				nodes.push(node->m_left);
			if (node->m_right)
				nodes.push(node->m_right);
		}
		cout << "Cannot find '" << val << "' using breadth first search" << endl;
		return false;
	}

	bool BinaryTree::insert(const int val) {
		queue<NodePtr> nodes;
		if (!m_root) {
			m_root = make_shared<Node>(val);
			return true;
		}
		nodes.push(m_root);

		while (!nodes.empty()){
			NodePtr node = nodes.front();
			nodes.pop();
			if (!node->m_left) {
				node->m_left = make_shared<Node>(val);
				return true;
			}
			else {
				nodes.push(node->m_left);
			}
			if (!node->m_right) {
				node->m_right = make_shared<Node>(val);
				return true;
			}
			else {
				nodes.push(node->m_right);
			}
		}
		return false;
	}

	bool BinaryTree::breadth_first_traversal() const {
		queue<NodePtr> nodes;
		if (!m_root)
			return false;
		nodes.push(m_root);
		//std::cout << "Breadth First Traversal:";
		stringstream ss;
		while (!nodes.empty()) {
			NodePtr node = nodes.front();
			nodes.pop();
			ss << node->m_data << ", ";
			if (node->m_left)
				nodes.push(node->m_left);
			if (node->m_right)
				nodes.push(node->m_right);
		}

		const string str = ss.str();
		if (!str.empty()) {
			cout << "Breadth First Traversal: " << str.substr(0, str.size() - 2) << endl;
		}
		return false;
	}

	void BinaryTree::depth_first_traversal() const {
		depth_first_traversal_helper(m_root);
	}

	void BinaryTree::depth_first_traversal_helper(NodePtr node) const {
		string str;
		if (!node)
			return;
		if (node->m_left) {
			depth_first_traversal_helper(node->m_left);
		}
		if (node->m_right) {
			depth_first_traversal_helper(node->m_right);
		}
		cout << node->m_data << endl;
	}

	void BinaryTree::remove(const int val) {

	}

	///***************Binary Search Tree Definitions*************************
	BinarySearchTree::BinarySearchTree()
	{
	}

	BinarySearchTree::BinarySearchTree(const int val)
	{
		m_root = NodePtr(new Node(val));
	}

	void BinarySearchTree::insert(const int val) {
		append(m_root, val);
	}

	bool BinarySearchTree::append(NodePtr& curNode, const int val) {
		if (curNode == nullptr){
			curNode = NodePtr(new Node(val));
			return true;
		}
		else if (curNode->m_data > val) {
			if (append(curNode->m_left, val)) {
				curNode->m_left->m_parent = curNode;
			}
		}
		else if (curNode->m_data < val) {
			if (append(curNode->m_right, val)) {
				curNode->m_right->m_parent = curNode;
			}
		}
	}

	NodePtr BinarySearchTree::find_largest_node(NodePtr root){
		if (!root)
			return nullptr;
		else {
			return (root->m_right) ? find_largest_node(root->m_right) : root;
		}
	}

	void BinarySearchTree::remove(const int val) {
		remove_helper(m_root, val);
	}

	void BinarySearchTree::remove_helper(NodePtr& node, const int val) {
		if (node){
			if (node->m_data == val) {
				if (node->m_left) {
					NodePtr replacement = find_largest_node(node->m_left);
					if (replacement != nullptr) {
						if (replacement->m_left) {
							replacement->m_parent->m_right = replacement->m_left;
						}
						else {
							replacement->m_parent->m_right.reset();
						}
						node.swap(replacement);
						node->m_left = replacement->m_left;
						node->m_right = replacement->m_right;
						node->m_parent = replacement->m_parent;
						replacement.reset();
					}
				}
				else if (node->m_right) {
					node.swap(node->m_right);
					node->m_right.reset();
				}
				else{
					node.reset();
				}
			}
			else if (node->m_data > val) {
				remove_helper(node->m_left, val);
			}
			else{
				remove_helper(node->m_right, val);
			}
		}
	}
}



namespace sd{



}
