#ifndef DEQ_h
#define DEQ_h
#include<iostream>
using namespace std;

template <class Type>

class deq
{
	
public:
	deq();
	~deq();
	bool deqIsEmpty();
	void add_front(Type&);
	void add_Rear(Type&);
	void remove_front(Type&v);
	void remove_rear(Type&v);
	void view_front(Type&);
	void view_rear(Type&);
	int deq_length();
	int binary_no(Type v);
	void return_binary(Type&v);
	void store_var(Type v);
private:
	class node
	{
	public:
		int e;
		int binary;
		node* next;
	};
	int count,var;
	typedef node* NodePointer;
	NodePointer front, rear;
};
template<class Type>
deq<Type>::deq()
{
	front = NULL;
	rear = NULL;
	count = 0;
}

template<class Type>
deq<Type>::~deq()
{
	Type v;
	while (front != NULL)
		remove_front(v);
}

template<class Type>
bool deq<Type>::deqIsEmpty()
{
	return (count == 0);
}

template<class Type>
void deq<Type>::add_front(Type &v)
{
	NodePointer pnew = new node;
	pnew->e = v;  pnew->next = NULL;
	if (deqIsEmpty())
	{
		front = pnew;
		rear = pnew;
	}
	else
	{
		pnew->next = front;
		front = pnew;
	}
	count++;
}

template<class Type>
void deq<Type>::add_Rear(Type &v)
{
	NodePointer pnew = new node;
	pnew->e = v;
	pnew->binary = binary_no(v);
	pnew->next = NULL;
	if (deqIsEmpty())
	{
		front = pnew;
		rear = pnew;
	}
	else
	{
		rear->next = pnew;
		rear = pnew;
	}
	count++;
}

template<class Type>
void deq<Type>::remove_front(Type&v)
{
	NodePointer cursor;
	if (deqIsEmpty()) cout << "deq is Empty" << endl;
	else
	{
		v = front->e;
		cursor = front;
		front = front->next;
		delete cursor;
		count--;
		if (count == 0)
			rear = NULL;
	}
}

template<class Type>
void deq<Type>::remove_rear(Type&v)
{
	NodePointer cursor = front->next, previous = front;
	if (deqIsEmpty()) cout << "deq is Empty" << endl;
	else
	{
		while (cursor->next != NULL)
		{
			cursor = cursor->next;
			previous = previous->next;
		}
		v = cursor->e;
		rear = previous;
		rear->next = NULL;
		delete cursor;
		count--;
		if (count == 0)
			rear = NULL;
	}
}

template<class Type>
void deq<Type>::view_front(Type&v)
{
	v = front->e;
}

template<class Type>
void deq<Type>::view_rear(Type&v)
{
	v = rear->e;
}

template<class Type>
int deq<Type>::deq_length()
{
	return count;
}

template<class Type>
int deq<Type>::binary_no(Type v)
{
	int bin=0000000000000000, q, r, i = 1,c=0;
	while (v != 0)
	{
		r = v % 2;
		v = v / 2;
		bin = bin + (r*i);
		i = i * 10;
		c++;
	}
	return bin;
}

template<class Type>
void deq<Type>::return_binary(Type & v)
{
	v = front->binary;
}

template<class Type>
void deq<Type>::store_var(Type v)
{
	var = v;
}

#endif // !DEQ_h

