#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include "Node.h"

namespace ds
{
	template<class T>
	class Queue
	{
		private:
		Node<T>* front;
		Node<T>* back;
	
		public:
		Queue() : front(NULL), back(NULL) {}

		Queue(const Queue<T>& obj)
		{
			front = Copy(obj.front);
			back = front;

			if(back != NULL)
			{
				while(back->next != NULL)
				{
					back = back->next;
				}
			}
		}

		Queue<T>& operator=(const Queue<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(front);
				front = Copy(rhs.front);
				back = front;
				
				if(back != NULL)
				{
					while(back->next != NULL)
					{
						back = back->next;
					}
				}
			}
			return *this;
		}

		~Queue()
		{
			Clear(front);
			front = NULL;
			back = NULL;
		} 

		void Enqueue(const T& itm)
		{
			Node<T> * t = Create(itm);

			if(front == NULL)
			{
				front = t;
				back = front;
			}
			else
			{
				back->next = t;
				t->prev = back;
				back = back->next;
			}
		}

		void Dequeue()
		{
			if(front != NULL)
			{
				Node<T>* t = front;
				front = front->next;
				delete t;
				t = NULL;

				if(front == NULL)
				{
					back = NULL;
				}
				else 
				{
					front->prev = NULL;
				}
			}
		}

		const T& Peek() const 
		{
			if(front == NULL)
			{
				throw std::invalid_argument("empty queue");
			}
			return front->data;
		}

		bool IsEmpty() const 
		{
			return (front == NULL);
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			if(front != NULL)
			{
				out << front->data;
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Queue<T>& obj)
		{
			out << obj.ToString();
			return out;
		} 
	};	
}

#endif

