#include "CircularBuffer.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	CircularBuffer<string, 10> buf1; //default constructor
	CircularBuffer<string, 5> buf2(5, "abc"); //constr1
	CircularBuffer<string, 2> buf3{ "123", "456", "789" }; //constr2


	for (int i = 0; i < 15; i++)
	{
		string str = "test";
		str = str + to_string(i);
		buf1.push_back(str);
	}
	
	buf1.print();
	cout << endl;

	
	cout << buf1.begin() << endl;
	cout << buf1.end() << endl;


	cout << endl;
	buf2.print();
	cout << endl;
	buf3.print();

		

	

	return 0;
}