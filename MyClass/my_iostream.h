#ifndef MY_IOSTREAM_H
#define MY_IOSTREAM_H
#include <stdio.h>

namespace std
{
	class ostream
	{
	private:
		int len;

	public:
		void print(char* str);
		void print(int i);
		void print(double d);

		ostream& operator<< (char* str);
		ostream& operator<< (int i);
		ostream& operator<< (double d);
		ostream& operator<< (ostream&(*f)(ostream&));
	};

	ostream endl(ostream& p);

	ostream cout;
}
#endif