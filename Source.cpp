#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include"DEQ.h"
using namespace std;
deq<int>dont_cares;
deq<int>minterms;
struct node {
	int no;
	node*next;
};
void compare()
{
	
}
int main()
{
	int var;
	cin >> var;
	while (var >= 16||var==0)
	{
		cout << "invalid input" << endl;
		cin >> var;
	}
	minterms.store_var(var);
	dont_cares.store_var(var);
	int no_of_min;
	cin >> no_of_min;
	while (no_of_min >= pow(var, 2))
	{
		cerr << "error\n";
		cin >> no_of_min;
	}
	int minterm;
	for (int i = 0; i < no_of_min; i++)
	{
		cin >> minterm;
		minterms.add_Rear(minterm);
	}
	int no_of_dont_care;
	cin >> no_of_dont_care;
	while (no_of_dont_care > (pow(var, 2)-no_of_min))
		cin >> no_of_dont_care;
	int dont_care;
	for (int i = 0; i < no_of_dont_care; i++)
	{
		cin >> dont_care;
		dont_cares.add_Rear(dont_care);
	}
	system("pause");
}