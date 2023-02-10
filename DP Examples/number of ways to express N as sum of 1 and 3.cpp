#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 100;
const int MOD = 1e9 + 7;
int res[N];


int f(int n)
{
    if(n == 1) return 1;
    if(n == 2) return 1;
    if(n == 3) return 2;
    if(res[n] != -1) return res[n];
    int cnt = 0;
    cnt = (cnt + f(n-1))%MOD;
    if(n-3 >= 0) cnt = (cnt + f(n-3)) % MOD;
    return res[n] = cnt;
}

int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    memset(res, -1, sizeof(res));
    cout << f(n) << endl;
}
