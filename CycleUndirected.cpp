bool cycle = false;

void cycle_undirected(int s, int parent)
{
    vis[s] = true;
    for (auto x: graph[s])
    {
        if (!vis[x])
        {
            cycle_undirected(x, s);
        }
        else
        {
            if (x != parent) cycle = true;
            // cycle detected...
        }
    }
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) cycle_undirected(i, -1);
    }
    return 0;
}
