#include "my_iostream.h"

My_std::ostream::ostream() : len(0){}

void My_std::ostream::print(const char* str)
{
	len += printf("%s", str);
}

void My_std::ostream::print(int i)
{
	len += printf("%d", i);
}

void My_std::ostream::print(double d)
{
	len += printf("%f", d);
}

My_std::ostream& My_std::ostream::operator<<(const char* str)
{
	print(str);
	return *this;
}

My_std::ostream& My_std::ostream::operator<<(int i)
{
	print(i);
	return *this;
}

My_std::ostream& My_std::ostream::operator<<(double d)
{
	print(d);
	return *this;
}

My_std::ostream& My_std::ostream::operator<<(ostream& (*f)(ostream&))
{
	return f(*this);
}


My_std::ostream My_std::endl(ostream& p)
{
	printf("\n");
	return p;
}

int main()
{
	My_std::cout << "Hi" << 123 << My_std::endl;
}