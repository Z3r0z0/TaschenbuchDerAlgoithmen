#include <iostream>
#include <vector>

using namespace std;

vector<long> quicksort(vector<long> list, long start, long end);

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

	dataList = quicksort(dataList, 0, dataList.size() - 1);

	for (long i = 0; i < dataList.size(); i++)
		cout << dataList[i] << endl;
}

vector<long> quicksort(vector<long> list, long start, long end)
{
	if (list.size() <= 1)
	{
		return list;
	}

	long pivot = list[start];
	long left = start;
	long right = end;

	while (left <= right)
	{
		while (list[left] < pivot)
		{
			left++;
		}

		while (list[right] > pivot)
		{
			right--;
		}

		if (left <= right)
		{
			if (left < right)
			{
				long temp = list[left];
				list[left] = list[right];
				list[right] = temp;
			}

			left++;
			right--;
		}

		if (start < right)
		{
			list = quicksort(list, start, right);
		}

		if (left < end)
		{
			list = quicksort(list, left, end);
		}

		return list;
	}
}