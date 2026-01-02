#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <queue>

using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;

    queue<int> q;
    int dis[100001];

    fill(dis, dis+ 100001, -1);
    dis[N] = 0;
    q.push(N);
    
    while(!q.empty())
    {
        int temp = q.front();
        q.pop();

        if(temp == K)
        {
            cout << dis[K];
            return 0;
        }
        
        if(temp < 0 || temp > 100000) continue;

        if(temp - 1 >= 0 && dis[temp-1] == -1)
        {
            dis[temp-1] = dis[temp] + 1;
            q.push(temp-1);
        }
        if(temp + 1 <= 100000 && dis[temp+1] == -1)
        {
            dis[temp+1] = dis[temp]+1;
            q.push(temp+1);
        }
        if(temp * 2 <= 100000 && dis[temp * 2] == -1)
        {
            dis[temp * 2] = dis[temp] + 1;
            q.push(temp * 2);
        }
    }

    return 0;
}