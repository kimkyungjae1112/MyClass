#include "String.h"

String::String(char c) //문자가 하나 들어왔을 때 생성자
{
	string_content = new char[1]; //동적으로 크기 1 할당
	string_content[0] = c;  //요소 추가
	string_length = 1;  //배열의 현재 길이
	memory_capacity = 1;  //배열의 할당된 메모리
}

String::String(const char* str) //문자열이 들어왔을 때 생성자
{
	string_length = strlen(str);  //문자열의 길이를 가져온다.
	memory_capacity = string_length;  //할당된 메모리를 설정해준다.
	string_content = new char[string_length];  //동적할당

	for (int i = 0; i < string_length; ++i)  //요소 저장
	{
		string_content[i] = str[i];
	}
}

String::String(const String& str)
{
	string_length = str.string_length;
	memory_capacity = str.memory_capacity;
	string_content = new char[string_length];
	for (int i = 0; i < string_length; ++i)
	{
		string_content[i] = str.string_content[i];
	}
}

void String::print() const
{
	for (int i = 0; i < string_length; ++i)
	{
		std::cout << string_content[i];
	}
}

void String::println() const
{
	for (int i = 0; i < string_length; ++i)
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
	return string_length;
}

int String::capacity() const
{
	return memory_capacity;
}

void String::reserve(int size)
{
	if (size > memory_capacity)
	{
		char* temp = new char[size];

		for (int i = 0; i < string_length; ++i)
		{
			temp[i] = string_content[i];
		}
		delete[] string_content;
		string_content = temp;
		memory_capacity = size;
	}
}

char String::at(int i) const
{
	if (i >= string_length || i < 0)
	{
		return NULL;
	}
	else
	{
		return string_content[i];
	}
}

String& String::insert(int loc, const String& str)
{
	String temp(str);
	return insert(loc, temp);

}


//insert, erase, find, operator들 추가하기
//String& String::assign(const String& str)
//{
//	if (str.string_length > memory_capacity)
//	{
//		delete[] string_content;
//
//		string_content = new char[str.string_length];
//		memory_capacity = str.string_length;
//	}
//
//	for (int i = 0; i < str.string_length; ++i)
//	{
//		string_content[i] = str.string_content[i];
//	}
//	string_length = str.string_length;
//	return *this;
//}
//
//String& String::assign(const char* str)
//{
//	int str_length = strlen(str);
//	if (str_length > memory_capacity)
//	{
//		delete[] string_content;
//
//		string_content = new char[str_length];
//		memory_capacity = str_length;
//	}
//
//	for (int i = 0; i < str_length; ++i)
//	{
//		string_content[i] = str[i];
//	}
//	string_length = str_length;
//	return *this;
//}
//
//String& String::append(const String & str)
//{
//	int append_length = string_length + str.string_length;
//	if (append_length > memory_capacity)
//	{
//		char* temp = new char[append_length];
//		for (int i = 0; i < string_length; ++i)
//		{
//			temp[i] = string_content[i];
//		}
//		for (int j = string_length; j < append_length; ++j)
//		{
//			temp[j] = str.string_content[j - string_length];
//		}
//
//		delete[] string_content;
//		string_content = temp;
//		memory_capacity = append_length;
//		return *this;
//	}
//	else
//	{
//		for (int i = 0; i < str.string_length; ++i)
//		{
//			string_content[i + string_length] = str.string_content[i];
//		}
//		return *this;
//	}
//}

char String::operator[](int i)
{
	return string_content[i];
}
