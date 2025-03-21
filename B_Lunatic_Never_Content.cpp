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
ll findGCD(vector<ll> &nums)
{
    if (nums.empty())
        return 0;
    int result = nums[0];
    for (int num : nums)
    {
        result = __gcd(result, num);
        if (result == 1)
            break;
    }
    return result;
}
void solve()
{

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<ll> dup = v;

    int i = 0, j = n - 1;
    set<ll> st;
    ll result = findGCD(v);
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    while (i < j)
    {
        st.insert(abs(v[i] - v[j]));
        i++;
        j--;
    }
    if (st.size() == 1)
    {
        ll x;
        for (auto it : st)
        {
            x = it;
            if (x == 0)
            {
                cout << 0 << endl;
                return;
            }
        }
        if (x == 0)
        {
            cout << 0 << endl;
        }
        else
            cout << max(x, result) << endl;
    }
}

int main()
{
    fastio();

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}