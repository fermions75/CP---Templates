#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e3 + 100;
const int MOD = 1e9 + 7;
int res[N];
int ress[N][N];
vector<int>v;
/// number of ways to express N as sum of integers O(n^2)
int f(int n)
{
    if(n == 0)
    {
        for(auto it: v) cout << it << " ";
        cout << endl;
        return 1;
    }
    //if(res[n] != -1) return res[n];
    int cnt = 0;
    for(int i=1; i<=n; i++)
    {
        if(n - i >= 0)
        {
            v.push_back(i);
            cnt = (cnt + f(n - i)) % MOD;
            v.pop_back();
        }
    }
    //return res[n] = cnt;
    return cnt;
}

int f1(int n, int idx) /// only sorted way
{
    if(n == 0)
    {
        for(auto it: v) cout << it << " ";
        cout << endl;
        return 1;
    }
    if(ress[idx][n] != -1) return ress[idx][n];
    int cnt = 0;
    for(int i=idx; i<=n; i++)
    {
        if(n - i >= 0)
        {
            v.push_back(i);
            cnt = (cnt + f1(n - i, i)) % MOD;
            v.pop_back();
        }
    }
    return ress[idx][n] = cnt;
}

int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    memset(ress, -1, sizeof(ress));
    memset(res, -1, sizeof(res));
    //cout << f(n) << endl;
    cout << f1(n, 1) << endl;
}

