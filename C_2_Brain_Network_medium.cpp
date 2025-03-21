#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
bool visited[MAXN];
int farthestNode, maxDistance;

void dfs(int node, int distance)
{
    visited[node] = true;
    if (distance > maxDistance)
    {
        maxDistance = distance;
        farthestNode = node;
    }
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, distance + 1);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    memset(visited, false, sizeof(visited));
    maxDistance = 0;
    dfs(1, 0);

    memset(visited, false, sizeof(visited));
    maxDistance = 0;
    dfs(farthestNode, 0);

    cout << maxDistance << endl;

    return 0;
}
