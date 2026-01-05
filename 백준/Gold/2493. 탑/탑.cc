// B.2493
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;
    stack<pair<int, int>> tower; // H, Index
    vector<int> ans(N, 0);

    for(int i =0; i< N; i++)
    {
        int x;
        cin >> x;

        while(!tower.empty() && (tower.top().first < x))
        {
            tower.pop();
        }
        if(!tower.empty() && (tower.top().first >= x))
        {
            ans[i] = tower.top().second + 1;
        }
        tower.push({x, i});
    }

    for(auto& i : ans)
    {
        cout << i << " ";
    }

    return 0;
}

/*
4
7
5
9
6
*/