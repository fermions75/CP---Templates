#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 100;
const int MOD = 1e9 + 7;
int n;



int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    int arr[n+5];
    for(int i=1; i<=n; i++) cin >> arr[i];
    int dp[n+5]{};
    int trace[n+5]{};
    int mxx_len = 0;
    int last_idx = 0;
    int cnt_lis[n+5]{};
    for(int i=1; i<=n; i++)
    {
        dp[i] = 1;
        for(int j=1; j<i; j++)
        {
            if(arr[j] < arr[i] and dp[j]+1 > dp[i])
            {
                dp[i] = dp[j] + 1;
                trace[i] = j;
                cnt_lis[i] = cnt_lis[j];
            }
            else if(arr[j] < arr[i] and dp[j]+1 == dp[i])
            {
                cnt_lis[i] += cnt_lis[j];
            }
        }
        if(dp[i] > mxx_len)
        {
            mxx_len = dp[i];
            last_idx = i;
        }
    }
    cout << mxx_len << endl;
    /*while(last_idx != trace[last_idx])
    {
        cout << arr[last_idx] << " ";
        last_idx = trace[last_idx];
    }*/

}

