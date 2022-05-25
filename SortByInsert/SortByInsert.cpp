#include <iostream>
#include <vector>
#include <random>

void sortbyinstert();

using namespace std;

vector<long> dataList;

int main()
{
	long listSize = 0;

	cout << "List size:" << endl;

	cin >> listSize;

	for (long i = 0; i < listSize; i++) 
	{
		dataList.push_back(rand() % (listSize * 10));
	}

	sortbyinstert();

	for (long i = 0; i < listSize; i++)
	{
		cout << dataList[i] << endl;
	}
}

void sortbyinstert()
{
	for (long i = 2; i < dataList.size(); i++)
	{
		long temp = dataList[i];
		long j = i - 1;

		while (j >= 1 && dataList[j] > temp)
		{
			dataList[j + 1] = dataList[j];
			j = j - 1;
		}

		dataList[j] = temp;
	}
}
