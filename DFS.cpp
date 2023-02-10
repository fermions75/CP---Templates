void dfs(int node) //simple dfs
{
    visited[node] = true;

    for(int i=0; i<graph[node].size(); i++)
    {
        int child = graph[node][i];

        if(visited[child] == 0)
        {
            dfs(child);
        }
    }
}
