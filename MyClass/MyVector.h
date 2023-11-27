#pragma once
//#include <iostream>
//
//template<typename T>
//class MyVector
//{
//	T* content;
//	int ISize;
//	int memory_allocation;
//
//public:
//	MyVector() : ISize(-1), memory_allocation(1)
//	{
//		content = new T[1];
//	}
//
//	MyVector(int memory_size) : ISize(-1), memory_allocation(memory_size)
//	{
//		content = new T[memory_size];
//	}
//
//	MyVector(int memory_size, T data) : ISize(-1), memory_allocation(memory_size)
//	{
//		content = new T[memory_size];
//		for (int i = 0; i < memory_size; ++i)
//		{
//			content[i] = data;
//		}
//	}
//
//	void push_back(T data)
//	{
//		if (ISize >= memory_allocation - 1)
//		{
//			T* temp = new T[memory_allocation * 2];
//			for (int i = 0; i < ISize + 1; ++i)
//			{
//				temp[i] = content[i];
//			}
//			delete[] content;
//			content = temp;
//			memory_allocation *= 2;
//
//		}
//		content[++ISize] = data;
//
//
//		//�迭�� ���������� �����͸� �������
//			//����ִٰ� ���̰� ���������� *2
//			//���� ����ִ� ���빰�� �Ҵ�� �޸� ũ��� �ٸ� �� ����
//	}
//
//	T pop_back()
//	{
//		if (ISize >= 0)
//		{
//			return content[ISize--];
//		}
//		else
//		{
//			std::cout << "�������" << std::endl;
//			return NULL;
//		}
//	}
//
//	int size()
//	{
//		return ISize + 1;
//	}
//
//	int capacity()
//	{
//		return memory_allocation;
//	}
//
//	T operator[](int n)
//	{
//		return content[n];
//	}
//	
//	~MyVector()
//	{
//		delete[] content;
//	}
//
//};


#include <iostream>

using namespace std;

template <typename T, typename U> void Sort(U begin, U end, T cmp) //�Լ� ������Ʈ�� ����� sort �Լ� 
{
	for (auto i = begin; i != end; ++i)
	{
		for (auto j = i; j != end; ++j)
		{
			if (cmp(*i, *j))
			{
				auto temp = *i;
				*i = *j;
				*j = temp;
			}
		}
	}
}

template <typename U> void Sort(U begin, U end) //�Լ� ������Ʈ�� ������� ���� sort �Լ�, algorithm ��� �ȿ� �ִ� ��Ʈ�� ������ �� ���� �����Ǿ� ���� ������,,
{
	for (auto i = begin; i != end; ++i)
	{
		for (auto j = i; j != end; ++j)
		{
			if (*i < *j)
			{
				auto temp = *i;
				*i = *j;
				*j = temp;
			}
		}
	}
}


template <typename T> class VECTOR_Iterator //adaptor ���� ����� �����, �ڷᱸ���� �� ��ü�� �ְ� �ڷᱸ�� �ۿ��� �ڷᱸ���� ����Ŵ
{
	T* cursor; //����ؼ� �������� ������

public:
	VECTOR_Iterator(T* p = 0) : cursor(p) {}

	bool operator!=(const VECTOR_Iterator& p)
	{
		return cursor != p.cursor;
	}

	bool operator==(const VECTOR_Iterator& p)
	{
		return cursor == p.cursor;
	}

	VECTOR_Iterator& operator++()
	{
		++cursor;
		return *this;
	}

	VECTOR_Iterator& operator++(int)
	{
		cursor++;
		return *this;
	}

	T& operator* ()
	{
		return *cursor;
	}
};

template <typename T> class VECTOR //�̰� �׳� �� ���� ����
{
	T* content;
	int mSize;
	int mCapacity;
	int mIndex;

public:
	VECTOR(int s = 0) : mSize(s), mCapacity(s), mIndex(0)
	{
		content = new T[mCapacity];
	}

	int size() { return mSize; }
	int capacity() { return mCapacity; }

	void resize(int s)
	{
		mSize = s;
		if (s >= mCapacity)
		{
			mCapacity = s * 2;

			T* temp = new T[mCapacity];
			for (int i = 0; i < mSize; ++i)
			{
				temp[i] = content[i];
			}
			delete[] content;
			content = temp;
		}
	}

	void push_back(const T& data) // �̷��Ե� ���� �ϳ�����.
	{
		if (mIndex == mSize) resize(mSize + 1);
		content[mIndex++] = data;
	}

	typedef VECTOR_Iterator<T> iterator;
	iterator begin() { return iterator(content); }
	iterator end() { return iterator(content + mSize); }
};

