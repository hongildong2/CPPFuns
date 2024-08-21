#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <queue>
#include <climits>
#include <cassert>
#include <algorithm>

namespace Algorithm
{
	using namespace std;


	class Node
	{
	public:
		Node(int val) : mWeight(val), mLeft(nullptr), mRight(nullptr) {}

		static Node* InsertNodeRecursive(Node* node, int weight, int value)
		{
			if (node == nullptr)
			{
				auto* n = new Node(weight);
				n->mValues.push(value);
				return n;
			}

			if (node->mWeight == weight)
			{
				node->mValues.push(value);
				return node;
			}

			if (weight > node->mWeight)
			{
				node->mRight = InsertNodeRecursive(node->mRight, weight, value);
			}
			else
			{
				node->mLeft = InsertNodeRecursive(node->mLeft, weight, value);
			}

			return node;
		}


		// traverse Tree to the leaf, return best matching node's pointer
		// cannot traverse to right subtree

		static Node* TraverseBestJewel(Node* root, int bagWeight)
		{
			Node* bestNode = root;
			traverseBestJewelRecursive(root, bagWeight, &bestNode);

			if (bestNode->mWeight > bagWeight)
			{
				return nullptr;
			}

			return bestNode;
		}

		static void traverseBestJewelRecursive(Node* node, int bagWeight, Node** ppOutBestNode)
		{
			if (node == nullptr)
			{
				return;
			}

			if (node->mWeight > bagWeight)
			{
				// discard this subtree
				return;
			}

			traverseBestJewelRecursive(node->mLeft, bagWeight, ppOutBestNode);


			if ((*ppOutBestNode)->mValues.empty())
			{
				*ppOutBestNode = node;
			}
			else
			{
				int currentScore = node->mValues.top();
				int bestScore = (*ppOutBestNode)->mValues.top();

				if (currentScore >= bestScore)
				{
					*ppOutBestNode = node;
				}
			}

			traverseBestJewelRecursive(node->mRight, bagWeight, ppOutBestNode);
		}
	public:
		int mWeight;
		priority_queue<int> mValues;
		Node* mLeft;
		Node* mRight;

	};

	// 작은 가방부터 시작해서, 본인이 감당할 수 있는 보석 중 가장 비싼보석을 가져가면 됨
	// 공간 분할 및 정렬?
	// map<weight, pq<val>>

	int N, K;

	int solve1202()
	{
		cin >> N >> K;
		// binary search tree of jewel weights

		vector<int> bags;
		bags.reserve(K + 10);
		Node* root = nullptr;

		int m, v;
		for (int i = 0; i < N; ++i)
		{
			cin >> m >> v;	
			root = Node::InsertNodeRecursive(root, m, v);
		}

		int bag;
		for (int i = 0; i < K; ++i)
		{
			cin >> bag;
			bags.push_back(bag);
		}

		sort(bags.begin(), bags.end());

		int totalScore = 0;

		for (auto& b : bags)
		{
			Node* bestNode = Node::TraverseBestJewel(root, b);
			if (bestNode == nullptr || bestNode->mValues.empty())
			{
				continue;
			}

			totalScore += bestNode->mValues.top();
			bestNode->mValues.pop();
		}

		cout << totalScore;

		return 0;
	}
}