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
        vector<ll> v(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
        }

        ll mn = 1;
        ll mx = n;
        ll i = 1, j = n;
        bool valid = true;

        while (i < j)
        {
            if (v[i] == mn)
            {
                i++;
                mn++;
            }
            else if (v[i] == mx)
            {
                i++;
                mx--;
            }
            else if (v[j] == mn)
            {
                j--;
                mn++;
            }
            else if (v[j] == mx)
            {
                j--;
                mx--;
            }
            else
            {

                cout << i << " " << j << endl;
                valid = false;
                break;
            }
        }

        if (valid)
        {
            cout << -1 << endl;
        }
    }

    return 0;
}
