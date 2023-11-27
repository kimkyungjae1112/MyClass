#include "MyVector.h"

int main()
{
	VECTOR<int> vec;
	vec.push_back(60);
	vec.push_back(20);
	vec.push_back(50);
	vec.push_back(20);
	vec.push_back(10);
	VECTOR<int>::iterator iter = vec.begin();

	for (iter; iter != vec.end(); ++iter)
	{
		cout << *iter << " ";
	}
	vec._sort();
	//Sort(vec.begin(), vec.end());
	cout << endl;

	for (auto& i : vec)
	{
		cout << i << " ";
	}
}