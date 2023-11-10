#pragma once
#include <iostream>

class String
{
	int string_length;         //현재 문자열의 길이
	int memory_capacity;    //현재 할당된 메모리
	char* string_content;

public:
	String(const char c);       //문자 생성자
	String(const char* str);    //문자열 생성자
	String(const String& str);  //복사 생성자
	
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
