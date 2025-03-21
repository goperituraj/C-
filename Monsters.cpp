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

    ll n, m;
    cin >> n >> m;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    queue<vector<ll>> q;
    pair<ll, ll> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'M')
            {
                q.push({i, j});
            }
            if (v[i][j] == 'A')
            {
                st.first = i;
                st.second = j;
            }
        }
    }
    q.push({st.first, st.second});
    while (!q.empty())
    {
        auto it = q.front();
        ll row = it[0];
        ll col = it[1];
        q.pop();
        if (row - 1 >= 0 && v[row - 1][col] == '.')
        {
            q.push({row - 1, col});
            v[row - 1][col] = (v[row][col] == 'M') ? 'M' : 'U';
        }
        if (row + 1 < n && v[row + 1][col] == '.')
        {
            q.push({row + 1, col});
            v[row + 1][col] = (v[row][col] == 'M') ? 'M' : 'D';
        }
        if (col - 1 >= 0 && v[row][col - 1] == '.')
        {
            q.push({row, col - 1});
            v[row][col - 1] = (v[row][col] == 'M') ? 'M' : 'L';
        }
        if (col + 1 < m && v[row][col + 1] == '.')
        {
            q.push({row, col + 1});
            v[row][col + 1] = (v[row][col] == 'M') ? 'M' : 'R';
        }
    }
    // for (auto it : v)
    // {
    //     cout << it << endl;
    // }
    pair<int, int> finish = {-1, -1};
    for (int i = 0; i < n; i++)
    {
        if (v[i][0] != 'M' && v[i][0] != '.' && v[i][0] != '#')
        {
            finish.first = i;
            finish.second = 0;
        }
        if (v[i][m - 1] != 'M' && v[i][m - 1] != '.' && v[i][m - 1] != '#')
        {
            finish.first = i;
            finish.second = m - 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (v[0][i] != 'M' && v[0][i] != '.' && v[0][i] != '#')
        {
            finish.first = 0;
            finish.second = i;
        }
        if (v[n - 1][i] != 'M' && v[n - 1][i] != '.' && v[n - 1][i] != '#')
        {
            finish.first = n - 1;
            finish.second = i;
        }
    }
    if (finish.first == -1 || finish.second == -1)
    {
        cout << "NO";
        return;
    }
    string ans;
    cout << "YES\n";
    ll x = finish.first;
    ll y = finish.second;
    while (v[x][y] != 'A')
    {
        // cout << x << " " << y << endl;
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