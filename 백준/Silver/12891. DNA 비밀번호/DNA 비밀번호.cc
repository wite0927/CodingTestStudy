//B 12891
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int Check(char c)
{
    if(c == 'A') return 0;
    if(c == 'C') return 1;
    if(c == 'G') return 2;
    if(c == 'T') return 3;
}

int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int S, P;
    cin >> S >> P;

    string str;
    cin >> str;

    int a, c, g, t;
    cin >> a >> c >> g >> t;

    int start = 0; int end = P-1;
    int answer = 0;

    int cnt[4] = {0,0,0,0};

    for(int i = 0; i < P; i++)
    {
        cnt[Check(str[i])]++;
    }
    if(cnt[0] >= a && cnt[1] >= c && cnt[2] >=g && cnt[3] >= t) answer++;

    for (int start = 1; start + P <= S; start++)
    {
        cnt[Check(str[start-1])]--;
        cnt[Check(str[start+P-1])]++;

        if(cnt[0] >= a && cnt[1] >= c && cnt[2] >=g && cnt[3] >= t) answer++;
    }

    cout << answer;

    return 0;
}