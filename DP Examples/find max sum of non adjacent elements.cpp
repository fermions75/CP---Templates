#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5;
const int MOD = 1000000007;
int arr[N];
int n;
int dp[N];
/// find max sum of non adjacent elements
int solve(int idx)
{
    if(idx == n-1) return arr[idx];
    if(idx >= n) return 0;
    if(dp[idx] != -1) return dp[idx];
    int take = arr[idx] + solve(idx + 2);
    int not_take = solve(idx + 1);
    return dp[idx] = max(take, not_take);
}

int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("inputs.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    /*memset(dp, -1, sizeof(dp));
    cout << solve(0) << endl;

    /// iterative dp
    dp[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        int take = arr[i];
        if(i > 1) take += dp[i-2];
        int not_take = dp[i-1];
        dp[i] = max(take, not_take);
    }*/

    /// space optimized
    int prev1 = 0;
    int prev2 = arr[0];
    int res = 0;
    for(int i=1; i<n; i++)
    {
        int take = arr[i];
        if(i > 1) take += prev1;
        int not_take = prev2;
        arr[i] = max(take, not_take);
        prev1 = prev2;
        prev2 = arr[i];
    }
    cout << prev2 << endl;

}
