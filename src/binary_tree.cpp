#include "binary_tree.h"
#include <iostream>

namespace kc{
	using namespace std;

	BinaryTree::Node::Node(const int val)
		: m_data(val) {}

	BinaryTree::BinaryTree()
	{
	}

	BinaryTree::BinaryTree(const int val)
	{
		m_root = NodePtr(new Node(val));
	}

	BinaryTree::~BinaryTree()
	{
	}

	void BinaryTree::insert(const int val) {
		append(m_root, val);
	}

	void BinaryTree::append(NodePtr& curNode, const int val) {
		if (curNode == nullptr){
			curNode = NodePtr(new Node(val));
		}
		else if (curNode->m_data > val) {
			append(curNode->m_left, val);
		}
		else if (curNode->m_data < val) {
			append(curNode->m_right, val);
		}
	}

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

	void BinaryTree::remove(const int val) {
		remove_helper(m_root, val);
	}

	void BinaryTree::remove_helper(NodePtr& node,  const int val) {
		if (node){
			if (node->m_data == val) {
				if (node->m_left) {
					node.swap(node->m_left);
					node->m_left.reset();
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