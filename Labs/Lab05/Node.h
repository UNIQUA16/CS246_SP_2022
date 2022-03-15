#ifndef NODE_H
#define NODE_H

namespace ds
{
	template<class T>
	struct Node
	{
		T data;
		Node<T>* prev;
		Node<T>* next;
	};
	
	template<class T>
	Node<T>* Create(const T& itm)
	{
		Node<T>* t = new Node<T>;
	
		t->data = itm;
		t->prev = 0;
		t->next = 0;
		return t;
	}

	template<class T>
	Node<T>* Copy(Node<T>* rt)
	{
		if(rt == 0)
		{
			return 0;
		}
		Node<T>* hd = Create(rt->data);
		Node<T>* t = hd, *s = rt;

		while(s->next != 0)
		{
			t->next = Create(s->next->data);
			t->next->prev = t;
			s = s->next;
			t = t->next;
		}
		return hd;
	} 
		
	template<class T>
	void Clear(Node<T>*& rt)
	{
		Node<T>* t;
			
		while(rt != 0)
		{
			t = rt;
			rt = rt->next;
			delete t;
			t = 0;
		}
	}
}

#endif

