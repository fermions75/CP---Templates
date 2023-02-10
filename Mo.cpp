#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 100;
const int MOD = 1e9 + 7;
int arr[N + 5];
int n;
int blocks[800];
int blk_sz = 3;
struct node
{
    int l, r, idx;
}res[N];

bool cmp(node &a, node &b)
{
    if((a.l/blocks) != (b.l/blocks)) return (a.l/blocks) < (b.l/blocks);
    return a.r < b.r;
}

/// sqrt decomposition
void make_blocks()
{
    int blk_idx = 0;
    int mnn = INT_MAX;
    for(int i=0; i<n; i++)
    {
        if((i + 1) % blk_sz == 0)
        {
            mnn = min(mnn, arr[i]);
            blocks[blk_idx++] = mnn;
            mnn = INT_MAX;
        }
        else
        {
            mnn = min(mnn, arr[i]);
        }
    }
    int total_blocks = ceil(n / (double)blk_sz);
    if(blk_idx != total_blocks)
    {
        blocks[blk_idx++] = mnn;
    }
}
int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> n;
    for(int i=0; i<n; i++) cin >> arr[i];
    make_blocks();
    int l, r;
    cin >> l >> r;
    l--, r--;
    int LB = l / blk_sz;
    int RB = r / blk_sz;
    int mnn = INT_MAX;
    if(LB == RB)
    {
        for(int i=l; i<=r; i++) mnn = min(mnn, arr[i]);
    }
    else
    {
        for(int i=l; i<(LB*blk_sz)+blk_sz; i++)
        {
            mnn = min(mnn, arr[i]);
        }
        for(int i=LB+1; i<RB; i++)
        {
            mnn = min(mnn, blocks[i]);
        }
        for(int i=blk_sz*RB; i<=r; i++)
        {
            mnn = min(mnn, arr[i]);
        }
    }
    cout << mnn << endl;


}

