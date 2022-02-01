#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template<class T>
	class Stack
	{
		private:
		Node<T>* head;
	
		public:
		Stack() : head(NULL) {}

		Stack(const Stack<T>& obj)
		{
			head = Copy(obj.head);
		}

		Stack<T>& operator=(const Stack<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(head);
				head = Copy(rhs.head);
			}
			return *this;
		}

		~Stack()
		{
			Clear(head);
			head = NULL;
		} 

		void Push(const T& itm)
		{
			Node<T>* t = Create(itm);
			t->next = head;
			head->prev = t;
			head = t;
		}

		void Pop()
		{
			if(head != NULL)
			{
				Node<T>* t = head;
				head = head->next;
				delete t;
				t = NULL;

				if(head != NULL)
				{
					head->prev = NULL;
				}
			}
		}

		const T& Top() const 
		{
			if(head == NULL)
			{
				throw "Empty Stack";
			}
			return head->data;
		}

		bool IsEmpty() const 
		{
			return (head == NULL);
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			if(head != NULL)
			{
				out << head->data;
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
		{
			out << obj.ToString();
			return out;
		} 
	};	
}

#endif

