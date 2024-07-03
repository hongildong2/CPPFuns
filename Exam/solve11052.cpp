#include <cassert>
#include <iostream>


namespace Algorithm
{

	using namespace std;
	int n;
	int arr[10005];
	int dp[10005];

	void solve11052()
	{
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> arr[i];
		}

		dp[0] = 0;
		dp[1] = arr[1];
		dp[2] = max(arr[2], dp[1] + arr[1]);

		for (int i = 3; i <= n; ++i)
		{
			int optimal = arr[i];

			for (int j = i; j >= 1; --j)
			{
				optimal = max(optimal, dp[i - j] + arr[j]);
			}

			dp[i] = optimal;
		}

		// 1개살때 최대 -> 1
		// 2개 1 1, 2,
		// 3개, 2 + 1 or 1 + 2 or 3
		// 4 1+3, 2+2, 3+1, 4
		// 5 1 4 2 3 3 2 4 1
		assert (n < 10000);
		cout << dp[n];
	}
}