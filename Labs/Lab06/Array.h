#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <initializer_list>

using ulong = unsigned long;

namespace ds
{
	template<class T>
	class Array
	{
		private:
		T* data;
		ulong capacity;
		
		public:
		Array() : Array(30) {}
		
		Array(ulong cp) : capacity(cp)
		{
			if(capacity < 2)
			{
				capacity = 30;
			}
			data = new T[capacity];

			for(ulong i = 0;i < capacity;i += 1)
			{
				data[i] = T();
			}
		}

		Array(std::initializer_list<T> lt)
		{
			capacity = lt.size();

			if(capacity < 2)
			{
				throw std::invalid_argument("invalid length");
			}
			data = new T[capacity];
			int i = 0;

			for(const T& x : lt)
			{	
				data[i] = x;
				i += 1;
			}
		}

		Array(const Array<T>& obj)
		{
			capacity = obj.capacity;
			data = new T[capacity];

			for(ulong i = 0;i < capacity;i += 1)
			{
				data[i] = obj.data[i];
			}
		}

		Array<T>& operator=(const Array<T>& rhs)
		{
			if(this != &rhs)
			{
				capacity = rhs.capacity;
				delete[] data;
				data = new T[capacity];

				for(ulong i = 0;i < capacity;i += 1)
				{
					data[i] = rhs.data[i];
				}
			}
			return *this;
		}

		Array<T>& operator=(std::initializer_list<T> lt)
		{
			if(capacity < lt.size())
			{
				throw std::invalid_argument("list exceeds capacity");
			}	
			
			ulong n = lt.size();
			int i = 0;

			for(const T& x : lt)
			{	
				data[i] = x;
				i += 1;
			}
			return *this;
		}

		~Array()
		{
			delete[] data;
		} 

		ulong Size() const 
		{
			return capacity;
		}

		ulong Length() const 
		{
			return capacity;
		}

		T& operator[](ulong idx)
		{
			if(idx >= capacity)
			{
				throw std::invalid_argument("out of bound");
			}
			return data[idx];
		}
	
		const T& operator[](ulong idx) const
		{
			if(idx >= capacity)
			{
				throw std::invalid_argument("out of bound");
			}
			return data[idx];
		}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			for(ulong i = 0;i < capacity;i += 1)
			{
				out << data[i];

				if((i + 1) < capacity)
				{
					out << ",";
				}
			}
			out << "]";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Array<T>& obj)
		{
			out << obj.ToString();
			return out;
		} 
	};	
}

#endif

