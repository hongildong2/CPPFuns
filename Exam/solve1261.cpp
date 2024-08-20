#include <iostream>
#include <queue>
#include <functional>
#include <climits>


namespace AlgorithmDone1261
{
	using namespace std;
	typedef pair<int, int> pos_t;

	pos_t offsets[4] =
	{
		{-1, 0},
		{0, 1},
		{1, 0},
		{0, -1},
	};

	

	class Node
	{
	public:
		Node(pos_t initPos, bool wall)
			: pos(initPos)
			, accumulatedWallCount(INT_MAX)
			, bWalled(wall)
		{
		}

		pos_t pos;
 		int accumulatedWallCount;
		bool bWalled;
	};

	class WallCountComparer
	{
	public:
		bool operator()(const Node* lhs, const Node* rhs)
		{
			return lhs->accumulatedWallCount < rhs->accumulatedWallCount;
		}
	};

	Node* board[110][110] = { nullptr, };


	int ROW, COL = 0;
	int solve1261()
	{
		cin >> COL >> ROW;
		std::pair<int, int> dest = { ROW - 1, COL - 1 };

		string wallInfo;
		for (unsigned int row = 0; row < ROW; ++row)
		{
			cin >> wallInfo;
			for (unsigned int col = 0; col < COL; ++col)
			{
				bool walledad = wallInfo.at(col) == '0' ? false : true;
				board[row][col] = new Node({row, col}, walledad);
			}

			wallInfo.clear();
		}
		board[0][0]->accumulatedWallCount = 0;

		priority_queue<Node*, vector<Node*>, WallCountComparer> pq;
		pq.push(board[0][0]);

		while (!pq.empty())
		{
			Node* curNode = pq.top();
			pq.pop();

			for (auto& offset : offsets)
			{
				pos_t nextPos = {curNode->pos.first + offset.first, curNode->pos.second + offset.second};
				if (nextPos.first < 0 || nextPos.first >= ROW || nextPos.second < 0 || nextPos.second >= COL)
				{
					continue;
				}

				Node* nextNode = board[nextPos.first][nextPos.second];
				int bonus = nextNode->bWalled ? 1 : 0;
				int newWallCount = curNode->accumulatedWallCount + bonus;

				if (newWallCount < nextNode->accumulatedWallCount)
				{
					nextNode->accumulatedWallCount = newWallCount;
					pq.push(nextNode);
				}
				else
				{
					continue;
				}
			}
		}
			
		cout << board[ROW-1][COL-1]->accumulatedWallCount;

		return 0;
	}
}