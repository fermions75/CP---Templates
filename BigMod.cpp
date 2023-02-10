ll bigMod (ll a, ll p, ll m)   // returns (a^p) % m
{
    ll res = 1 % m, x = a % m;
    while ( p > 0 )
    {
        if ( (p & 1) > 0 ) res = ( res * x ) % m;
        x = ( x * x ) % m;
        p >>= 1;
    }
    return res;
}
