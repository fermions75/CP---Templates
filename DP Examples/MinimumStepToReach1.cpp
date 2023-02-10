#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e4 + 100;
const ll MOD = 998244353;
int res[N];
///minimum step to reach 1 from n
int f(int n)
{
    if(n == 1) return 0;
    int b = INT_MAX, c = INT_MAX;
    if(res[n] != -1) return res[n];
    int a = f(n-1) + 1;
    if(n % 2 == 0)
    {
        b = f(n / 2) + 1;
    }
    if(n % 3 == 0)
    {
        c = f(n / 3) + 1;
    }
    return res[n] = min(a, min(b, c));
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

