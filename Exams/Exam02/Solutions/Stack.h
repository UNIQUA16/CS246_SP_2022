#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Node.h"

namespace ds
{
	template<class T>
	class Stack
	{
		private:
		Node<T>* top;
	
		public:
		Stack() : top(NULL) {}

		Stack(const Stack<T>& obj)
		{
			top = Copy(obj.top);
		}

		Stack<T>& operator=(const Stack<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(top);
				top = Copy(rhs.top);
			}
			return *this;
		}

		~Stack()
		{
			Clear(top);
			top = NULL;
		} 

		void Push(const T& value)
		{
			Node<T>* t = Create(value);

			if(top == NULL)
			{
				top = t;
			}
			else
			{
				t->next = top;
				top->prev = t;
				top = t;
			}
		}

		void Pop()
		{
			if(top != NULL)
			{
				Node<T>* t = top;
				top = top->next;
				delete t;
				t = NULL;

				if(top != NULL)
				{
					top->prev = NULL;
				}
			}
		}

		const T& Top() const 
		{
			if(top == NULL)
			{
				throw std::invalid_argument("Empty Stack");
			}
			return top->data;
		}

		bool IsEmpty() const 
		{
			return (top == NULL);
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			if(top != NULL)
			{
				out << top->data;

				if(top->next != NULL)
				{
					out << "," << top->next->data;
				}
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

