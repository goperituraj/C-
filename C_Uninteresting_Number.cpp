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

void solve()
{

    string s;
    cin >> s;
    ll n = s.length();
    ll sum = 0;
    ll cnt2 = 0, cnt3 = 0;
    for (int i = 0; i < n; i++)
    {

        sum += s[i] - '0';
        if (s[i] - '0' == 2)
            cnt2++;
        else if (s[i] - '0' == 3)
            cnt3++;
    }
    vector<ll> st;
    ll i = 6;
    ll mxpossible = 6 * cnt3 + 2 * cnt2;
    st.push_back(0);
    while (cnt3)
    {
        st.push_back(i);
        i += 6;
        cnt3--;
    }
    // i=2;
    // while (cnt2)
    // {
    //     st.insert(i);
    //    if(st.find(i)!=st.end()) cnt3--;
    //     i += 2;
    // }

    if (sum % 9 == 0)
    {
        cout << "Yes" << endl;
        return;
    }
    else
    {
        ll rem = 9 - sum % 9;
        while (rem <= mxpossible)
        {
            ll low = 0;
            ll high = st.size() - 1;
            ll ans = -1;
            while (low <= high)
            {
                ll mid = (low + high) / 2;
                if (st[mid] > rem)
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                    ans = mid;
                }
            }
            if (st[ans] == rem)
            {
                cout << "YEs" << endl;
                return;
            }
            else
            {
                if (rem - st[ans] <= cnt2 * 2 && (rem - st[ans]) % 2 == 0)
                {
                    cout << "yes" << endl;
                    return;
                }
                rem += 9;
            }
        }
    }
    cout << "No" << endl;
    return;
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