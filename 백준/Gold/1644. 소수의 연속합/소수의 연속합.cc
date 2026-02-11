// B 1644
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

bool isPrime(int x)
{
	if (x == 0 || x == 1) return false;
	if (x == 2) return true;
	if (x % 2 == 0) return false;
	for (int i = 3; i * i <= x; i += 2)
	{
		if (x % i == 0) return false;
	}
	return true;
}

int main()
{
	int N;
	cin >> N;
	vector<int> prime;

	for (int i = 2; i <= N; i++)
	{
		if (isPrime(i))
		{
			prime.push_back(i);
		}
	}

	int p_size = prime.size();
	int left = 0; int right = 0; int sum = 0;
	int answer = 0;
	while (1)
	{
		if (sum == N)
		{
			answer++;
			if (left < p_size) sum -= prime[left++];
		}
		else if (sum > N)
		{
			if (left < p_size)
			{
				sum -= prime[left++];
			}
		}
		else if (sum < N)
		{
			if (right < p_size)
			{
				sum += prime[right++];
			}
			else break;
		}
	}

	std::cout << answer;
}