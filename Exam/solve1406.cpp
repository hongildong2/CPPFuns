#include <iostream>
#include <string>
using namespace std;

namespace Algorithm1406
{

	class Node
	{
	public:
		Node(const char letter) : mLetter(letter), next(nullptr), prev(nullptr)
		{
		}

		// Input will be always cursor, not head, �׻� insert �� ����� �����͸� �����ϵ���
		static Node* InsertNode(Node* cursor, const char letter)
		{
			if (cursor == nullptr)
			{
				return new Node(letter);
			}

			if (cursor->next == nullptr)
			{
				cursor->next = new Node(letter);
				cursor->next->prev = cursor;
				return cursor->next;
			}
			else
			{
				Node* inserted = new Node(letter);
				Node* currentNext = cursor->next;

				cursor->next = inserted;
				inserted->prev = cursor;

				inserted->next = currentNext;
				currentNext->prev = inserted;
				return inserted;
			}
		}

		// Ŀ���� ��ġ�� ��带 ����, Ŀ���� ���ʳ��� �̵�
		static Node* DeleteNode(Node* cursor)
		{
			if (cursor == nullptr || cursor->prev == nullptr)
			{
				return cursor;
			}

			Node* leftNode = cursor->prev;
			Node* rightNode = cursor->next;

			// nullptr ok, desired
			leftNode->next = rightNode;


			if (rightNode != nullptr)
			{
				rightNode->prev = leftNode;
			}

			delete cursor;

			return leftNode;
		}

		static Node* GoLeft(Node* cursor)
		{
			if (cursor == nullptr || cursor->prev == nullptr)
			{
				return cursor;
			}
			else
			{
				return cursor->prev;
			}

		}
		static Node* GoRight(Node* cursor)
		{
			if (cursor == nullptr || cursor->next == nullptr)
			{
				return cursor;
			}
			else
			{
				return cursor->next;
			}
		}

		static void Print(Node* cursor)
		{
			Node* head = cursor;
			while (head->prev != nullptr)
			{
				head = head->prev;
			}

			// ignore dummy node
			head = head->next;
			if (head == nullptr)
			{
				return; // empty string
			}

			while (head->next != nullptr)
			{
				cout << head->mLetter;
				head = head->next;
			}

			cout << head->mLetter;
		}

		char mLetter;
		Node* next;
		Node* prev;
	};


	int n;
	string input;
	void solve1406()
	{

		getline(cin, input);

		cin >> n;

		Node* cursor = new Node(0);
		for (unsigned int i = 0; i < input.size(); ++i)
		{
			cursor = Node::InsertNode(cursor, input.at(i));
		}

		char command;
		char letter;
		for (int i = 0; i < n; ++i)
		{
			cin >> command;
			if (command == 'P')
			{
				cin >> letter;
			}

			switch (command)
			{
			case 'P': // add letter to cursor
				cursor = Node::InsertNode(cursor, letter);
				break;
			case 'L': // left
				cursor = Node::GoLeft(cursor);
				break;
			case 'D': // right
				cursor = Node::GoRight(cursor);
				break;
			case 'B': // delete
				cursor = Node::DeleteNode(cursor);
				break;

			default:
				break;
			}
		}

		Node::Print(cursor);
	}
}