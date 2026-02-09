#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 0;

int solution(int n, vector<int> stations, int w)
{
    int station_size = stations.size();
    
    int bound = 2 * w + 1;
    int station_index = 0;
    int cur = 1;
    while(cur <= n)
    {
        if(station_index >= station_size)
        {
            int len = n - cur + 1;
            if(len % bound > 0)
            {
                answer += len / bound + 1;
            }
            else
            {
                answer += len / bound;
            }
            break;
        }
        
        int left = stations[station_index] - w;
        int right = stations[station_index] + w;
        
        if(cur < left)
        {
            int len = left - cur;
            if(len % bound > 0)
            {
                answer += len / bound + 1;
            }
            else
            {
                answer += len / bound;
            }
        }
        
        cur = max(cur, right + 1);
        station_index++;
    }

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << answer << endl;

    return answer;
}
