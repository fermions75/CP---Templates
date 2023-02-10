#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 100;
const int MOD = 1e9 + 7;
string s = "";
string a, b;
int dp[200][200];
int lcs_len = 0;
int solve(int i, int j)
{
    if(i == a.size()) return 0;
    if(j == b.size()) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int res = 0;
    if(a[i] == b[j])
    {
        res = max(res, 1+solve(i+1, j+1));
    }
    else
    {
        res = max(res, max(solve(i+1, j), solve(i, j+1)));
    }
    return dp[i][j] = res;
}
vector<string>v;
void set_lcs(int i, int j, int curr_lcs_len, string res)
{
    if(v.size() > 2) return;
    if(curr_lcs_len == lcs_len)
    {
        v.push_back(res);
        return;
    }
    if(i == a.size() || j == b.size()) return;
    for(char ch='a'; ch<='z'; ch++)
    {
        bool done = false;
        for(int k=i; k<a.size(); k++)
        {
            if(ch == a[k])
            {
                for(int l=j; l<b.size(); l++)
                {
                    if(ch == b[l] && dp[k][l] == (lcs_len - curr_lcs_len))
                    {
                        res += ch;
                        set_lcs(k+1, l+1, curr_lcs_len+1, res);
                        done = true;
                        break;
                    }
                }
            }
            if(done) break;
        }
    }
}


int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int t, cases = 1;
    cin >> t;
    while(t--)
    {
        cin >> a >> b;
        memset(dp, -1, sizeof(dp));
        lcs_len = solve(0, 0);
        if(lcs_len == 0) cout << "Case " << cases++ << ": "  << ":(" << endl;
        else
        {
            s.clear();
            v.clear();
            set_lcs(0, 0, 0, s);
            sort(v.begin(), v.end());
            cout << "Case " << cases++ << ": " << v[0] << endl;

        }
    }


}

