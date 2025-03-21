#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;

    string t = s;
    for (int i = 0; i < n; i++)
    {
        if (i < n / 2)
            t[i] = 'R';
        else
            t[i] = 'L';
    }

    vector<int> original(n);
    int max_value = 0;
    vector<int> diff;
    int cnt = 0;

    for (int i = 0; i < n / 2; i++)
    {
        max_value += 2 * max(i, n - i - 1);
    }
    if (n % 2)
    {
        max_value += n / 2;
    }
    int k = n - 1;
    for (int i = 0; i <= n / 2; i++)
    {
        if (s[i] != t[i] && k >= 0)
        {
            if (i == n / 2 && n % 2)
                continue;
            cnt++;
            diff.push_back(k);
            // diff.push_back(k);
        }
        k -= 2;
    }
    k = n - 1;
    for (int i = n - 1; i >= n / 2; i--)
    {
        if (s[i] != t[i] && k >= 0)
        {
            if (i == n / 2 && n % 2)
                continue;
            cnt++;
            diff.push_back(k);
        }
        k -= 2;
    }

    sort(diff.rbegin(), diff.rend());

    vector<int> prefix_sum(diff.size() + 1, 0);
    for (int i = 0; i < diff.size(); i++)
    {
        prefix_sum[i + 1] = prefix_sum[i] + diff[i];
    }

    vector<long long> ans(n + 1, 0);
    for (int k = 1; k <= n; k++)
    {
        if (cnt - k >= 0)
            ans[k] = max_value - prefix_sum[cnt - k];
        else
            ans[k] = max_value;
        cout << ans[k] << " ";
    }
    cout << "\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
