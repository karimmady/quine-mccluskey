#ifndef DEQ_h
#define DEQ_h
#include<iostream>
#include<vector>
#include<algorithm>
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
	void remove_front(Type&v, Type&b);
	void remove_rear(Type&v);
	void view_front(Type&);
	void view_rear(Type&);
	int deq_length();
	int binary_no(Type v);
	void return_binary(Type&v);
	void store_var(Type v);
	void special_enqueue(Type& v, int b);
	void special_dequeue(Type& v);
	int counting_ones(string s);
	void sort_nodes();
	void checking_nodes();
	void compare();
	void compare_binary(string first, string sec, int c);
	
private:
	class node
	{
	public:
		Type e;
		Type binary;
		node* next;
		int no_of_ones;
		int decimal_no;
	};
	int count,var;
	typedef node* NodePointer;
	NodePointer front, rear; 
	vector<string> table;
	vector<string>table2;
	vector<string>prime_imp;
	int c;
	
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
	Type v,b;
	while (front != NULL)
		remove_front(v,b);
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
void deq<Type>::remove_front(Type&v,Type&b)
{
	NodePointer cursor;
	if (deqIsEmpty()) cout << "deq is Empty" << endl;
	else
	{
		v = front->e;
		b = front->binary;
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
	int bin=0, q, r, i = 1,c=0;
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
template<class Type>
void deq<Type>::special_enqueue(Type & v, int b)
{
	NodePointer pnew = new node;
	pnew->decimal_no = b;
	pnew->binary = v;
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
	rear->no_of_ones = counting_ones(v);
	count++;
}
template<class Type>
void deq<Type>::special_dequeue(Type & v)
{
	NodePointer cursor;
	if (deqIsEmpty()) cout << "deq is Empty" << endl;
	else
	{
		v = front->binary;
		cursor = front;
		front = front->next;
		delete cursor;
		count--;
		if (count == 0)
			rear = NULL;
	}

}
template<class Type>
int deq<Type>::counting_ones(string s)
{
	int c = 0;
	for (int i = 0; i < s.length(); i++)
		if (s.at(i) == '1')
			c++;
	return c;
}

template<class Type>
void deq<Type>::sort_nodes()
{
	NodePointer cursor1 = front, cursor2 = front->next, move = front;
	int tempo_ones;
	string tempo_no;

	
	for (int i = 0; i < count-1; i++)
	{
		while(cursor2!=NULL)
		{
			if (cursor1->no_of_ones > cursor2->no_of_ones)
			{
				tempo_no=cursor1->binary;
				cursor1->binary = cursor2->binary;
				cursor2->binary = tempo_no;
				tempo_ones = cursor1->no_of_ones;
				cursor1->no_of_ones = cursor2->no_of_ones;
				cursor2->no_of_ones = tempo_ones;
				tempo_ones = cursor1->decimal_no;
				cursor1->decimal_no = cursor2->decimal_no;
				cursor2->decimal_no= tempo_ones;
			}
			cursor2 = cursor2->next;
		}
		move = move->next;
		cursor1 = move;
		cursor2 = cursor1->next;
	}
	
}

template<class Type>
void deq<Type>::checking_nodes()
{
	NodePointer cursor=front;
	cout << "/////////////////////////////\n";
	while (cursor != NULL)
	{
		cout << cursor->decimal_no << "          " << cursor->binary << endl;
		cursor = cursor->next;
	}
}

template<class Type>
void deq<Type>::compare()
{
	NodePointer cursor1=front, cursor2=front->next;
	for (int i = 0; i < count - 1; i++)
	{
		while (cursor2 != NULL)
		{
			c = 0;
			if (cursor1->no_of_ones == ((cursor2->no_of_ones) - 1))
				compare_binary(cursor1->binary, cursor2->binary,c);
			cursor2 = cursor2->next;

		}
		cursor1 = cursor1->next;
		cursor2 = cursor1->next;
	}
	int len = table.size();
	for (int i = 0; i < len - 1; i++)
	{
		bool prime = false;
		string a, b;
		a = table[i];
		for (int j = i + 1; j < len; j++)
		{

			b = table[j];
			for (int k = 0; k < a.length() - 1; k++)
			{
				int cnt = 0;
				if (a[k] != b[k])
					cnt++;
				if (cnt == 1)
				{
					compare_binary(table[i], table[j], c);
				}
			}
			if (!prime)
				prime_imp.push_back(a);
		}
		}
	system("pause");
}

template<class Type>
void deq<Type>::compare_binary(string first, string sec,int c)
{
	int counter = 0;
	int point = 0;
	if (first.length() != sec.length())
		cerr << "error \n";
	else 
	{
		for (int i = 0; i < first.length(); i++)
		{
			if (first.at(i) != sec.at(i))
			{
				counter++;
				point = i;
			}
		}
		if (counter == 1)
		{
			first.replace(point,1,1, '_');
			table.push_back(first);
		}
	}
}
#endif // !DEQ_h

