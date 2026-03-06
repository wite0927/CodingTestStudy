// B 14502
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = { 1,0,-1,0 };

void Solve()
{
}

bool check(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M)
	{
		return false;
	}
	return true;
}

void dfs(vector<vector<int>>& CopyMap, int x, int y)
{
	for (int dir = 0; dir < 4; dir++)
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (!check(nx, ny)) continue;
		if (CopyMap[nx][ny] != 0) continue;

		CopyMap[nx][ny] = 2;
		dfs(CopyMap, nx, ny);
	}
}

// 0 - 빈
// 1 - 벽
// 2 - 바이러스
int main()
{
	cin >> N >> M;

	vector<pair<int, int>> empty;
	vector<pair<int, int>> virus;
	vector<vector<int>> map(N, vector<int>(M, 0));

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];

			if (map[i][j] == 0)
			{
				empty.push_back({ i,j });
			}
			if (map[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}

	int emptySize = empty.size();
	for (int i = 0; i < emptySize - 2; i++)
	{
		for (int j = i + 1; j < emptySize - 1; j++)
		{
			for (int k = j + 1; k < emptySize; k++)
			{
				auto w1 = empty[i];
				auto w2 = empty[j];
				auto w3 = empty[k];

				vector<vector<int>> CopyMap = map;
				CopyMap[w1.first][w1.second] = 1;
				CopyMap[w2.first][w2.second] = 1;
				CopyMap[w3.first][w3.second] = 1;

				for (int x = 0; x < virus.size(); x++)
				{
					dfs(CopyMap, virus[x].first, virus[x].second);
				}

				int cnt = 0;
				for (int a = 0; a < N; a++)
				{
					for (int b = 0; b < M; b++)
					{
						if (CopyMap[a][b] == 0)
							cnt++;
					}
				}

				answer = max(answer, cnt);
			}
		}
	}

	cout << answer << "\n";
	return 0;
}