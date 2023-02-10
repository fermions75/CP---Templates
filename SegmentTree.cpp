#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 100005;
const int MOD = 1e9 + 7;
int arr[N];
struct ST
{
    int tree[N * 4];
    static const int inf = 1e9;
    ST()
    {
        memset(tree, 0, sizeof(tree));
    }
    void build(int node, int b, int e)
    {
        if(b == e)
        {
            tree[node] = arr[b];
            return;
        }
        int mid = (b + e) / 2;
        int l = node * 2, r = node * 2 + 1;
        build(l, b, mid);
        build(r, mid+1, e);
        tree[node] = tree[l] + tree[r]; ///change
    }
    void update(int node, int b, int e, int idx, int val)
    {
        if(idx < b or idx > e) return;
        if(b == e and idx == b)
        {
            tree[node] = val;
            return;
        }
        int mid = (b + e) / 2;
        int l = node * 2, r = node * 2 + 1;
        update(l, b, mid, idx, val);
        update(r, mid+1, e, idx, val);
        tree[node] = tree[l] + tree[r]; ///change
    }
    int query(int node, int b, int e, int i, int j)
    {
        if(b > j or e < i) return 0; /// return appropriate value
        if(b >= i and e <= j) return tree[node];
        int mid = (b + e) / 2;
        int l = node * 2, r = node * 2 + 1;
        return query(l, b, mid, i, j) + query(r, mid+1, e, i, j); /// change here
    }
}st;
int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) cin >> arr[i];
    st.build(1, 1, n);
    st.update(1, 1, n, 4, 5);
    cout << st.query(1, 1, n, 4, 5) << endl;

}
