
#include <iostream>
#include <unordered_set>
#include <utility>
#include <queue>
using namespace std;

typedef pair<int, int> pos_t;

struct hasher
{
	size_t operator()(const pos_t& p) const
	{
		return p.first ^ (p.second << 12 | p.second >> 19);
	}
};

int offsets[4][2] = { {0, -1}, {1, 0}, {0, 1}, {-1, 0} };

namespace Algorithm
{
	int a;
	int width;
	int height;
	int count;
	void solve1012()
	{
		cin >> a >> width >> height >> count;

		unordered_set<pos_t, hasher> cabbages;

		int ROW, COL;
		for (int i = 0; i < count; ++i)
		{
			cin >> COL >> ROW;

			cabbages.emplace(COL, ROW);
		}


		unordered_set<pos_t, hasher> visited;
		int group = 0;

		for (auto& pos : cabbages)
		{
			if (visited.count(pos) > 0)
			{
				continue;
			}
			else
			{
				group++;
				queue<pos_t> q;

				q.push(pos);
				visited.insert(pos);

				while (!q.empty())
				{
					pos_t current = q.front();
					q.pop();

					for (int* offset : offsets)
					{
						int dcol = current.first + offset[0];
						int drow = current.second + offset[1];

						pos_t next = {dcol, drow};

						if (dcol < 0 || dcol >= width || drow < 0 || drow >= height)
						{
							continue;
						}
						if (visited.count(next) > 0 || cabbages.count(next) == 0)
						{
							continue;
						}

						visited.insert(next);
						q.push(next);
					}
				}
			}
		}

		cout << group;
	}
}