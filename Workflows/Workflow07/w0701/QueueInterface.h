#ifndef QUEUEINTERFACE_H
#define QUEUEINTERFACE_H

#include <iostream>
#include <string>

namespace ds
{
	template<class T>
	class QueueInterface
	{
		public:
		virtual void Enqueue(const T&) = 0;
		virtual void Dequeue() = 0;
		virtual const T& Peek() const = 0; 
		virtual bool IsEmpty() const = 0; 
	};	
}

#endif

