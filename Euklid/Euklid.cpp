
#include <iostream>

int euklid(int a, int b);

using namespace std;

int main()
{
	int a = 0;
	int b = 0;

	cout << "Bitte Wert eingeben: ";
	cin >> a;

	cout << "Bitte Wert eingeben: ";
	cin >> b;

	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

	std::cout << "GGT: " << euklid(a, b);
}

int euklid(int a, int b)
{
	int mod = a % b;
	
	if (mod == 0)
		return b;

	return euklid(b, mod);
}
