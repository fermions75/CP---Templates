int dfs_subtree(int u, int p)  /// dfs for subtree
{
    visited[u] = true;
    subtree[u] = 1;
    for(auto v: graph[u])
    {
        if(!visited[v] && v!=p)
        {
            subtree[u] += dfs_subtree(v, u);
        }
    }
    return subtree[u];
}
