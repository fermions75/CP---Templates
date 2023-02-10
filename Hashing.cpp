#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e6 + 9;
const int MOD = 1e9 + 7;

/// declare primes and mod value for hash
const int p1 = 137;
const int mod1 = 1e9 + 7;
const int p2 = 277;
const int mod2 = 1e9 + 9;

/// bigmod for substr hash
int power(ll n, ll k, int mod)
{
    int ans = 1 % mod;
    n = n % mod;
    if(n < 0) n += mod;
    while(k)
    {
        if(k & 1) ans = (ll) ans * n % mod;
        n = (ll) n * n % mod;
        k >>= 1;
    }
    return ans;
}

/// pre calculate power values of primes
pair<int, int>pw[N], ipw[N];
void prec()
{
    pw[0] = {1,1};
    for(int i=1; i<N; i++)
    {
        pw[i].first = 1LL * pw[i-1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i-1].second * p2 % mod2;
    }
    int inv_p1 = power(p1, mod1-2, mod1);
    int inv_p2 = power(p2, mod2-2, mod2);
    ipw[0] = {1,1};
    for(int i=1; i<N; i++)
    {
        ipw[i].first = 1LL * ipw[i-1].first * inv_p1 % mod1;
        ipw[i].second = 1LL * ipw[i-1].second * inv_p2 % mod2;
    }
}

/// forward hash of the string
pair<int, int> string_hash(string s)
{
    int n = s.size();
    pair<int, int>hs({0,0});
    for(int i=0; i<n; i++)
    {
        hs.first += 1LL * s[i] * pw[i].first % mod1;
        hs.first %= mod1;
        hs.second += 1LL * s[i] * pw[i].second % mod2;
        hs.second %= mod2;
    }
    return hs;
}

/// builds the pref hash array
pair<int, int>pref[N];
void build_pref(string s)
{
    int n = s.size();
    for(int i=0; i<n; i++)
    {
        pref[i].first = 1LL * s[i] * pw[i].first % mod1;
        if(i) pref[i].first = (pref[i].first + pref[i-1].first) % mod1;
        pref[i].second = 1LL * s[i] * pw[i].second % mod2;
        if(i) pref[i].second = (pref[i].second + pref[i-1].second) % mod2;
    }
}

/// get hash from idx i to j
pair<int, int> get_hash(int i, int j)
{
    assert(i<=j);
    pair<int, int>hs({0,0});
    hs.first = pref[j].first;
    if(i) hs.first = (hs.first - pref[i-1].first + mod1) % mod1;
    hs.first = 1LL * hs.first * ipw[i].first % mod1;
    hs.second = pref[j].second;
    if(i) hs.second = (hs.second - pref[i-1].second + mod2) % mod2;
    hs.second = 1LL * hs.second * ipw[i].second % mod2;
    return hs;
}

int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);



}
