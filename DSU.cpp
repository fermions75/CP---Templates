#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 1e5 + 5;
int parent[N+5];
int sz[N+5];

void make_node(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_root(int v)
{
    if(v == parent[v])
    {
        return v;
    }
    return parent[v] = find_root(parent[v]);
}


void Union(int a, int b)
{
    a = find_root(a);
    b = find_root(b);
    if(a!=b)
    {
        if(sz[a] < sz[b])
        {
            swap(a, b);
        }
        parent[b] = a;
        sz[a] += sz[b];
    }
}


int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

}
