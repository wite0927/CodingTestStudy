#include <string>
#include <vector>

using namespace std;

extern int excavate(int);

int dp[201][201];
int best_pos[201][201];

int solution(vector<int> depth, int money) {
    
    int w = depth.size();
    
    for(int len = 1; len <= w; len++)
    {
        for(int left = 1; left <= w - len + 1; left++)
        {
            int right = left + len - 1;
            
            if(len == 1)
            {
                dp[left][right] = depth[left-1];
                best_pos[left][right] = left;
                continue;
            }
            
            dp[left][right] = 2e9;
            for(int i = left; i <= right; i++)
            {
                int cost = depth[i-1] + max(dp[left][i-1], dp[i+1][right]);
                
                if(cost < dp[left][right])
                {
                    dp[left][right] = cost;
                    best_pos[left][right] = i;
                }
            }
            
        }
    }
    
    int left = 1; 
    int right = w;
    while(left<=right)
    {
        int target = best_pos[left][right];
        int res = excavate(target);
        
        if(res == 0) return target;
        else if(res == -1) right = target - 1;
        else if(res == 1) left = target + 1;
    }
    
    return 0;
}