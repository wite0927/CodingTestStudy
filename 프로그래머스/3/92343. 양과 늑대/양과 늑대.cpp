#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> edge;
vector<int> info;
vector<vector<int>> g;
vector<bool> vis;
int answer = 0;

void dfs(vector<int> cur)
{
    int wolf = 0;
    int sheep = 0;
    
    for(auto a : cur)
    {
        if(info[a] == 0) sheep++;
        else wolf++;
    }
    
    if(wolf >= sheep) return;
    
    answer = max(answer, sheep);
    
    for(int i = 0; i < cur.size(); i++)
    {
        int node = cur[i];
        for(auto c : g[node])
        {
            if(vis[c]) continue;
            vis[c] = true;
            cur.push_back(c);
            dfs(cur);
            cur.pop_back();
            vis[c] = false;
        }
    }
}

int solution(vector<int> infos, vector<vector<int>> edges) {
    edge = edges; info = infos;
    int n = infos.size();
    g.resize(n);
    vis.resize(n, false);
    
    for(auto edge : edges)
    {
        g[edge[0]].push_back(edge[1]);
    }
    
    vis[0] = true;
    dfs({0});
    
    return answer;
}