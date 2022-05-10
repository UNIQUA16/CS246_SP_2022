#include <iostream>
#include "Array.h"
#include "Node.h"

/*Task 01*/
//It assigns each element of root the closest multiple of 4 greater than or equal to its absolute value   
void F(ds::Node<int>* root)
{
	for(ds::Node<int>* t = root;t != NULL;t = t->next)
	{
		if(t->data < 0)
		{
			t->data *= -1;
		}
		t->data = t->data + (t->data % 4);
	}
}

void G(ds::Array<int>& data)
{
	for(int i = 0;i < data.Size();i += 1)
	{
		if(data[i] < 0)
		{
			data[i] *= -1;
		}
		data[i] = data[i] + (data[i] % 4);
	}
}

/*Task 02*/
bool Monotonic(const ds::Node<int>* root)
{
	if(root == NULL)
	{
		return  true;
	}

	for(ds::Node<int>* i = root->next;i != NULL;i = i->next)
	{
		if(i->prev->data > i->data)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	return 0;
}
