//B 2457
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int start = 301;
int lastday = 1201;

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    int answer = 0;
    vector<pair<int, int>> flower(N);
 
    for(int i = 0; i < N; i++)
    {
        int m, d;
        cin >> m >> d;
        flower[i].first = m * 100 + d;
        cin >> m >> d;
        flower[i].second = m * 100 + d;
    }

    sort(flower.begin(), flower.end());
    
    int idx = 0;
    int maxday = 0;
    int today = start;

    while(today < lastday)
    {
        maxday = 0;
        bool b = false;

        while(idx < N && flower[idx].first <= today)
        {
            if(maxday < flower[idx].second)
            {
                maxday = flower[idx].second;
                b = true;
            }
            idx++;
        }
        
        if(!b || maxday <= today)
        {
            cout << 0;
            return 0;
        }

        answer++;
        today = maxday;
    }

    cout << answer;
    return 0;
}