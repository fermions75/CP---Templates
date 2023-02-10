vector<pair<int, int>> graph[N];

int dis[N + 5];
int link[N + 5];



void dijkstra(int source, int V)   //O(Edges * log (Vertices) + Edges)
{
    for(int i=0; i<=V; i++)
    {
        dis[i] = inf;
        link[i] = -1;
    }
    dis[source] = 0;
    priority_queue<  pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;  //{cost, nodes}
    pq.push({0, source});

    while(!pq.empty())
    {
        int u = pq.top().second;
        int cost_of_par = pq.top().first;
        pq.pop();
        if(dis[u] != cost_of_par) continue;
        for(auto v: graph[u])
        {
            int cost_of_child = v.second;
            int child = v.first;
            if(cost_of_par + cost_of_child < dis[child])
            {
                dis[child] = cost_of_par + cost_of_child;  // relaxing done
                pq.push({dis[child], child});
                link[child] = u;

            }
        }
    }

    for(int i=1; i<=V; i++)
    {
        cout << "distance to " << i << " from source is ----> " << dis[i] << endl;
    }


    //path printing
    int curr = V; // v er jaygay jei node porjonto path print korte hbe sheta hbe

    vector<int> path;
    while(curr!=1)
    {
        path.push_back(curr);
        curr = link[curr];
    }
    path.push_back(1);
    reverse(path.begin(), path.end());
    for(auto it: path)
    {
        cout << it << " ";
    }


    //path printing in lexicographical order

    vector<int> path;
    path.push_back(V);
    for(int i=V; i>1; i--)
    {
        int mxx = 10000000;

        bool flag = 0;

        for(auto it: graph[i])
        {
            if(dis[i] + it.second == dis[it.first] && !visited[it.first])
            {
                mxx = min(mxx, it.first);
                cout << "taken node -----> " << mxx << endl;
                visited[it.first] = 1;
                flag = 1;
            }
        }
        if(flag)
        {
            path.push_back(mxx);
            i = mxx;
        }
    }
    reverse(path.begin(), path.end());
    for(auto it: path)
    {
        cout << it << " ";
    }
}


int graph_grid[N + 5][N + 5];

bool visited[N + 5][N + 5];

int dis[N + 5][N + 5];

int row, col;

int dx[] = {-1,0,1,0};   //bfs on grid
int dy[] = {0,1,0,-1};


//int dx[]= {+0,+0,+1,-1,-1,+1,-1,+1};
//int dy[]= {-1,+1,+0,+0,+1,+1,-1,-1};

bool isValid(int x, int y)
{
    if(x<0 || x>=row || y<0 || y>=col)
    {
        return false;
    }

    return true;
}

void dijkstra_grid(int source1, int source2)
{
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<N; j++)
        {
            dis[i][j] = inf;
        }
    }
    priority_queue<  pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> > pq;
    pq.push({graph_grid[source1][source2], {source1, source2}});  // {cost, source}
    dis[source1][source2] = graph_grid[source1][source2];

    while(!pq.empty())
    {
        pair<int, pair<int, int>> fronts = pq.top();
        pq.pop();
        int cost_of_par = fronts.first;
        int par_x = fronts.second.first;
        int par_y = fronts.second.second;
        for(int i=0; i<4; i++)
        {
            int n_x = par_x + dx[i];
            int n_y = par_y + dy[i];

            if(isValid(n_x, n_y))
            {
                int cost_of_child = graph_grid[n_x][n_y];

                if(cost_of_par + cost_of_child < dis[n_x][n_y])
                {
                    dis[n_x][n_y] = cost_of_par + cost_of_child;
                    pq.push({dis[n_x][n_y], {n_x, n_y}});
                }
            }
        }
    }

    /*for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }*/
}





