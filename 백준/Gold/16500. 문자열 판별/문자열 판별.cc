// B 16500
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

int main()
{
    string s; int n;
    vector<string> a;
    cin >> s >> n;

    for(int i =0;i<n;i++)
    {
        string as;
        cin >> as;
        a.push_back(as);
    }

    int cnt = s.length();
    vector<bool> dp(cnt + 1, false);
    dp[0] = true;

    for(int i = 0; i < cnt; i++)
    {
        if(dp[i])
        {
            for(auto& aa : a)
            {
                if(s.substr(i, aa.length()) == aa)
                {
                    dp[i+aa.length()] = true;
                }
            }
        }
    }

    if(dp[cnt])
    {
        cout << "1";
    }
    else
    {
        cout << "0";
    }
}