#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;
#define ll long long int

int calculate_score(const vector<ll> &a, const vector<ll> &b, const vector<int> &perm)
{
    vector<ll> alice = a, bob = b;
    int turn = 0; // 0 for Alice's turn, 1 for Bob's turn
    int n = a.size();

    for (int i = 0; i < n; i++)
    {
        int color = perm[i];

        // if (alice[color] > 0 && bob[color] > 0)
        // {
        if (turn == 0)
        {
            alice[color]--;
            bob[color] = 0;
        }
        else
        {
            bob[color]--;
            alice[color] = 0;
        }
        turn = 1 - turn; // Switch turn
        // }
    }

    // Calculate the score
    ll remaining_alice = accumulate(alice.begin(), alice.end(), 0);
    ll remaining_bob = accumulate(bob.begin(), bob.end(), 0);

    return (ll)(remaining_alice - remaining_bob);
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<ll> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> perm(n);
        for (int i = 0; i < n; i++)
        {
            perm[i] = i;
        }

        ll best = 1e18;

        do
        {
            ll score = calculate_score(a, b, perm);
            cout << score << endl;
            best = min(best, score);
        } while (next_permutation(perm.begin(), perm.end())); // Try next permutation

        cout << best << endl;
    }

    return 0;
}
