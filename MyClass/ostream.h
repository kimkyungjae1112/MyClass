#pragma once
#include "header.h"
namespace STD
{
	class ostream
	{
	private:
		int len;

		void print(const int& i) { len += printf("%d", i); }
		void print(const float& f) { len += printf("%f", f); }
		void print(const double& d) { len += printf("%lf", d); }
		void print(const char& c) { len += printf("%c", c); }
		void print(const char* c) { len += printf("%s", c); }
		void print(const std::string str)
		{ 
			len += printf("%s", str.c_str()); 
		}
	public:
		ostream& operator<<(const int& i)
		{
			print(i);
			return *this;
		}
		ostream& operator<<(const float& f)
		{
			print(f);
			return *this;
		}
		ostream& operator<<(const double& d)
		{
			print(d);
			return *this;
		}
		ostream& operator<<(const char& c)
		{
			print(c);
			return *this;
		}
		ostream& operator<<(const char* c)
		{
			print(c);
			return *this;
		}
		ostream& operator<<(const std::string str)
		{
			print(str);
			return *this;
		}
		ostream& operator<<(ostream&(*p)(ostream& os))
		{
			return p(*this);
		}
	};

	ostream& endl(ostream& os)
	{
		printf("\n");
		return os;
	}

	ostream cout;
}