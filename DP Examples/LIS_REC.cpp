#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 100;
const int MOD = 1e9 + 7;
int n;
int arr[N];
int dp[4000][4000];
int solve(int idx, int prev)
{
    if(idx == n) return 0;
    if(dp[idx][prev+1] != -1) return dp[idx][prev];
    int res = 0;
    res = max(res, solve(idx+1, prev));
    if(prev == -1 or arr[idx] > arr[prev])
    {
        res = max(res, 1+solve(idx+1, idx));
    }
    return dp[idx][prev] = res;
}



int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);


    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    memset(dp, -1, sizeof(dp));
    cout << solve(0, -1) << endl;

}


