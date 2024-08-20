#include <iostream>
#include <unordered_map>

namespace AlgorithmDone2531
{
	using namespace std;

	int sushi[50000] = { -1, };
	int sushiT;
	int pCount;
	int c;

	int N;
	int solve2531()
	{
		cin >> N >> sushiT >> pCount >> c;

		// sushi 뒤에 k만큼 0 ~ k 복사
		for (int i = 0; i < N; ++i)
		{
			cin >> sushi[i];
		}
		for (int i = 0; i <= pCount + 3; ++i)
		{
			sushi[N + i] = sushi[i];
		}

		int left = 0;
		int right = left + pCount - 1;

		unordered_map<int, int> ateSushi;
		ateSushi.reserve(N + 1);

		for (int i = 0; i < pCount; ++i)
		{
			if (ateSushi.find(sushi[i]) == ateSushi.end())
			{
				ateSushi.insert({ sushi[i], 1 });
			}
			else
			{
				++ateSushi[sushi[i]];
			}
		}

		int maxSushi = ateSushi.size();
		while (left < N)
		{
		
			int sushiTCount = (int) ateSushi.size();
			if (ateSushi.find(c) == ateSushi.end())
			{
				sushiTCount++;
			}
			
			maxSushi = max(maxSushi, sushiTCount);
			if (maxSushi == pCount + 1)
			{
				cout << pCount + 1;
				return 0;
			}


			// 접시 옮기기
			left++;
			right++;

			// most left 없애고 right + 1추가
			int mostLeftFish = sushi[left - 1];
			if (ateSushi[mostLeftFish] == 1)
			{
				ateSushi.erase(mostLeftFish);
			}
			else
			{
				--ateSushi[mostLeftFish];
			}


			if (ateSushi.find(sushi[right]) == ateSushi.end())
			{
				ateSushi.insert({sushi[right], 1});
			}
			else
			{
				++ateSushi[sushi[right]];
			}
		}


		cout << maxSushi;
		return 0;
	}
}