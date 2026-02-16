#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    int N = land.size();
    int dp[N][4];
    
    for(int j = 0; j < 4; j++)
    {
        dp[0][j] = land[0][j];
    }
    
    for(int i = 1; i < N; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int xxx = 0;
            for(int k = 0; k < 4; k++)
            {
                if(k != j)
                {
                    xxx = max(xxx, land[i][j] + dp[i-1][k]);
                }
            }
            dp[i][j] = xxx;
        }
    }

    for(int i = 0; i < 4; i++)
    {
        answer = max(answer, dp[N-1][i]);
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}