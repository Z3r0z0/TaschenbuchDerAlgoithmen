
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<long> getPrimeList(long n);

int main()
{
    long max = 0;

    cout << "Insert max value: ";
    cin >> max;

    vector<long> primes = getPrimeList(max);

    for (long i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << endl;
    }
}

vector<long> getPrimeList(long n)
{
    vector<long> primes;
    vector<bool> isPrime = vector<bool>(n, true);

    isPrime[0] = false;
    isPrime[1] = false;

    for (long i = 2; i < n; i++)
    {
        if (isPrime[i])
        {
            primes.push_back(i);

            for (unsigned j = i * i; j < n; j += i)
                isPrime[j] = false;
        }
    }

    return primes;
}