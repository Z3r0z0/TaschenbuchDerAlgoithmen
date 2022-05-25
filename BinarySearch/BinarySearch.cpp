#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

bool binarySearch(long searchData, long left, long right);

using namespace std;

vector<long> dataList;

long stepCount = 0;

int main()
{
    long itemCount = 0;
    long searchElement = 0;

    cout << "Item Count:" << endl;
    cin >> itemCount;

    cout << "Select element to Search:" << endl;
    cin >> searchElement;

    for (long i = 0; i <= itemCount; i++)
    {
        dataList.push_back(i);
    }

    cout << (binarySearch(searchElement, 0, dataList.size() - 1) ? "Element has been found!" : "Element hasn't been found!") << endl;
    cout << "Setps: " << stepCount << endl;
}

bool binarySearch(long searchData, long left, long right)
{
    if (left > right)
        return false;
    
    long midle = (left + right) / 2;
    stepCount++;

    if (dataList[midle] == searchData)
        return true;
    else if (dataList[midle] > searchData)
        return binarySearch(searchData, left, midle - 1);
    else if (dataList[midle] < searchData)
        return binarySearch(searchData, midle + 1, right);
        
}
