#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> p, vector<string> m) {
    int answer = 0;
    
    int limit = min((int)m.size(), (p[0] + p[1] + p[2]) * 5);
    int x = m.size() / 5;
    if(m.size() % 5 != 0) x += 1;
    
    vector<int> dia(x, 0);
    vector<int> iron(x, 0);
    vector<int> stone(x, 0);
    
    for(int i = 0; i < x; i++)
    {
        int start = i * 5;
        for(int idx = start; idx < start+5 && idx < limit; idx++)
        {
            if(m[idx] == "diamond")
            {
                dia[i] += 1;
                iron[i] += 5;
                stone[i] += 25;
            }
            if(m[idx] == "iron")
            {
                dia[i] += 1;
                iron[i] += 1;
                stone[i] += 5;
            }
            if(m[idx] == "stone")
            {
                dia[i] += 1;
                iron[i] += 1;
                stone[i] += 1;
            }
        }
    }
    
    vector<int> order(x);
    
    for (int i = 0; i < x; i++) order[i] = i;

    sort(order.begin(), order.end(), [&](int a, int b) {
        return stone[a] > stone[b];
    });
    
    for(int i = 0; i < x; i++)
    {
        int k = order[i];
        
        if(p[0] > 0)
        {
            p[0]--;
            answer += dia[k];
        }
        else if(p[1] > 0)
        {
            p[1]--;
            answer += iron[k];
        }
        else if(p[2] > 0)
        {
            p[2]--;
            answer += stone[k];
        }
        else
            break;
    }
    
    return answer;
}