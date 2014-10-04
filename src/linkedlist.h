#include <iostream>
#include <memory>
#include "stack.h"

namespace sd {

	bool ReverseM(Element ** head);

	bool ReverseT(Element ** head);

	bool Sort(Element** head);

	bool SortedInsert(Element **head, Element * data);
}

namespace kc{
	template<class T>
	class LinkedList{
		class Node;
		typedef std::shared_ptr<Node> NodePtr;

		class Node{
		public:
			T m_data;
			NodePtr m_previous;
			NodePtr m_next;
		};
		

	public:
		LinkedList()
			:m_size(0) {};
		virtual ~LinkedList(){}

		size_t size() const { return m_size(); }

		void push_back(T val){
			if (m_size == 0) {
				m_head = m_tail = std::make_shared<Node>();
				m_head->m_data = val;
			}
			else {
				m_tail->m_next = std::make_shared<Node>();
				m_tail->m_next->m_previous = m_tail;
				m_tail->m_next->m_data = val;
				m_tail = m_tail->m_next;
			}
			++m_size;
		}

		void pop_back(){
			if (m_size == 0)
				return;
			else if (m_size == 1) {
				m_head.reset();
				m_tail.reset();
			}
			else{			
				m_tail = m_tail->m_previous;
				m_tail->m_next.reset();
			}

			--m_size;
		}

		void push_front(T val){
			if (m_size == 0) {
				m_head = m_tail = std::make_shared<Node>();
				m_head->m_data = val;
			}
			else {
				NodePtr tmp = std::make_shared<Node>();
				tmp->m_data = val;
				tmp->m_next = m_head;
				m_head = tmp;
			}
			++m_size;
		}

		void pop_front(){
			if (m_size == 0) {
				return;
			}
			else {
				m_head = m_head->m_next;
				m_head->m_previous.reset();
			}
			--m_size;
		}

		void print() {
			std::cout << "content in list..." << std::endl;
			NodePtr ptr = m_head;
			while (ptr){
				std::cout << ptr->m_data << std::endl;
				ptr = ptr->m_next;
			}
		}

		void reverse() {
			NodePtr front = m_head;
			NodePtr back = m_tail;
			for (int i = 0; i < m_size / 2; ++i) {
				std::swap(front->m_data, back->m_data);
				front = front->m_next;
				back = back->m_previous;
			}
		}

	protected:
		NodePtr m_head;
		NodePtr m_tail;
		size_t m_size;
	};
}