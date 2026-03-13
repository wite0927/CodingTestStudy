#include <string>
#include <vector>
#include <numeric>

using namespace std;

int gcd(int a, int b)
{
    while(b)
    {
        a %= b;
        swap(a,b);
    }
    return a;
}

int lcm(int a, int b)
{
    if(a==0||b==0) return 0;
    return (a*b) / gcd(a,b);
}

int solution(vector<vector<int>> signals) {
    int size = signals.size();
    
    int maxlcm = 1;
    
    vector<int> fulltime(size, 0);
    for(int i = 0; i < size; i++)
    {
        fulltime[i] = signals[i][0] + signals[i][1] + signals[i][2];
        maxlcm = lcm(maxlcm, fulltime[i]);
        
        if(maxlcm > 100000000) maxlcm = 100000000;
    }
    
    for(int time = 1; time < maxlcm; time++)
    {        
        int yelloCheck = 0;
        
        for(int i = 0; i < size; i++)
        {
            int xTime = (time-1) % fulltime[i];
            
            if(xTime >= signals[i][0] && xTime < signals[i][0] + signals[i][1])
            {
                yelloCheck++;
            }
        }
        
        if(yelloCheck == size)
        {
            return time;
        }
    }
    
    int answer = 0;
    return -1;
}