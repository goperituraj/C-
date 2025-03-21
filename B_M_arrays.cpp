#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        map<int, int> cnt;
        while (n--)
        {
            int x;
            cin >> x;
            cnt[x % m]++;
        }
        int ans = 0;
        set<int> processed;

        for (auto c : cnt)
        {
            int num = c.first;
            if (processed.find(num) != processed.end())
            {
                continue;
            }

            if (num == 0)
            {
                ans++;
                processed.insert(num);
            }
            else if (2 * num == m)
            {
                ans++;
                processed.insert(num);
            }
            else if (cnt.find(m - num) != cnt.end())
            {
                int x = c.second, y = cnt[m - num];
                ans += 1 + max(0, abs(x - y) - 1);
                processed.insert(num);
                processed.insert(m - num);
            }
            else
            {
                ans += c.second;
                processed.insert(num);
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
