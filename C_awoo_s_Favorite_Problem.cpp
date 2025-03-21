#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t, n, i, j, n1, a_i, b_i, c_i;
    string a, b;
    cin >> t;

    for (; t--;)
    {
        cin >> n;
        a_i = b_i = c_i = -1;

        cin >> a;
        cin >> b;

        n1 = 0;

        queue<ll> qa, qb, qc;

        for (i = 0; i < n; i++)
        {
            if (a[i] == 'a')
            {
                qa.push(i);
            }
            else if (a[i] == 'b')
            {
                qb.push(i);
            }
            else
            {
                qc.push(i);
            }
        }

        if (qa.empty() == false)
        {
            a_i = qa.front();
        }

        if (qb.empty() == false)
        {
            b_i = qb.front();
        }

        if (qc.empty() == false)
        {
            c_i = qc.front();
        }

        for (i = 0; i < n; i++)
        {

            if (b[i] == 'a')
            {
                if (a[i] == 'a')
                {
                    n1++;
                }
                else
                    break;
            }
            else if (b[i] == 'b')
            {
                if (a[i] == 'b' || (b_i < c_i) || c_i == -1)
                {
                    n1++;
                }
            }
        }
    }