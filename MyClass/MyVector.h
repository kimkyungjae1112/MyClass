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


		//�迭�� ���������� �����͸� �������
			//����ִٰ� ���̰� ���������� *2
			//���� ����ִ� ���빰�� �Ҵ�� �޸� ũ��� �ٸ� �� ����
	}

	T pop_back()
	{
		if (ISize >= 0)
		{
			return content[ISize--];
		}
		else
		{
			std::cout << "�������" << std::endl;
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