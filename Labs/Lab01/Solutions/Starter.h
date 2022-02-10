#ifndef STARTER_H
#define STARTER_H

#include <iostream>
#include <string>
#include <sstream>

bool IsBinaryString(const std::string& str)
{
	for(int i = 0;str[i] != '\0';i += 1)
	{
		if(str[i] != '0' && str[i] != '1')
		{
			return false;
		}
	}
	return true;
}

int AbsoluteSum(int data[],int n)
{
	int s = 0;

	for(int i = 0;i < n;i += 1)
	{
		if(data[i] < 0)
		{
			s += -1 * data[i];
		}
		else 
		{
			s += data[i];
		}
	}
	return s;
}

class Location
{
	public:
	int x;
	int y;

	Location() : x(0), y(0) {}

	Location(const Location& obj)
	{
		x = obj.x;
		y = obj.y;
	}

	~Location() {}

	std::string ToString() const 
	{
		std::stringstream out;
		out << "<" << x << "," << y << ">";
		return out.str();
	}
};

#endif 
