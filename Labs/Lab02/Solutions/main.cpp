#include <iostream>
#include <string>
#include "Array.h"
#include "Window.h"

bool HasOverlapped(const Window& a,const Window& b)
{
	bool x, y;

	if(a.GetX() < b.GetX())
	{
		x = b.GetX() - a.GetX() < a.GetWidth();
	}
	else 
	{
		x = a.GetX() - b.GetX() < b.GetWidth();
	}

	if(a.GetY() < b.GetY())
	{
		y = b.GetY() - a.GetY() < a.GetLength();
	}
	else 
	{
		y = a.GetY() - b.GetY() < b.GetLength();
	}
	return (x && y);
}

double Probability(const Window& x,const ds::Array<Window>& data)
{
	double c = 0;
	int n = data.Length();

	for(int i = 0;i < n;i += 1)
	{
		if(HasOverlapped(x,data[i]))
		{
			c += 1;
		}
	}
	return (c / n);
}

Window MaxProbability(const ds::Array<Window>& data)
{
	int n = data.Length();
	double mp = Probability(data[0],data), p;
	int mi = 0;

	for(int i = 1;i < n;i += 1)
	{
		p = Probability(data[i],data);

		if(mp < p)
		{
			mp = p;
			mi = i;
		}
	}
	return data[mi];
}

int main()
{
	ds::Array<Window> data(4);
	int xs[] = {0,3,6,9};
	int ys[] = {1,3,8,0};
	int ws[] = {6,5,2,3};
	int ls[] = {8,7,3,5};

	for(int i = 0;i < 4;i += 1)
	{
		data[i].SetX(xs[i]);
		data[i].SetY(ys[i]);
		data[i].SetWidth(ws[i]);
		data[i].SetLength(ls[i]);
	}

	std::cout << std::boolalpha;

	for(int i = 0;i < 4;i += 1)
	{
		for(int j = i + 1;j < 4;j += 1)
		{
			std::cout << "HasOverlapped(" << data[i] << "," << data[j] << ") = " << HasOverlapped(data[i],data[j]) << "\n";
		}
	}
	std::cout << data << "\n";

	return 0;
}
