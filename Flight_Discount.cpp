#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define int long long
const int INF = LLONG_MAX;

const int MAXN = 100005;
vector<vector<pair<int, int>>> adj(MAXN);
vector<vector<int>> dist(MAXN, vector<int>(2, INF));

int n, m;

void solve()
{
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {1, 0}});
    dist[1][0] = 0;

    while (!pq.empty())
    {
        auto it = pq.top();
        int currDist = it.first;
        int city = it.second.first, used = it.second.second;
        pq.pop();

                for (auto edge : adj[city])
        {
            int next = edge.first;
            int price = edge.second;

            if (currDist + price < dist[next][used])
            {
                dist[next][used] = currDist + price;
                pq.push({dist[next][used], {next, used}});
            }

            if (!used && currDist + (price / 2) < dist[next][1])
            {
                dist[next][1] = currDist + (price / 2);
                pq.push({dist[next][1], {next, 1}});
            }
        }
    }

    int result = dist[n][1];
    if (result == INF)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << result << endl;
    }
}

int32_t main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    solve();
    return 0;
}
