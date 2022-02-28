#include <iostream>
#include <string>
#include <sstream>
#include "Array.h"

/********************************************************************
 * Task 01
 * 01. O(1) 
 * 02. O(ceiling(log(n)))
 * 03. O(ceiling(lg(lg(n))))
 * 04. O(ceiling(lg(n)))
 * 05. O(ceiling(lg^2(n)))
 * 06. O(ceiling(sqrt(n)))
 * 07. O(n)
 * 08. O(ceiling(nlg(n)))
 * 09. O(n^2)
 * 10. O(2^n)
 * ******************************************************************/

/********************************************************************
 * Task 02
 * n = the size of data
 *
 * RT = {(c1,1),(c2,1),(c3,1),(c4,ceiling(n/2)+1)
 * ,(c5,ceiling(n/2),(c6,ceiling(n/2),(c7,ceiling(n/2),(c8,1)}
 *
 * T(n) = 4*ceiling(n/2) + 5
 *******************************************************************/

//Task 03
int EvenOddDifference(const ds::Array<int>& data)
{
	int n = data.Size(), es = 0, os = 0;

	for(int i = 0;i < n;i += 1)
	{
		if(data[i] % 2 == 0)
		{
			es += data[i];
		}
		else 
		{
			os += data[i];
		}
	}
	return (os - es);
}

//Task 04
template <typename T>
void InsertBefore(ds::Array<T>& data,const T& target,const T& value)
{
	int idx = 0, n = data.Size();

	while(idx < n && data[idx] != target)
	{
		idx += 1;
	}

	if(idx < n)
	{
		for(int i = n - 1;i > idx;i -= 1)
		{
			data[i] = data[i-1];
		}
		data[idx] = value;
	}
}

//Task 05
template <class T>
class Pair
{
	public:
	T key;
	int value;

	Pair()
	{
		key = T();
		value = 0;
	}

	Pair(const Pair<T>& obj)
	{
		key = obj.key;
		value = obj.value;
	}

	Pair<T>& operator=(const Pair<T>& rhs)
	{
		if(this != &rhs)
		{
			key = rhs.key;
			value = rhs.value;
		}
		return *this;
	}

	~Pair() {}

	std::string ToString() const 
	{
		std::stringstream out;
		out << "<" << key << "," << value << ">";
		return out.str();
	}
};

int main()
{
	ds::Array<int> a = {2,6,1,5,7,3};
	ds::Array<char> b = {'h','f','j','f','q'};

	std::cout << "EvenOddDifference(" << a << ") = " << EvenOddDifference(a) << "\n";
	std::cout << "\nBefore InsertBefore() caller:\n";
	std::cout << b << "\n";
	InsertBefore(b,'f','t');
	std::cout << "After InsertBefore() caller:\n";
	std::cout << b << "\n";

	return 0;
}
