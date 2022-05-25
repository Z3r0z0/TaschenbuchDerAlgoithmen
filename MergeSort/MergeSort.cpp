#include <iostream>
#include <vector>
#include <random>

using namespace std;

vector<long> mergesort(vector<long> list);
vector<long> merge(vector<long> listA, vector<long> listB);


vector<long> dataList;

int main()
{
	long listSize = 0;
	
	cout << "List size" << endl;
	cin >> listSize;

	for (long i = 0; i < listSize; i++)
	{
		dataList.push_back(rand() % (listSize * 10));
	}

	dataList = mergesort(dataList);

	for (long i = 0; i < dataList.size(); i++)
		cout << dataList[i] << endl;
}


vector<long> mergesort(vector<long> list)
{
	if (list.size() <= 1)
	{
		return list;
	}

	long size = list.size() / 2;

	vector<long> halfA(list.begin(), list.begin() + size);
	vector<long> listA = mergesort(halfA);

	vector<long> halfB(list.begin() + size, list.end());
	vector<long> listB = mergesort(halfB);

	return merge(listA, listB);
}

vector<long> merge(vector<long> listA, vector<long> listB)
{
	vector<long> result;

	while (listA.size() > 0 && listB.size() > 0)
	{
		if (listA[0] <= listB[0])
		{
			result.push_back(listA[0]);
			listA.erase(listA.begin());
		}
		else
		{
			result.push_back(listB[0]);
			listB.erase(listB.begin());
		}
	}

	while (listA.size() > 0)
	{
		result.push_back(listA[0]);
		listA.erase(listA.begin());
	}

	while (listB.size() > 0)
	{
		result.push_back(listB[0]);
		listB.erase(listB.begin());
	}

	return result;
}
