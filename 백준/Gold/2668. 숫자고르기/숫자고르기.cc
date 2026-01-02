#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>
#include <unordered_map>

using namespace std;

int N;
vector<int> v;
bool visited[101];
bool finished[101];
bool checked[101];

void dfs(int n)
{
    visited[n] = true;
    int next = v[n];

    if(!visited[next])
    {
        dfs(next);
    }
    else if(!finished[next])
    {
        int nn = next;
        while(true)
        {
            checked[nn] = true;
            if(nn == n ) break;
            nn = v[nn];
        }
    }

    finished[n] = true;
}

int main()
{
    cin >> N;
    v.assign(N+1, 0);

    for(int i = 1; i <= N; i++)
    {
        cin >> v[i];
    }

    for(int i = 1; i<=N; i++)
    {
        if(!visited[i]) 
            dfs(i);
    }

    int cnt = 0;
    vector<int> answer;
    for(int i = 1 ; i <= N; i++)
    {
        if(checked[i])
            answer.push_back(i);
    }

    sort(answer.begin(), answer.end());
    cout<<answer.size()<<"\n";
    for(auto i : answer)
    {
        cout << i << "\n";
    }

    return 0;
}