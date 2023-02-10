#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 100;
const int MOD = 1e9 + 7;
vector<ll>values, weight;
ll dp[200][100000+5];
int n, w;
ll knapsack(int idx, int capacity)
{
    if(idx >= n) return 0;
    if(dp[idx][capacity] != -1) return dp[idx][capacity];
    ll res = knapsack(idx+1, capacity);
    if(capacity - weight[idx] >= 0)
    {
        res = max(res, knapsack(idx+1, capacity - weight[idx]) + values[idx]);
    }
    dp[idx][capacity] = res;
    return res;
}

int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n >> w;
    values.resize(n);
    weight.resize(n);

    for(int i=0; i<n; i++)
    {
        cin >> weight[i] >> values[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(0, w) << endl;



}

