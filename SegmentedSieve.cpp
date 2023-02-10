int seg_sieve(ll l, ll r)  // do a sieve before running this function // prints primes of the segment and returns number of primes int he segment
{
    if(l == 1) l++;
    ll arr[r-l+1];
    for(int i=0; i<r-l+1; i++) arr[i] = 1;
    for(int i=0; i<primes.size(); i++)
    {
        ll p = primes[i];

        if(ll(primes[i] * primes[i]) <= r)
        {
            ll j = (l/primes[i]) * primes[i];

            if(j < l) j += primes[i];

            for(; j<=r; j += primes[i])
            {
                if(j != primes[i])
                {
                    arr[j - l] = 0;
                }
            }
        }
    }
    int cnt = 0;
    for(ll i=l; i<=r; i++)  // printing primes of the segments
    {
        if(arr[i-l] == 1)
        {
            cnt++;
            cout << i-l << " ";
        }
    }
    return cnt;
}

