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
    int n;
    cin >> n;
    vector<vector<char>> v(2, vector<char>(n));
    vector<vector<int>> isvis(2, vector<int>(n, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> v[i][j];
        }
    }
    queue<pair<int, int>> q;
    q.push({0, 0});
    isvis[0][0] = 1;
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};
    while (!q.empty())
    {
        auto it = q.front();
        int row = it.first;
        int col = it.second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (nrow >= 0 && nrow <= 1 && ncol >= 0 && ncol < n)
            {
                if (v[nrow][ncol] == '>' && !isvis[nrow][ncol] && !isvis[nrow][ncol + 1])
                {
                    isvis[nrow][ncol] = 1;
                    q.push({nrow, ncol + 1});
                    isvis[nrow][ncol + 1] = 1;
                }
                else if (v[nrow][ncol] == '<' && !isvis[nrow][ncol] && !isvis[nrow][ncol])
                {
                    isvis[nrow][ncol] = 1;
                    q.push({nrow, ncol - 1});
                    isvis[nrow][ncol - 1] = 1;
                }
            }
        }
    }
    if (isvis[1][n - 1])
        cout << "yes" << endl;
    else
        cout << "no" << endl;
}

int main()
{
    fastio();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}