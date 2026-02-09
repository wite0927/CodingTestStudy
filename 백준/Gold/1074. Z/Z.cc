#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <stack>
#include <deque>
#include <math.h>
#include <cstring>
#include <cmath>
using namespace std;

int N, r, c;
int x = 0, y = 0, cnt = 0;


void Z(int x, int y, int size)
{
	if (x == c && y == r)
	{
		cout << cnt;
		return;
	}
	else if (r < y + size && c < x + size && r >= y && c >= x)
	{
		Z(x, y, size / 2);
		Z(x + size / 2, y, size / 2);
		Z(x, y + size / 2, size / 2);
		Z(x + size / 2, y + size / 2, size / 2);
	}
	else
	{
		cnt += size * size;
	}

}

int main(void)
{
	std::cin >> N >> r >> c;

	if (r == 0 && c == 0) { cout << "0"; return 0; }
	Z(0, 0, pow(2, N));
}