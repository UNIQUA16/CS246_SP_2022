#include <iostream>
#include "Array.h"
#include "Node.h"

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

int main()
{
	return 0;
}
