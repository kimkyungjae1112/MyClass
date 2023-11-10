#include "String.h"

String::String(char c) //���ڰ� �ϳ� ������ �� ������
{
	string_content = new char[1]; //�������� ũ�� 1 �Ҵ�
	string_content[0] = c;  //��� �߰�
	string_length = 1;  //�迭�� ���� ����
	memory_capacity = 1;  //�迭�� �Ҵ�� �޸�
}

String::String(const char* str) //���ڿ��� ������ �� ������
{
	string_length = strlen(str);  //���ڿ��� ���̸� �����´�.
	memory_capacity = string_length;  //�Ҵ�� �޸𸮸� �������ش�.
	string_content = new char[string_length];  //�����Ҵ�

	for (int i = 0; i < string_length; ++i)  //��� ����
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


//insert, erase, find, operator�� �߰��ϱ�
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
