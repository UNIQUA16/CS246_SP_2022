#ifndef WINDOW_H
#define WINDOW_H

#include <iostream>
#include <string>
#include <sstream>

class Window
{
	private:
	int x;
	int y;
	int width;
	int length;

	public:
	Window() : x(0), y(0), width(1), length(1) {}

	Window(const Window& obj)
	{
		x = obj.x;
		y = obj.y;
		width = obj.width;
		length = obj.length;
	}

	Window& operator=(const Window& rhs)
	{
		if(this != &rhs)
		{
			x = rhs.x;
			y = rhs.y;
			width = rhs.width;
			length = rhs.length;
		}
		return *this;
	}

	~Window() {}

	int GetX() const {return x;}
	int GetY() const {return y;}
	int GetWidth() const {return width;}
	int GetLength() const {return length;}

	void SetX(int value)
	{
		if(value >= 0 && value < 20 && (value + width) < 20)
		{
			x = value;
		}
	}
	
	void SetY(int value)
	{
		if(value >= 0 && value < 20 && (value + length) < 20)
		{
			y = value;
		}
	}
	
	void SetWidth(int value)
	{
		if(value >= 1 && value < 20 && (x + value) < 20)
		{
			width = value;
		}
	}

	void SetLength(int value)
	{
		if(value >= 1 && value < 20 && (y + value) < 20)
		{
			length = value;
		}
	}

	std::string ToString() const 
	{
		std::stringstream out;
		out << "((" << x << "," << y << ")," << width << "," << length << ")";
		return out.str();
	}

	friend bool operator==(const Window& op1,const Window& op2)
	{
		return ((op1.x == op2.x) && (op1.y == op2.y) && (op1.width == op2.width) && (op1.length == op2.length));
	}

	friend std::ostream& operator<<(std::ostream& out,const Window& obj)
	{
		out << obj.ToString();
		return out;
	}
};
#endif 
