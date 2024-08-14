#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <unordered_set>
#include <climits>

#include "AlgoHeader.h"

using namespace std;
namespace AlgorithmDone17141
{



	typedef pair<int, int> pos;

	struct posHasher
	{
		size_t operator()(const pos& in) const
		{
			return in.first ^ (in.second << 16 | in.second >> 16);
		}
	};

	pos offsets[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

	int board[50][50] = { 0, };

	vector<pos> virusables;
	vector<pos> walls;

	int n, m;

	void clearBoard()
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				board[i][j] = 0;
			}
		}

		for (auto& poss : walls)
		{
			board[poss.first][poss.second] = -1;
		}
	}

	void printBoard()
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cout << board[i][j] << " ";
			}
			cout << '\n';
		}

		cout << '\n';
	}


	int selectedViruseIndicies[10] = { 0, };
	int g_min = INT_MAX;

	void solveBoardRecursive(int prevIndex, int level)
	{
		if (level >= m)
		{
			queue<pos> plantedViruses;
			unordered_set<pos, posHasher> visited;
			// solve

			// cout << "selected viruses";
			for (int vC = 0; vC < m; vC++)
			{
				pos planting = virusables[selectedViruseIndicies[vC]];
				//  cout << "[ " << planting.first << ", " << planting.second << " ] ";
				plantedViruses.push(planting);
				visited.insert(planting);
			}
			// cout << '\n';



			for (auto& a : walls)
			{
				visited.insert(a);
			}

			int maxTick = 0;


			while (!plantedViruses.empty())
			{
				pos curPos = plantedViruses.front();
				plantedViruses.pop();

				for (pos offset : offsets)
				{
					pos next = { curPos.first + offset.first, curPos.second + offset.second };

					if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= n)
					{
						continue; // overflow
					}
					if (visited.count(next) > 0)
					{
						continue;
					}


					board[next.first][next.second] = board[curPos.first][curPos.second] + 1;
					maxTick = max(maxTick, board[next.first][next.second]);
					plantedViruses.push(next);
					visited.insert(next);
				}

				// printBoard();
			}

			// all spread
			if (visited.size() == n * n)
			{
				g_min = min(g_min, maxTick);
			}

			// clear
			clearBoard();
			return;
		}

		for (int i = prevIndex + 1; i < virusables.size(); ++i)
		{
			selectedViruseIndicies[level] = i;
			solveBoardRecursive(i, level + 1);
		}
	}

	int solve17141()
	{
		cin >> n >> m;
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> board[i][j];

				if (board[i][j] == 1)
				{
					walls.push_back({ i, j });
					board[i][j] = -1;
				}
				else if (board[i][j] == 2)
				{
					board[i][j] = 0;
					virusables.push_back({ i, j });
				}
			}
		}

		for (int s = 0; s <= virusables.size() - m; ++s)
		{
			solveBoardRecursive(-1, 0);
		}

		cout << (g_min == INT_MAX ? -1 : g_min);
		return 0;
	}
}