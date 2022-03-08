#include <iostream>
#include "Array.h"

int SumOfTwoMax(const ds::Array<int>& data)
{
	if(data.Size() < 2)
	{
		return 0;
	}
	int m[2] = {data[0],data[1]};

	if(m[0] < m[1])
	{
		m[0] = data[1];
		m[1] = data[0];
	}

	for(int i = 2;i < data.Size();i += 1)
	{
		if(data[i] > m[0])
		{
			m[1] = m[0];
			m[0] = data[i];
		}
		else if(data[i] > m[1])
		{
			m[1] = data[i];
		}
	}
	return (m[0] + m[1]);
}

int main()
{
	ds::Array<int> a = {6,5,3,4,2,1};

	std::cout << "SumOfTwoMax(" << a << ") = " << SumOfTwoMax(a) << "\n";
	return 0;
}
