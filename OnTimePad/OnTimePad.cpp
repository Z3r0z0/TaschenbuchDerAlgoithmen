

#include <iostream>
#include <vector>

using namespace std;

vector<int> crypt(vector<int> value, vector<int> key);

int main()
{
	vector<int> value = { 1, 0, 1, 0 };
	vector<int> key = { 0, 1, 0, 1 };

	cout << "Value: ";
	for (int i = 0; i < value.size(); i++)
		cout << value[i] << " ";
	cout << endl;

	cout << "Key: ";
	for (int i = 0; i < value.size(); i++)
		cout << key[i] << " ";
	cout << endl;

	vector<int> temp = crypt(value, key);

	cout << "New Value: ";
	for (int i = 0; i < value.size(); i++)
		cout << temp[i] << " ";
	cout << endl;

	temp = crypt(temp, key);

	cout << "Value: ";
	for (int i = 0; i < value.size(); i++)
		cout << temp[i] << " ";
	cout << endl;
}

vector<int> crypt(vector<int> value, vector<int> key) 
{
	vector<int> res;

	for (int i = 0; i < value.size(); i++)
	{
		res.push_back(value[i] ^ key[i]);
	}

	return res;
}


