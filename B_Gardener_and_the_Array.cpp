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
        vector<vector<ll>> data(n);
        map<ll, ll> mp;
        for (int i = 0; i < n; i++)
        {
            ll k;
            cin >> k;
            data[i].resize(k);
            for (int j = 0; j < k; j++)
            {
                cin >> data[i][j];
                mp[data[i][j]]++;
            }
        }
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            bool f = true;
            for (int j = 0; j < data[i].size(); j++)
            {
                if (mp[data[i][j]] == 1)
                    f = false;
            }
            if (f)
            {
                cout << "Yes" << endl;
                flag = false;
                break;
            }
        }

        if (flag)
            cout << "No" << endl;
    }
    return 0;
}
