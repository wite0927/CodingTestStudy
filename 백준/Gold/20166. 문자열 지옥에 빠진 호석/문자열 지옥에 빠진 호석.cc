//B.20166
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int N, M, K;
vector<vector<char>> v;
unordered_map<string, int> m;
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[8] = {-1, 0, 1, 0, 1, -1, 1, -1}; // 상, 우, 하, 좌

void dfs(int x, int y, int depth, string str)
{
    str += v[x][y];
    m[str]++;

    if(depth == 5) return;

    for(int dir = 0; dir < 8; dir++)
    {
        int nx = (x + dx[dir] + N) % N;
        int ny = (y + dy[dir] + M) % M;
        dfs(nx, ny, depth + 1, str);
    }
}

int main()
{
    cin >> N >> M >> K;

    v.assign(N, vector<char>(M, 0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            cin >> v[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            dfs(i,j,1,"");
        }
    }

    vector<int> ans;
    for(int i = 0; i < K; i++)
    {
        string s;
        cin >> s;
        ans.push_back(m[s]);
    }

    for(auto& i : ans)
    {
        cout<<i<<"\n";
    }

    return 0;
}