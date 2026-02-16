#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int N = sticker.size();
    int dp1[N];
    
    if(N == 1)
    {
        return sticker[0];
    }
    if(N == 2)
    {
        return max(sticker[0], sticker[1]);
    }
    
    dp1[0] = sticker[0];
    dp1[1] = max(sticker[1],dp1[0]);
    for(int i = 2; i < N-1; i++)
    {
        dp1[i] = max(sticker[i] + dp1[i-2], dp1[i-1]);
    }

    int dp2[N];
    dp2[1]= sticker[1];
    dp2[2] = max(sticker[2],dp2[1]);
    for(int i = 3; i < N; i++)
    {
        dp2[i] = max(sticker[i] + dp2[i-2], dp2[i-1]);
    }
    
    answer = max(dp1[N-2], dp2[N-1]);
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}