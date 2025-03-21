#include <bits/stdc++.h>
using namespace std;
#include <cctype>
#define M 1000000007
#define ll long long
#define rep(i, s, n) for (ll i = s; i < n; i++)
#define pb push_back
#define F first
#define S second
#define mp make_pair
#define endl "\n"
#define all(v) v.begin(), v.end()
#define lower(s) transform(s.begin(), s.end(), s.begin(), ::tolower)
#define upper(s) transform(s.begin(), s.end(), s.begin(), ::toupper)
#define srt(v) sort(v.begin(), v.end())
#define rsrt(v) sort(v.rbegin(), v.rend())
#define vi vector<ll>
#define pll pair<ll, ll>
#define vp vector<pair<ll, ll>>
#define seea(a, n)             \
    for (ll i = 0; i < n; i++) \
    {                          \
        cin >> a[i];           \
    }
#define seed(a, n, m)              \
    for (ll i = 0; i < n; i++)     \
    {                              \
        for (ll j = 0; j < m; j++) \
        {                          \
            cin >> a[i][j];        \
        }                          \
    }
#define show(a, n)             \
    for (ll i = 0; i < n; i++) \
    {                          \
        cout << a[i] << " ";   \
    }                          \
    cout << endl;
#define yy cout << "YES" << "\n";
#define nn cout << "NO" << "\n";

bool isArraySorted(vector<ll> &arr)
{
    for (size_t i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false; // Array is not sorted
        }
    }
    return true; // Array is sorted
}

int fMSB(int num)
{
    return 63 - __builtin_clzll(num);
}

bool comp(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first > b.first;
}

bool comp2(pair<ll, ll> a, pair<ll, ll> b)
{
    return a.first < b.first;
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

bool check(vector<ll> &arr, ll x)
{
    ll l = 0;
    ll r = arr.size() - 1;
    bool f = true;
    while (l <= r)
    {
        while (arr[l] == x)
            l++;
        while (arr[r] == x)
            r--;
        if (l > r)
            break;
        if (arr[l] != arr[r])
        {
            f = false;
            break;
        }
        l++;
        r--;
    }
    return f;
}

int func(vector<ll> &arr, int x)
{
    int lo = 0;
    int hi = x;
    int ans = 0;
    while (lo <= hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] >= x - mid + 1)
        {
            ans = x - mid + 1;
            hi = mid - 1;
        }
        else
        {
            lo = mid + 1;
        }
    }
    return ans;
}

void solve()
{
    // cout<<gcd(2,-6);
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    rep(i, 0, n)
    {
        cin >> a[i];
    }
    rep(i, 0, n)
    {
        cin >> b[i];
    }
    // rep(i,0,n){
    //     if(a[i]<0 && b[i]<0){
    //         a[i]*=-1;
    //         b[i]*=-1;
    //     }else if(a[i]>0 && b[i]<0){
    //         a[i]*=-1;
    //         b[i]*=-1;
    //     }
    // }
    map<pair<pair<ll, ll>, ll>, ll> mpp;
    // ll cnt=0;
    ll cnt = 0;
    rep(i, 0, n)
    {
        ll sign = (a[i] * b[i]) / abs((a[i] * b[i]));
        // cout<<abs(-1);
        if (a[i] != 0)
        {
            ll k = gcd(abs(a[i]), abs(b[i]));
            k = abs(k);
            auto s = make_pair(make_pair(abs(a[i] / k), abs(b[i] / k)), sign);
            mpp[s]++;
        }
        if (a[i] == 0 && b[i] == 0)
            cnt++;
    }

    ll ans = 0;
    for (auto it : mpp)
    {
        ans = max(ans, it.second);
        // cout<<it.first.first.first<<" "<<it.first.first.second<<endl;
    }
    // cout<<cnt;
    cout << ans + cnt << endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
}
