//B 11501
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<long long> answer;

void Solve()
{
    int N;
    cin >> N;

    long long Max = 0;
    
    vector<int> price(N);
    for(int i = 0; i < N; i++)
    {
        cin >> price[i];
    }
    long long result = 0;

    for(int i = N - 1; i >= 0; i--)
    {
        if(price[i] > Max)
        {
            Max = price[i];
        }
        else
        {
            result += (Max - price[i]);
        }
    }

    answer.push_back(result);
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        Solve();
    }

    for(int i = 0; i < T; i++)
    {
        cout << answer[i] << "\n";
    }

    return 0;
}