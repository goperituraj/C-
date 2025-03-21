
    sort(vp.begin(), vp.end(), comp);
    ll low = vp[0][0];
    ll high = vp[0][1];
    for (int i = 1; i < n - 1; i++)
    {
        if (vp[i][0] >= low &&