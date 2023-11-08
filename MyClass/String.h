#pragma once
#include <iostream>

class String
{
	int content_length;
	int capacity_allocation;
	char* string_content;

public:
	String(const char c);
	String(const char* str);
	String(const String& str);
	
	void print() const;
	void println() const;

	int strlen(const char* str);
	int length() const;
	int capacity() const;



	void append(const char* str);
	


	int reserve(int n);
	int find(const String& str);

	String& erase(int loc, int num);
	String& assign(const char* str);
	String& operator+(const String& str);
	String& operator=(const String& str);
	
	/*insert
	assign*/
};
