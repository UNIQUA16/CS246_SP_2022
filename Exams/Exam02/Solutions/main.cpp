#include <iostream>
#include <string>
#include "Array.h"
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

/********************************************************************
 * Fundamentals
 ********************************************************************
 * a. first-in-first-out
 * b. e d c b a
 * c. enqueue() and dequeue()
 * d. the previous link of the head is the tail and the next link of 
 * the tail is the head.
 *******************************************************************/

/********************************************************************
 * Runtime
 ********************************************************************
 * On spreadsheet
 *******************************************************************/

/********************************************************************
 * Problem Solving
 *******************************************************************/
bool EM(const ds::Node<int>* root)
{
	bool found = false;

	if(root == NULL)
	{
		return false;
	}

	for(ds::Node<int>* i = root->next;i != NULL;i = i->next)
	{
		if(i->next->data == i->data)
		{
			if(found == true)
			{
				return true;
			}
			found = true;
		}
		else if(found == true)
		{
			found = false;
		}
	}
	return false;
}

template <typename T>
bool SecondToLastRemoval(ds::Node<T>*& root)
{
	int c = 1;
	ds::Node<T>* t = root;

	while(t != NULL || t->next != NULL)
	{
		c += 1;
		t = t->next;
	}

	if(c < 3)
	{
		return false;
	}
	t = t->prev;
	t->prev->next = t->next;
	t->next->prev = t->prev;
	delete t;
	t = NULL;
	return true;
}

bool IsValid(std::string str)
{
	ds::Stack<char> s;

	for(int i = 0;str[i] != '\0';i += 1)
	{
		if(str[i] == '(' || str[i] == '[')
		{
			s.Push(str[i]);
		}
		else if(str[i] == ')' || str[i] == ']')
		{
			if(s.IsEmpty())
			{
				return false;
			}
			else if((s.Top() == '(' && str[i] == ')') || (s.Top() == '[' && str[i] == ']'))
			{
				s.Pop();
			}
			else
			{
				return false;
			}
		}
		else 
		{
			return false;
		}
	}
	return s.IsEmpty();
}

/********************************************************************
 * Implementation
 *******************************************************************/
class NewStack
{
	private:
	ds::Stack<std::string> values;

	public:
	void Push(std::string str)
	{
		values.Push(str);
	}

	std::string Pop()
	{
		if(values.IsEmpty())
		{
			return "";
		}
		std::string value = values.Top();
		values.Pop();
		return value;
	}

	bool IsEmpty() const
	{
		return values.IsEmpty();
	}
};	

int main()
{
	std::cout << std::boolalpha;
	std::cout << "IsValid(\"[([])]\") = " << IsValid("[([])]") << "\n";
	std::cout << "IsValid(\"[(])\") = " << IsValid("[(])") << "\n";
	return 0;
}
