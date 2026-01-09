#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> Fenwick;
vector<long long> answer;

void Update_Fenwick(int idx, long long value, int M)
{
    while(idx <= M)
    {
        Fenwick[idx] = Fenwick[idx] + value;
        idx = idx + (idx & (-idx));
    }
}

long long Sum_Fenwick(int idx)
{
    long long result = 0;
    while(idx > 0)
    {
        result = result + Fenwick[idx];
        idx = idx - (idx & (-idx));
    }
    return result;
}

void Solve(int t)
{
    int N, M, K;
    cin >> N >> M >> K;
    vector<vector<int>> Road(N+1);
    Fenwick.assign(M+1, 0);

    for(int i = 0; i < K; i++)
    {
        int a, b;
        cin >> a>>b;
        Road[a].push_back(b);
    }

    long long sum = 0;
    for(int i = 1; i <= N; i++)
    {
        //서쪽 a가 b를 방문했을 때 그 전에 b이상의 동쪽을 얼마나 갔냐.
        for(int j = 0; j < (int)Road[i].size(); j++)
        {
            int b = Road[i][j];
            sum = sum + (Sum_Fenwick(M) - Sum_Fenwick(b));
        }

        for(int j = 0; j < (int)Road[i].size(); j++)
        {
            int b = Road[i][j];
            Update_Fenwick(b, 1, M);
        }
    }
    answer.push_back(sum);
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        Solve(i);
    }

    for(int i = 0; i < T; i++)
    {
        cout << "Test case " << (i+1) << ": "<< answer[i] << "\n";
    }
    return 0;
}