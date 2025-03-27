#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int r, c;
    cin >> r >> c;

    vector<vector<char>> g(r, vector<char>(c));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> g[i][j];
        }
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (g[i][j] == '1')
            {
                bool l = true, t = true;

                for (int k = 0; k < j; k++)
                {
                    if (g[i][k] == '0')
                    {
                        l = false;
                        break;
                    }
                }

                for (int k = 0; k < i; k++)
                {
                    if (g[k][j] == '0')
                    {
                        t = false;
                        break;
                    }
                }

                if (!l && !t)
                {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }

    cout << "YES\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
