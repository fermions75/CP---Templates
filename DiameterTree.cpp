void dfs(int node, int ds) //diameter of tree using dfs ---> weighted graph
{
    visited[node] = true;
    dis[node] = ds;
    if(maxD < ds)
    {
        maxD = ds;
        maxNode = node;
    }
    for(int i=0; i<graph[node].size(); i++)
    {
        int child = graph[node][i];
        if(visited[child] == 0)
        {
            dfs(child, dis[node]+mp[ {node,child}]);  // use dis[node] + 1 for unweighted graph
        }
    }
}
