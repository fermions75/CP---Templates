stack<int>order;
void top_sort(int s)
{
    vis[s] = true;
    for (auto x: graph[s])
    {
        if (!vis[x]) top_sort(x);
    }
    order.push(s);
}

int main()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i]) top_sort(i);
    }
    while (!order.empty())
    {
        cout << order.top() << endl;
        order.pop();
    }
    return 0;
}
