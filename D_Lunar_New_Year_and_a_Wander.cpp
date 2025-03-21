// Step-by-step guide:
// 1. Read the problem statement carefully.
// 2. Visualize and dry-run examples.
// 3. Implement the solution here.
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve()
{

    ll n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, std::greater<int>> pq;
    pq.push(1);
    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<int> ans;
    // ans.push_back(1)
    vector<int> isvis(n + 1, 0);
    isvis[1] = 1;
    while (pq.size() > 0)
    {
        int el = pq.top();
        pq.pop();
        ans.push_back(el);
        for (auto it : adj[el])
        {
            if (!isvis[it])
            {

                pq.push(it);
                isvis[it] = 1;
            }
        }
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
}

int main()
{
    fastio();

    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}