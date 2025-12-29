#include "CircularBuffer.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	CircularBuffer<string, 10> buf1; //default constructor
	CircularBuffer<string, 5> buf2(5, "abc"); //constr1
	CircularBuffer<string, 2> buf3{ "123", "456", "789" }; //constr2
	//filling buffer1 w/ rewriting
	for (int i = 0; i < 15; i++)
	{
		string str = "test";
		str = str + to_string(i);
		buf1.push_back(str);
	}
	//cout w/o position check
	for (int i = 0; i < buf1.capacity(); i++)
	{
		cout << buf1.at(i) << endl;
	}
	cout << endl;
	cout << endl;
	cout << "Oldest element at position " << buf1.begin() << (" (start)") << endl;
	cout << "Newest element at position " << buf1.end() << (" (end)") << endl;
	cout << endl;
	cout << endl;
	//cout w/ position check (from oldest element to newest)
	for (int i = buf1.begin(); true; i++)
	{
		if (i == buf1.capacity()) i = 0;
		cout << buf1.at(i) << endl;
		if (i == buf1.end())
		{
			break;
		}
	}
	cout << endl;
	//cout buf2
	for (int i = buf2.begin(); true; i++)
	{
		if (i == buf2.capacity()) i = 0;
		cout << buf2.at(i) << endl;
		if (i == buf2.end())
		{
			break;
		}
	}
	cout << endl;
	//cout buf3
	for (int i = buf3.begin(); true; i++)
	{
		if (i == buf3.capacity()) i = 0;
		cout << buf3.at(i) << endl;
		if (i == buf3.end())
		{
			break;
		}
	}
	cout << endl;
	//buf capacity
	cout << buf1.capacity() << endl;
	cout << buf2.capacity() << endl;
	cout << buf3.capacity() << endl;
	cout << endl;
	//oldest buffer element plus 6
	cout << buf1.at(buf1.begin() + 6) << endl;
	cout << endl;
	//insert element into position 6 manually
	buf1.insert(buf1.begin() + 6, "ManualInsert");
	for (int i = buf1.begin(); true; i++)
	{
		if (i == buf1.capacity()) i = 0;
		cout << buf1.at(i) << endl;
		if (i == buf1.end())
		{
			break;
		}
	}
	return 0;
}