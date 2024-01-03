#pragma once
#include "header.h"
namespace STD
{
	class istream
	{
	private:
		void input(const int& i) { scanf_s("%d", &i); }
		void input(const float& f) { scanf_s("%f", &f); }
		void input(const double& d) { scanf_s("%lf", &d); }
		void input(const char& c) { scanf_s("%c", &c); }
		void input(const char* c) { scanf_s("%s", &c); }
		void input(const std::string& str) { scanf_s("%s", &str); }
	
	public:
		istream& operator>>(const int& i)
		{
			input(i);
			return *this;
		}
		istream& operator>>(const float& f)
		{
			input(f);
			return *this;
		}
		istream& operator>>(const double& d)
		{
			input(d);
			return *this;
		}
		istream& operator>>(const char& c)
		{
			input(c);
			return *this;
		}
		istream& operator>>(const char* c)
		{
			input(c);
			return *this;
		}
		istream& operator>>(const std::string& str)
		{
			input(str);
			return *this;
		}
	};

	istream cin;
}