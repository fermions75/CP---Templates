int dx[] = {-1,0,1,0};   //bfs on grid
int dy[] = {0,1,0,-1};

int dx[]= {+0,+0,+1,-1,-1,+1,-1,+1};
int dy[]= {-1,+1,+0,+0,+1,+1,-1,-1};

bool isValid(int x, int y)
{
    if(x<0 || x>=col || y<0 || y>=row)
    {
        return false;
    }
    if(visited[x][y] == 1) // also use dis[x][y] == -1 tferZ
    {
        return false;
    }
    return true;
}

void bfs(int source1, int source2) // bfs on grid  ----------> always use dis array to traverse
{
    queue<pair <int, int>> q;
    q.push({source1, source2});
    visited[source1][source2] = 1;
    while(!q.empty())
    {
        int cr_x = q.front().first;
        int cr_y = q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            if(isValid(cr_x + dx[i], cr_y + dy[i]))
            {
                int n_x = cr_x + dx[i];
                int n_y = cr_y + dy[i];
                dis[n_x][n_y] = dis[cr_x][cr_y] + 1;
                visited[n_x][n_y] = 1;
                q.push({n_x, n_y});
            }
        }
    }
}
