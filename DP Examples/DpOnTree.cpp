#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5;
const int MOD = 1e9 + 7;
vector<int>graph[N + 100];
int n;
int dp[N + 100];
/// find subtree of every node
void solve(int node, int par)
{
    dp[node] = 1;
    for(int i=0; i<graph[node].size(); i++)
    {
        int child = graph[node][i];
        if(child != par)
        {
            solve(child, node);
            dp[node] += dp[child];
        }
    }
}

int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i=0; i<n-1; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    solve(1, 0);
    for(int i=1; i<=n; i++) cout << dp[i] << " ";
    cout << endl;




}

