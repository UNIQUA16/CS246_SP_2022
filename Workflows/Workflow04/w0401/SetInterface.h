#ifndef SETINTERFACE_H
#define SETINTERFACE_H

#include <iostream>
#include <string>

namespace ds
{
	template<class T>
	class SetInterface
	{
		public:
		virtual void Insert(const T&) = 0;
		virtual void Remove(const T&) = 0;
		virtual bool Contains(const T&) const = 0;
		virtual bool IsEmpty() const = 0; 
	};	
}

#endif

