#include <iostream>
#include <vector>
#include <algorithm>

namespace AlgorithmDone2217
{
	using namespace std;

	int n;
	vector<int> v;

	int solve2217()
	{
		cin >> n;
		v.reserve(n + 1);
		int a;
		for (int i = 0; i < n; ++i)
		{
			cin >> a;
			v.push_back(a);
		}

		sort(v.rbegin(), v.rend());

		int score = -1;

		for (int i = 0; i < n; ++i)
		{
			v[i] = (i + 1) * v[i];
			score = max(score, v[i]);
		}

		cout << score;


		return 0;
	}
}