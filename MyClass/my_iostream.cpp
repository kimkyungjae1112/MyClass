#include "my_iostream.h"

void std::ostream::print(char* str)
{
	len += printf("%s ", str);
}

void std::ostream::print(int i)
{
	len += printf("%d ", i);
}

void std::ostream::print(double d)
{
	len += printf("%lf ", d);
}

std::ostream& std::ostream::operator<<(char* str)
{
	print(str);
	return *this;
}

std::ostream& std::ostream::operator<<(int i)
{
	print(i);
	return *this;
}

std::ostream& std::ostream::operator<<(double d)
{
	print(d);
	return *this;
}

std::ostream& std::ostream::operator<<(ostream& (*f)(ostream&))
{
	return f(*this);
}


std::ostream std::endl(ostream& p)
{
	printf("\n");
	return p;
}
