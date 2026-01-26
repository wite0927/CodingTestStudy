// B 13975
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> pq;
int T;
vector<long long> answer;

//1 3 3 4 4 5 5 5 14 17 21 21 32 35 98
void solve()
{
    int N;
    cin >> N;

    pq = priority_queue<long long, vector<long long>, greater<long long>>();
    for(int i = 0; i < N; i++)
    {
        long long x;
        cin >> x; pq.push(x);
    }

    long long result = 0;
    while(!pq.empty())
    {
        long long t = pq.top(); pq.pop();
        
        if(pq.empty()) break;

        t = t + pq.top(); pq.pop();
        result += t;
        pq.push(t);
    }

    answer.push_back(result);
}

int main()
{
    cin >> T;

    while(T--)
    {
        solve();
    }

    for(auto& i : answer)
    {
        cout << i << "\n";
    }

    return 0;
}