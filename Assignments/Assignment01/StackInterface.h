#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H

#include <iostream>
#include <string>

namespace ds
{
	template<class T>
	class StackInterface
	{
		public:
		virtual void Push(const T&) = 0;
		virtual void Pop() = 0;
		virtual const T& Top() const = 0;
		virtual bool IsEmpty() const = 0; 
	};	
}

#endif

