// B 14889
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<vector<int>> abil(N, vector<int>(N, 0));

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cin >> abil[i][j];
        }
    }

    int answer = 1e9;
    vector<int> v(N, 1);
    for(int i = 0; i < N / 2; i++) v[i] = 0;

    do{ // v[0] ~ v[N/2] // v[N/2]~v[N]
        int f = 0;
        int s = 0;

        vector<int> v1; vector<int> v2;
        v1.reserve(N/2); v2.reserve(N/2);
        for(int i = 0; i < N; i++)
        {
            if(v[i] == 0) v1.push_back(i);
            else v2.push_back(i);
        }

        for(int i = 0; i < v1.size(); i++)
        {
            for(int j = i+1; j<v1.size(); j++)
            {
                int x = v1[i]; int y = v1[j];
                f += abil[x][y] + abil[y][x];
            }
        }

        for(int i = 0; i < v2.size(); i++)
        {
            for(int j = i+1; j<v2.size(); j++)
            {
                int x = v2[i]; int y = v2[j];
                s += abil[x][y] + abil[y][x];
            }
        }

        answer = min(answer, abs(f-s));

    }while(next_permutation(v.begin(), v.end()));

    cout << answer;
    return 0;
}