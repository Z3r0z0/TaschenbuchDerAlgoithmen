#include <iostream>
#include <vector>

int pack(int n, int M);
int maximum(int a, int b);

using namespace std;

int dp[2005][2005];

vector<int> v;
vector<int> m;

int main()
{
    int M;
    int n;

    scanf("%d %d", &M, &n);

    for (int i = 0; i < n; i++)
    {
        int tempValue = 0;
        int tempMasse = 0;

        scanf("%d %d", &tempMasse, &tempValue);

        m.push_back(tempMasse);
        v.push_back(tempValue);
    }

    printf("%d", pack(n, M));
}

int pack(int n, int M)
{
    if (dp[M][n] != 0)
    {
        return dp[M][n];
    }

    if (M == 0 || n == 0)
    {
        return 0;
    }
    else
    {
        int value1 = pack(n - 1, M);
        int value2 = 0;

        if (M - m[(n - 1)] < 0)
        {
            return dp[M][n] = value1;
        }
        else
        {
            value2 = pack(n - 1, M - m[(n - 1)]) + v[(n - 1)];
        }

        return dp[M][n] = maximum(value1, value2);
    }
}

int maximum(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}
