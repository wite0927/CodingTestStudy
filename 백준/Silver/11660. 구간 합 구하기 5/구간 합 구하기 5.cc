// B 11660
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = { 1,0,-1,0 };

bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M)
	{
		return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> M;

	vector<vector<int>> map(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> map[i][j];
		}
	}

	vector<vector<int>> sum(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + map[i][j];
		}
	}

	for (int i = 0; i < M; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		cout << sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1] << "\n";
	}

	return 0;
}