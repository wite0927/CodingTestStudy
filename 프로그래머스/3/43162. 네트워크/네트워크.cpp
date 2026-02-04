#include <string>
#include <vector>

using namespace std;

vector<vector<int>> com;
vector<bool> vis;
int N;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

void dfs(int x)
{
    vis[x] = true;
    
    for(int i = 0; i < N; i++)
    {
        if(vis[i]) continue;
        if(com[i][x] == 0) continue;
        dfs(i);
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    N = n;
    com = computers;
    vis.assign(n, false);
    
    for(int i = 0; i< N; i++)
    {
        if(!vis[i])
        {
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}