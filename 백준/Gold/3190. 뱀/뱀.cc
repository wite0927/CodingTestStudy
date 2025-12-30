#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int N, K, L;

bool Check(int nowX, int nowY, const deque<pair<int, int>>& snake)
{
    if(nowX < 0 || nowY < 0 || nowX >= N || nowY >= N)
    {
        return false;
    }

    for(const auto& p : snake)
    {
        if(p.first == nowX && p.second == nowY)
        {
            return false;
        }
    }

    return true;
}

bool GetApple(int x, int y, vector<pair<int,int>>& apple)
{
   for(int i = 0; i < (int)apple.size(); i++)
   {
        if(x == apple[i].first && y == apple[i].second)
        {
            apple[i] = {-1, -1};
            return true;
        }
   }

   return false;
}

//17:05 ~ 18:30
int main()
{   
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int dr[4] = {-1, 0, 1, 0};
    int dc[4] = {0, 1, 0, -1};

    cin >> N;
    deque<pair<int, int>> snake;
    snake.push_back({0,0});

    cin >> K;
    vector<pair<int,int>> apple(K);
    for(int i = 0; i < K; i++)
    {
        int apple_x, apple_y;
        cin >> apple_x >> apple_y;
        apple[i].first = apple_x -1;
        apple[i].second = apple_y -1;
    }

    cin >> L;
    vector<pair<int,char>> dir(L);
    for(int i = 0; i < L; i++)
    { 
        cin >> dir[i].first >> dir[i].second;
    }

    int time = 0;
    int turnTime = 0;
    int direction = 1; // 첫 시작 오른쪽
    while(1)
    {
        int nr = snake.front().first + dr[direction];
        int nc = snake.front().second + dc[direction];

        if(!Check(nr, nc, snake))
        {
            cout << time + 1;
            return 0;
        }

        bool eat = GetApple(nr, nc, apple);

        snake.push_front({nr, nc});
        if(!eat)
        {
            snake.pop_back();                    
        }

        time++;

        if(turnTime < L && time == dir[turnTime].first)
        {
            if(dir[turnTime].second == 'D')
            {
                direction++;
                if(direction > 3) direction = 0;
            }
            else if(dir[turnTime].second == 'L')
            {
                direction--;
                if(direction < 0) direction = 3;
            }
            else
            {
                return 0;
            }

            turnTime++;
        }
    }

    cout << time;
    return 0;
}