#include <bits/stdc++.h>
using namespace std;
void solve()
{
    long long n, m;
    cin >> n >> m;

    vector<long long> a(n), b(m);
    long long val;

    long long i = 0;
    while (i < n)
    {
        cin >> a[i];
        i++;
    }

    priority_queue<long long> max_heap;
    i = 0;
    while (i < m)
    {
        cin >> b[i];
        max_heap.push(b[i]);
        i++;
    }

    sort(a.begin(), a.end());

    long long idx = n - 1;
    bool f = true;
    while (!max_heap.empty())
    {
        if (max_heap.size() > n)
        {
            f = false;
            break;
        }

        long long current_b = max_heap.top();
        max_heap.pop();
        if (current_b < a[idx])
        {
            cout << "NO" << endl;
            return;
        }

        if (current_b == a[idx])
        {
            idx--;
        }
        else
        {
            max_heap.push(current_b / 2);
            max_heap.push(current_b - current_b / 2);
        }
    }
    if (!f)
    {
        cout << "no" << endl;
        return;
    }
    if (idx == -1)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
