//B 2110
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
int dis = 0;
vector<int> house;

// 1 2 4 8 9
bool isPossible(int mid)
{
    int cnt = 1;
    int last = house[0];
    for(int i = 0; i < N; i++)
    {
        if(house[i] - last >= mid)
        {
            cnt++;
            last = house[i];
        }

        if(cnt >= C)
        {
            return true;
        }
    }

    return false;
}

// right 4 mid 2 / 4-1 >2 cnt 2 / 8-4 > 2 cnt 3 / dis = 2
// left 3 , mid 3 / 4-1 = 3 cnt 2 / 8-4 > 3 cnt 3 / dis = 3
// left 4 

int main()
{
    cin >> N >> C;

    house.assign(N, 0);
    for(int i = 0; i< N; i++)
    {
        cin >> house[i];
    }
    sort(house.begin(), house.end());

    int left = 1; int right = house[N-1] - house[0];

    while(left <= right)
    {
        int mid = (left + right) / 2;

        if(isPossible(mid))
        {
            dis = max(dis, mid);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    cout << dis;
    return 0;
}