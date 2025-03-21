#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

bool dfs(int row, int col, int parentRow, int parentCol, char ch, vector<string> &v, vector<vector<int>> &isvis)
{
    int n = v.size();
    int m = v[0].size();

    isvis[row][col] = 2;
    int dx[] = {-1, 0, 0, 1};
    int dy[] = {0, -1, 1, 0};

    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];

        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && v[nrow][ncol] == ch)
        {
            if (nrow == parentRow && ncol == parentCol)
                continue;

            if (isvis[nrow][ncol] == 2)
                return true;

            if (isvis[nrow][ncol] == 0)
            {
                if (dfs(nrow, ncol, row, col, ch, v, isvis))
                    return true;
            }
        }
    }

    isvis[row][col] = 1;
    return false;
}

void solve()
{
    ll n, m;
    cin >> n >> m;
    vector<string> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    vector<vector<int>> isvis(n, vector<int>(m, 0));

    for (char ch = 'A'; ch <= 'Z'; ch++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == ch && isvis[i][j] == 0)
                {
                    if (dfs(i, j, -1, -1, ch, v, isvis))
                    {
                        cout << "Yes" << endl;
                        return;
                    }
                }
            }
        }
    }

    cout << "No" << endl;
}

int main()
{
    fastio();
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
