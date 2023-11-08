#ifndef MY_IOSTREAM_H
#define MY_IOSTREAM_H
#include <stdio.h>

namespace My_std
{
	class ostream
	{
	private:
		int len;

	public:
		ostream();

		void print(const char* str);
		void print(int i);
		void print(double d);

		ostream& operator<< (const char* str);
		ostream& operator<< (int i);
		ostream& operator<< (double d);
		ostream& operator<< (ostream&(*f)(ostream&));
	};

	ostream endl(ostream& p);

	extern ostream cout;
}
#endif