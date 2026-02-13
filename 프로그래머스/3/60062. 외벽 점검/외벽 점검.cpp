#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = dist.size() + 1;
    
    sort(dist.begin(), dist.end());    
    int weakSize = weak.size();
    
    for(int i = 0; i < weakSize; i++)
    {
        weak.push_back(weak[i] + n);
    }
    
    for(int i = 0; i < weakSize; i++)
    {
        do{
            int cnt = 1;
            int point = weak[i] + dist[cnt-1];
            
            for(int j = i; j < i + weakSize; j++)
            {
                if(point < weak[j])
                {
                    cnt++;
                    
                    if(cnt > dist.size()) break;
                    
                    point = weak[j] + dist[cnt-1];
                }
            }
            
            answer = min(answer, cnt);
        }while(next_permutation(dist.begin(), dist.end()));
    }
   
    if(answer > dist.size()) answer = -1;
    
    return answer;
}