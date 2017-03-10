#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include"DEQ.h"
using namespace std;
deq<int>dont_cares;
deq<int>minterms;
int var;
int no_of_min;
void compare()
{
	int original_length = minterms.deq_length();
	deq<string>binary_string;
	for(int i=0;i<original_length;i++)
	{
		int binary_no = 0, decimal_no = 0, extra;
		string s;
		minterms.remove_front(decimal_no,binary_no);
		minterms.add_Rear(decimal_no);
		s= to_string(binary_no);
		extra = var - s.length();
		for (int i = 0; i < extra; i++)
			s.insert(0, "0");
		binary_string.special_enqueue(s,decimal_no);
	}
	int dont_care_length = dont_cares.deq_length();
	for (int i = 0; i<dont_care_length; i++)
	{
		int binary_no = 0, decimal_no = 0, extra;
		string s;
		dont_cares.remove_front(decimal_no, binary_no);
		dont_cares.add_Rear(decimal_no);
		s = to_string(binary_no);
		extra = var - s.length();
		for (int i = 0; i < extra; i++)
			s.insert(0, "0");
		binary_string.special_enqueue(s, decimal_no);
	}
	binary_string.sort_nodes();
	binary_string.checking_nodes();
	binary_string.compare();
	system("pause");
}
int main()
{
	cin >> var;
	while (var >= 16||var==0)
	{
		cout << "invalid input" << endl;
		cin >> var;
	}
	minterms.store_var(var);
	dont_cares.store_var(var);
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
		compare();
	system("pause");
}
