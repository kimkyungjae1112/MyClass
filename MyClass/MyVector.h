#pragma once
#include <iostream>

template<typename T>
class MyVector
{
	T* content;
	int ISize;
	int memory_allocation;

public:
	MyVector() : ISize(-1), memory_allocation(1)
	{
		content = new T[1];
	}

	MyVector(int memory_size) : ISize(-1), memory_allocation(memory_size)
	{
		content = new T[memory_size];
	}

	MyVector(int memory_size, T data) : ISize(-1), memory_allocation(memory_size)
	{
		content = new T[memory_size];
		for (int i = 0; i < memory_size; ++i)
		{
			content[i] = data;
		}
	}

	void push_back(T data)
	{
		if (ISize >= memory_allocation - 1)
		{
			T* temp = new T[memory_allocation * 2];
			for (int i = 0; i < ISize + 1; ++i)
			{
				temp[i] = content[i];
			}
			delete[] content;
			content = temp;
			memory_allocation *= 2;

		}
		content[++ISize] = data;


		//배열의 마지막으로 데이터를 집어넣음
			//집어넣다가 길이가 부족해지면 *2
			//실제 들어있는 내용물과 할당된 메모리 크기는 다를 수 있음
	}

	T pop_back()
	{
		if (ISize >= 0)
		{
			return content[ISize--];
		}
		else
		{
			std::cout << "비어있음" << std::endl;
			return NULL;
		}
	}

	int size()
	{
		return ISize + 1;
	}

	int capacity()
	{
		return memory_allocation;
	}

	T operator[](int n)
	{
		return content[n];
	}
	
	~MyVector()
	{
		delete[] content;
	}

};