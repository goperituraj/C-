#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    long long n, q;
    cin >> n >> q;

    vector<long long> arr(n);
    long long sum = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    set<ll> updatedIndices;
    long long globalValue = -1;

    for (int i = 0; i < q; ++i)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            long long idx, x;
            cin >> idx >> x;
            --idx;

            if (globalValue != -1 && updatedIndices.find(idx) == updatedIndices.end())
            {
                sum += x - globalValue;
                updatedIndices.insert(idx);
            }
            else
            {
                sum += x - arr[idx];
            }
            arr[idx] = x;
        }
        else if (t == 2)
        {
            long long x;
            cin >> x;

            globalValue = x;
            sum = x * n;

            updatedIndices.clear();
        }
        cout << sum << endl;
    }

    return 0;
}
