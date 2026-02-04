#include<vector>
#include <queue>
using namespace std;

vector<vector<int> > map;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int N, M;

bool Check(int xx, int yy)
{
    if(xx < 0 || yy < 0 || xx >= N || yy >= M)
    {
        return false;
    }
    return true;
}

int bfs()
{
    queue<pair<int, int>> q;
    vector<vector<bool>> vis(N, vector<bool>(M, false));
    vector<vector<int>> dis(N, vector<int>(M, 0));
    
    q.push({0,0});
    vis[0][0] = true;
    dis[0][0] = 1;
    
    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        if((x == N-1) && (y == M-1))
        {
            return dis[x][y];
        }
        
        for(int dir = 0; dir <4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(!Check(nx,ny)) continue;
            if(vis[nx][ny] || map[nx][ny] == 0) continue;
            
            vis[nx][ny] = true;
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx,ny});
        }
    }
    
    return -1;
}

int solution(vector<vector<int> > maps)
{
    map = maps;
    N = maps.size();
    M = maps[0].size();
    
    int answer = bfs();
    
    return answer;
}