// B 17281
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int answer;

void Solve()
{
	int n;
	cin >> n;

	vector<int> dp(n + 1);
	dp[0] = 1;

	for (int i = 1; i <= 3; i++)
	{
		for (int j = i; j <= n; j++)
		{
			dp[j] = dp[j] + dp[j - i];
		}
	}

	cout << dp[n] << "\n";
}

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		Solve();
	}

	return 0;
}