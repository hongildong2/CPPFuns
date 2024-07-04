#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <unordered_set>
#include <queue>

using namespace std;

namespace Algorithm
{

	class Node
	{
	public:
		Node(const int num) : mNum(num) {}

	public:
		void AddChild(Node* child, const unsigned int dist)
		{
			mChildren.push_back({child, dist});
		}

		int mNum;
		vector<pair<Node*, unsigned int>> mChildren;
	};

	unordered_map<unsigned int, Node*> nodeMap17140;

	void solve17140()
	{
		int n, m;

		cin >> n >> m;

		for (unsigned int i = 1; i <= n; ++i)
		{
			nodeMap17140[i] = new Node(i);
		}


		int x, y, dist;
		for (unsigned int i = 1; i < n; ++i)
		{
			cin >> x >> y >> dist;

			Node* nodeA = nodeMap17140[x];
			Node* nodeB = nodeMap17140[y];

			nodeA->AddChild(nodeB, dist);
			nodeB->AddChild(nodeA, dist);
		}


		for (unsigned int i = 0; i < m; ++i)
		{
			cin >> x >> y;

			Node* root = nodeMap17140[x];
			Node* dest = nodeMap17140[y];
			unordered_set<unsigned int> visited;
			queue<Node*> q;

			q.push(root);
			visited.insert(root->mNum);

			unordered_map<Node*, unsigned int> distMap;
			distMap[root] = 0;

			while (!q.empty())
			{
				Node* curNode = q.front();
				q.pop();

				if (curNode == dest)
				{
					cout << distMap[curNode] << '\n';
					break;
				}

				for (pair<Node*, unsigned int>& nextNode : curNode->mChildren)
				{
					if (visited.count(nextNode.first->mNum) > 0)
					{
						continue;
					}

					distMap[nextNode.first] = distMap[curNode] + nextNode.second;
					visited.insert(nextNode.first->mNum);
					q.push(nextNode.first);
				}
			}
			

		}

	}
}