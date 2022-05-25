#include <vector>
#include <queue>

int bfs(int start, int target);

using namespace std;

vector<vector<int> > graph;
queue<int> q;

bool visited[1000005];
std::vector<int> lengtht;

int m;
int n;

int main()
{
    scanf("%d %d", &n, &m);

    graph.resize(n);

    int a = 0;
    int b = 0;

    lengtht.resize(n);

    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);

        graph[(a - 1)].push_back((b - 1));
        graph[(b - 1)].push_back((a - 1));
    }

    printf("%d", bfs(0, (n - 1)));
}

int bfs(int point, int target)
{
    int counter = 0;

    q.push(point);

    lengtht[point] = 0;
    visited[point] = true;

    while (!q.empty())
    {
        int v = q.front();

        if (v == target)
        {
            return lengtht[target];
        }
        else
        {
            for (int i = 0; i < graph[v].size(); i++)
            {
                if (visited[graph[v][i]] == false)
                {
                    q.push(graph[v][i]);

                    lengtht[graph[v][i]] = (lengtht[v] + 1);
                    visited[graph[v][i]] = true;
                }
            }

            q.pop();
        }
    }

    return -1;
}