#pragma once
#include <iostream>

class String
{
	int string_length;         //���� ���ڿ��� ����
	int memory_capacity;    //���� �Ҵ�� �޸�
	char* string_content;

public:
	String(const char c);       //���� ������
	String(const char* str);    //���ڿ� ������
	String(const String& str);  //���� ������
	
	void print() const;
	void println() const;

	int strlen(const char* str);
	int length() const;
	int capacity() const;

	void reserve(int size);
	
	char at(int i) const;

	String& insert(int loc, const String& str);
	String& insert(int loc, const char* str);
	String& insert(int loc, char c);

	String& assign(const String& str);
	String& assign(const char* str);
	String& append(const String& str);

	
	
	
	


	char operator[](int i);

	
	//insert
};
