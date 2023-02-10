bool cycle = false;
int color[ N ];

void cycle_directed(int s)
{
    color[s] = 1;
    for (auto x: graph[s])
    {
        if (color[x] == 0)
        {
            cycle_directed(x);
        }
        else
        {
            if (color[x] == 1)
            {
                // cycle detected..
                cycle = true;
            }
        }
    }
    color[s] = 2;
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == 0) cycle_directed(i);
    }
    return 0;
}
