#include "String.h"

String::String(char c)
{
	string_content = new char[1];
	string_content[0] = c;
	content_length = 1;
	capacity_allocation = 1;
}

String::String(const char* str) : content_length(0)
{
	content_length = strlen(str);
	capacity_allocation = content_length;
	string_content = new char[content_length];

	for (int i = 0; i < content_length; ++i)
	{
		string_content[i] = str[i];
	}
}

String::String(const String& str)
{
	content_length = str.content_length;
	capacity_allocation = str.capacity_allocation;
	string_content = new char[content_length];
	for (int i = 0; i < content_length; ++i)
	{
		string_content[i] = str.string_content[i];
	}
}

void String::print() const
{
	for (int i = 0; i < content_length; ++i)
	{
		std::cout << string_content[i];
	}
}

void String::println() const
{
	for (int i = 0; i < content_length; ++i)
	{
		std::cout << string_content[i]; 
	}
	std::cout << '\n';
}

int String::strlen(const char* str)
{
	int answer = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		answer++;
		i++;
	}
	return answer;
}

int String::length() const
{
	return content_length;
}

int String::capacity() const
{
	return capacity_allocation;
}

String& String::assign(const char* str)
{
	int str_length = strlen(str);
	if (str_length > capacity_allocation)
	{
		string_content = new char[capacity_allocation * 2];

	}
	
}

int main()
{
	String str = "abc";
	str.print();
}