#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define fastio()             \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0)

const ll MOD = 1e9 + 7;
const ll INF = 1e18;

void solve(int testCase)
{
    ll n;
    cin >> n;
    string s;
    cin >> s;

    stack<pair<char, ll>> st;
    for (int i = 0; i < n; i++)
    {
        if (st.empty() || (st.top().first == ')' && s[i] == '(') ||
            (st.top().first == '(' && s[i] == '(') ||
            (st.top().first == ')' && s[i] == ')'))
        {
            st.push({s[i], i});
        }
        else
        {
            st.pop();
        }
    }

    if (st.size() % 2 != 0)
    {
        cout << -1 << endl;
        return;
    }

    ll cnt1 = 0, cnt2 = 0;
    vector<ll> idx1;
    vector<ll> idx2;

    while (!st.empty())
    {
        char ch = st.top().first;
        ll idx = st.top().second;
        st.pop();
        if (ch == '(')
        {
            cnt1++;
            idx1.push_back(idx);
        }
        else
        {
            cnt2++;
            idx2.push_back(idx);
        }
    }

    // if (!idx1.empty() && !idx2.empty() && s[idx2[0]] == ')' && s[idx1[idx1.size() - 1]] == '(')
    // {
    stack<pair<char, ll>> st2;
    bool valid = true;
    for (int i = n - 1; i >= 0; i--)
    {
        if (st2.empty() || (st2.top().first == ')' && s[i] == '(') ||
            (st2.top().first == '(' && s[i] == '(') ||
            (st2.top().first == ')' && s[i] == ')'))
        {
            st2.push({s[i], i});
        }
        else
        {
            st2.pop();
        }
    }
    if (st2.size() == 0)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }
    // }

    if (cnt1 != cnt2)
    {
        cout << -1 << endl;
        return;
    }

    if ((cnt1 == 0 && cnt2 == 0) || cnt1 + cnt2 == n)
    {
        cout << 1 << endl;
        for (int i = 0; i < n; i++)
        {
            cout << 1 << " ";
        }
        cout << endl;
        return;
    }

    vector<ll> ans(n, 1);
    for (ll i : idx1)
    {
        ans[i] = 2;
    }
    for (ll i : idx2)
    {
        ans[i] = 2;
    }

    cout << 2 << endl;
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main()
{
    fastio();

    int t;
    cin >> t;
    for (int testCase = 1; testCase <= t; testCase++)
    {
        solve(testCase);
    }

    return 0;
}
