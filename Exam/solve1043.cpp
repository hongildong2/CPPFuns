#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>

namespace AlgorithmDone1043
{
	using namespace std;

	typedef int Person;

	struct Node
	{
		unordered_set<Node*> peopleMet;
		unordered_set<int> attendedParty;
	};


	unordered_map<Person, Node*> arr;
	unordered_set<Person> knows;
	unordered_set<int> avoidPartyIndex;


	int n, m;
	int solve1043()
	{
		int knowCount = 0;
		cin >> n >> m >> knowCount;

		if (knowCount == 0)
		{
			cout << m;
			return 0;
		}

		for (int i = 1; i <= n; ++i)
		{
			arr[i] = new Node();
			arr[i]->peopleMet = {};
			arr[i]->attendedParty = {};
		}

		
	

		for (int i = 0; i < knowCount; ++i)
		{
			int a = -1;
			cin >> a;
			knows.insert(a);
		}

		int pCount = -1;
		int attendee = -1;
		for (int i = 1; i <= m; ++i)
		{
			cin >> pCount;
			vector<Person> at;

			for (int j = 0; j < pCount; ++j)
			{
				cin >> attendee;
				at.push_back(attendee);
				arr[attendee]->attendedParty.insert(i);
			}

			for (int ap : at)
			{
				for (int bp : at)
				{
					if (ap == bp)
					{
						continue;
					}

					arr[ap]->peopleMet.insert(arr[bp]);
				}
			}
		}


		unordered_set<Node*> visited;
		for (int p : knows)
		{
			Node* n = arr[p];
			if (visited.count(n) > 0)
			{
				continue;
			}

			visited.insert(n);

			queue<Node*> q;
			q.push(n);
			while (!q.empty())
			{
				Node* cur = q.front();
				q.pop();

				for (auto party : cur->attendedParty)
				{
					avoidPartyIndex.insert(party);
				}
				

				for (auto* next : cur->peopleMet)
				{
					if (visited.count(next) > 0)
					{
						continue;
					}
					q.push(next);
					visited.insert(next);
				}
			}

		}

		cout << m - avoidPartyIndex.size();
		return 0;
	}
}