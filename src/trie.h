#pragma once

#include <map>

namespace kc{
	template<class T>
	class Trie{

		class Node{
		public:
			T m_data;
			std::map<char, Node> m_children;
			bool m_valid;
		};
	public:
		Trie() {};
		virtual ~Trie() {}
		void add(const std::string key, T data) {
			Node* cur_node = &m_node;
			for (std::string::const_iterator itr = key.begin();
				itr != key.end(); ++itr) {
				cur_node = &cur_node->m_children[*itr];
			}
			if (cur_node) {
				cur_node->m_data = data;
				cur_node->m_valid = true;
			}
		}
		void remove();
		bool isMember(const std::string& key) {
			Node* cur_node = &m_node;
			for (std::string::const_iterator itr = key.begin();
				itr != key.end(); ++itr) {
				if (cur_node->m_children.find(key.c_str()) == cur_node->m_children.end()) {
					return false;
				}
				cur_node = &cur_node->m_children[*itr];
			}
			return (cur_node && cur_node->m_valid);
		}
	private:
		Node m_node;	
	};
}