#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

void findPermutations(string s, string k, int n, set<string> &ans)
{
    if (k.length() == n)
    {
        ans.insert(k);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (s[i] != '#')
        {
            char ch = s[i];
            s[i] = '#';
            findPermutations(s, k + ch, n, ans);
            // s[i] = ch;
        }
    }
}

void solve()
{
    string s;
    cin >> s;
    int n = s.length();
    set<string> ans;
    findPermutations(s, "", n, ans);
    cout << ans.size() << "\n";
    for (string m : ans)
    {
        cout << m << endl;
    }
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
