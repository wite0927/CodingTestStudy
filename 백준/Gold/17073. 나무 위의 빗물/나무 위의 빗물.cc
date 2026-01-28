// B 17073
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int N;
    double w;
    cin >> N >> w;

    vector<vector<int>> tree(N+1);

    for(int i = 0; i < N-1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    double leafCount = 0;
    for(int i = 2; i < N+1; i++)
    {
        if(tree[i].size() == 1)
        {
            leafCount++;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(10);
    cout << (w / leafCount);
    return 0;
}