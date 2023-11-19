#include "MyVector.h"
#include <string>
int main()
{
	MyVector<std::string> mv;

	mv.push_back("a");
	mv.push_back("b");

	for (int i = 0; i < mv.size(); ++i)
	{
		std::cout << mv[i] << " ";
	}
	std::cout << std::endl;
	std::cout << mv.size();
	std::cout << std::endl;
	mv.push_back("c");
	mv.push_back("d");
	mv.push_back("e");
	for (int i = 0; i < mv.size(); ++i)
	{
		std::cout << mv[i] << " ";
	}

	std::cout << std::endl;
	std::cout << mv.capacity() << std::endl;

}