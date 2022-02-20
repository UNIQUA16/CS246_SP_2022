#ifndef BEGINNER_H
#define BEGINNER_H

#include <iostream>
#include <string>
#include "Array.h"

int PartitionCount(ds::Array<int>& data,int target)
{
	int c = 0;
	int n = data.Size();

	for(int i = 0;i < n;i += 1)
	{
		if(data[i] <= target)
		{
			c += 1;
		}
	}
	return c;	
}

double Distance(ds::Array<double>& data)
{
	int n = data.Size();

	if(n <= 1)
	{
		return 0;
	}
	double mx, mn;

	if(data[0] < data[1])
	{
		mn = data[0];
		mx = data[1];
	}
	else 
	{
		mn = data[1];
		mx = data[0];
	}

	for(int i = 2;i < n;i += 1)
	{
		if(data[i] > mx)
		{
			mx = data[i];
		}
		else if(data[i] < mn)
		{
			mn = data[i];
		}
	}
	return (mx - mn);
}

double Median(const ds::Array<int>& data)
{
	int n = data.Size(), c = n / 2 + 1, below, copy, i;
       	
	if(n == 0)
	{
		return 0.0;
	}
	//Find middle value if odd or upper middle value if even
	for(i = 0;i < n;i += 1)
	{
		below = 0;
		copy = 0;

		for(int j = 0;j < n;j += 1)
		{
			if(data[j] < data[i])
			{
				below += 1;
			}
			else if(data[j] == data[i])
			{
				copy += 1;
			}
		}
		if(below < c && (below + copy) >= c)
		{
			break;
		}
	}
	
	if(n % 2 == 1 || (below < c - 1))
	{
		return data[i];
	}
	else
	{
		int mx = data[i];

		for(int j = 0;j < n;j += 1)
		{
			if(data[j] < data[i]) 
			{
				if(mx == data[i] || mx < data[j])
				{
					mx = data[j];
				}
			}
		}
		return ((mx + data[i]) / 2.0);
	}
}	

#endif
