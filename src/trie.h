#pragma once

#include <map>
#include <string>
#include <iostream>

namespace kc{
	template<class T>
	class Trie{

		class Node{
		public:
			Node() : m_valid(false) {}
			T m_data;
			std::map<char, Node> m_children;
			bool m_valid;
		};
	public:
		Trie() {};
		virtual ~Trie() {}
		void add(const std::string key, T data) {
			Node* cur_node = &m_node;
			for (std::string::const_iterator itr = key.begin(); itr != key.end(); ++itr) {
				cur_node = &cur_node->m_children[*itr];
			}
			if (cur_node) {
				cur_node->m_data = data;
				cur_node->m_valid = true;
			}
		}
		bool remove(const std::string& key) {
			Node* cur_node = &m_node;
			Node* parent_node = nullptr;
			for (std::string::const_iterator itr = key.begin(); itr != key.end(); ++itr) {
				char char_key = *itr;
				if (cur_node->m_children.find(char_key) == cur_node->m_children.end()) {
					return false;
				}
				cur_node = &cur_node->m_children[*itr];
			}

			if (cur_node && cur_node->m_valid) {
				cur_node->m_valid = false;
			}

			cleanup(key, m_node);

		}
		bool isMember(const std::string& key) {
			Node* cur_node = &m_node;
			for (std::string::const_iterator itr = key.begin(); itr != key.end(); ++itr) {
				char char_key = *itr;
				if (cur_node->m_children.find(char_key) == cur_node->m_children.end()) {
					return false;
				}
				cur_node = &cur_node->m_children[*itr];
			}
			bool ret = (cur_node && cur_node->m_valid);
			if (ret)
				std::cout << key << " is a member" << std::endl;
			else
				std::cout << key << "is not a member" << std::endl;
			return ret;
		}
	private:
		bool cleanup(const std::string& key, Node& node) {
			if (key.empty() || node.m_children.find(key[0]) != node.m_children.end() || node.m_children[key[0]].m_valid) {
				return false;
			}
			if (key.size() > 1) {
				if (!cleanup(key.substr(1), node.m_children[key[0]])) {
					return false;
				}
			}
			
			return node.m_children.erase(key[0]);
		}

		Node m_node;	
	};
}