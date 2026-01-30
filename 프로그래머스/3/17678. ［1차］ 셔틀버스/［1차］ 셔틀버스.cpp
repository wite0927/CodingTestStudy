#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> tTable;
    int memberSize = (int)timetable.size();
    
    for(int i = 0; i < memberSize; i++)
    {
        int hour = stoi(timetable[i].substr(0,2));
        int minute = stoi(timetable[i].substr(3,2));
        
        tTable.push_back(hour * 60 + minute);
    }
    
    sort(tTable.begin(), tTable.end());

    vector<int> bus(n,0);
    int idx = 0;
    int lastTime = -1;
    int answerTime = 0;
    
    for(int i = 0; i < n; i++)
    {
        int busTime = 540 + i * t;
        
        while(idx < memberSize && busTime >= tTable[idx] && bus[i] < m)
        {
            lastTime = tTable[idx];
            idx++;
            bus[i]++;
        }
        
        if(i == n-1)
        {
            if(bus[i] < m)
            {
                answerTime = busTime;
            }
            else
            {
                answerTime = lastTime - 1;
            }
        }
    }
    
    int hh = answerTime / 60;
    int mm = answerTime % 60;
    if(hh < 10) answer += ("0" + to_string(hh));
    else answer += to_string(hh);
    
    answer += ":";
    
    if(mm < 10) answer += ("0" + to_string(mm));
    else answer += to_string(mm);
    
    return answer;
}