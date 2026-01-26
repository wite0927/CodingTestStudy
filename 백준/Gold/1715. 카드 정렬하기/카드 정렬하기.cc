// B 1715
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for(int i = 0; i < N; i++)
    {
        int x;
        cin >> x; pq.push(x);
    }

    int answer = 0;
    while(!pq.empty())
    {
        int t = pq.top(); pq.pop();
        
        if(pq.empty()) break;

        t = t + pq.top(); pq.pop();
        answer += t;
        pq.push(t);
    }
    cout << answer;

    return 0;
}