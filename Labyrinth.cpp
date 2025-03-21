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
    ll n, m;
    cin >> n >> m;
    vector<string> v(n);

    pair<ll, ll> st, en;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'A')
                st = {i, j};
            if (v[i][j] == 'B')
                en = {i, j};
        }
    }

    queue<pair<ll, ll>> q;
    q.push(st);
    while (!q.empty())
    {
        auto it = q.front();
        ll row = it.first;
        ll col = it.second;
        q.pop();

        if (row - 1 >= 0 && (v[row - 1][col] == '.' || v[row - 1][col] == 'B'))
        {
            q.push({row - 1, col});
            v[row - 1][col] = 'U';
        }
        if (row + 1 < n && (v[row + 1][col] == '.' || v[row + 1][col] == 'B'))
        {
            q.push({row + 1, col});
            v[row + 1][col] = 'D';
        }
        if (col - 1 >= 0 && (v[row][col - 1] == '.' || v[row][col - 1] == 'B'))
        {
            q.push({row, col - 1});
            v[row][col - 1] = 'L';
        }
        if (col + 1 < m && (v[row][col + 1] == '.' || v[row][col + 1] == 'B'))
        {
            q.push({row, col + 1});
            v[row][col + 1] = 'R';
        }
    }

    if (v[en.first][en.second] == 'B')
    {
        cout << "NO\n";
        return;
    }
    cout << "YES" << endl;

    string ans;
    ll x = en.first, y = en.second;

    while (v[x][y] != 'A')
    {
        ans += v[x][y];
        if (v[x][y] == 'R')
            y--;
        else if (v[x][y] == 'L')
            y++;
        else if (v[x][y] == 'U')
            x++;
        else if (v[x][y] == 'D')
            x--;
    }

    reverse(ans.begin(), ans.end());
    cout << ans.length() << endl;
    cout << ans << endl;
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
