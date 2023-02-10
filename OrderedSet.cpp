#include<bits/stdc++.h>
#define endl "\n"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5;
const int MOD = 1e9 + 7;
template<typename T>
using ordered_set = tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>;


int main()
{
    //ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    ordered_set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(4);
    st.insert(8);
    st.insert(5);

    /// returns the value of given index starting from 0
    cout << *st.find_by_order(5) << endl;

    /// It returns to the number of items that are strictly smaller than our item k in
    cout << st.order_of_key(2) << endl;

}



