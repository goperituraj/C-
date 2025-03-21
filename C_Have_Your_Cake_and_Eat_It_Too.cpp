#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll tot = 0;
        vector<vector<ll>> v(3, vector<ll>(n));
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
                if (i == 0)
                    tot += v[i][j];
            }
        }
        tot = ceil((double)tot / 3);
        // cout << tot << endl;
        vector<ll> arr = {0, 1, 2};
        bool flag = true;

        for (int i = 0; i < 6; i++)
        {
            ll idx1 = -1, idx2 = -1, idx3 = -1;
            ll sum = 0;

            for (int k = 0; k < n; k++)
            {
                sum += v[arr[0]][k];
                // cout << sum << endl;
                if (sum >= tot)
                {
                    idx1 = k;
                    break;
                }
            }
            // cout << idx1 << endl;
            sum = 0;
            for (int k = idx1 + 1; k < n; k++)
            {
                sum += v[arr[1]][k];
                if (sum >= tot)
                {
                    idx2 = k;
                    break;
                }
            }
            // cout << idx2 << endl;

            sum = 0;
            for (int k = idx2 + 1; k < n; k++)
            {
                sum += v[arr[2]][k];
                if (sum >= tot)
                {
                    idx3 = k;
                    break;
                }
            }
            // cout << idx3 << endl;

            if (idx1 != -1 && idx2 != -1 && idx3 != -1)
            {
                vector<pair<ll, ll>> ans(3);
                ans[arr[0]] = {1, idx1 + 1};
                ans[arr[1]] = {idx1 + 2, idx2 + 1};
                ans[arr[2]] = {idx2 + 2, idx3 + 1};
                for (int i = 0; i < 3; i++)
                {
                    cout << ans[i].first << " " << ans[i].second << " ";
                }
                cout << endl;

                flag = false;
                break;
            }

            next_permutation(arr.begin(), arr.end());
        }

        if (flag)
            cout << -1 << endl;
    }
}
