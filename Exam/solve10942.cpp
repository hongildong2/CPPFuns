#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>

namespace Algorithm
{
	using namespace std;
	int arr[2010] = { -1, };
	int dp[2010][2010] = { 0, };
	int sDP[2010][2010] = { 0, };
	

	int n, m;
	int solve10942()
	{
		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		cin >> n;

		for (int i = 1; i <= n; ++i)
		{
			cin >> arr[i];
		}


		// palindrome base case
		for (int i = 1; i <= n; ++i)
		{
			dp[i][0] = 1;
			
			if (arr[i] == arr[i - 1])
			{
				sDP[i-1][2] = 1;
			}
		}

		for (int centerIndex = 1; centerIndex <= n - 1; ++centerIndex)
		{
			for (int wingLength = 1; centerIndex + wingLength <= n && centerIndex - wingLength >= 0; ++wingLength) // j is palindrome length
			{
				// Ȧ�� �Ӹ���� 1 ~ 7 -> 1 ~ 5 �Ӹ���� �ƴ� �� 3 ~ 5 �Ӹ�����̸� 1 ~ 7 �Ӹ���� ���� => 2���� dp��[������][����]��
				// ���������� top down recursive��?
				// ���̷� ABA�� �Ǿ����.  B�� �Ӹ�����̾����
				// ���� 7 -> 313, 232, 151 ���⼭ A�� ���� �Ӹ�����̰� �߰��� B�� �Ӹ�����̸� ����
				// B�� ���� k�϶� k = 1���� Ȯ���ϱ�
				// B�� Ȯ�� ���������� (j - k) / 2.
				// ��ġ x���� ���� y�� �Ӹ���� Ȯ���ߴ��� ���ߴ��� ���� ���� �ʿ� => DP

				// ABA Ȯ�ν���
				// �߰� 3���� �Ӹ������ �ƴѵ� �߰� 5���� �Ӹ������ �����Ѱ�?? ���� => 3�� Ȯ���ϸ� ��
				
				const int left = centerIndex - wingLength;
				const int right = centerIndex + wingLength;
				if (dp[centerIndex][wingLength - 1] == 1 && arr[left] == arr[right])
				{
					dp[centerIndex][wingLength] = 1;
				}
				else
				{
					break; // no further palindrome possible
				}
			}
		}

		for (int startIndex = 1; startIndex <= n - 1; ++startIndex)
		{
			for (int sL = 4; startIndex + sL - 1 <= n; sL += 2)
			{
				if (sDP[startIndex][sL - 2] != 1)
				{
					break;
				}

				if (arr[startIndex + sL - 1] == arr[startIndex + sL - 2] && arr[startIndex] == arr[startIndex + sL - 1])
				{
					sDP[startIndex][sL] = 1;
				}
			}
		}



		// ¦���� ��� ���� �����ؾ� �Ӹ����
		// 1 ~ 1 �� �Ӹ����
		// 1 ~ 2 �� ������� ��, ������ ¦���̰� 1 ~ 1�� �Ӹ�����̾����Ƿ�, ��� ���� �������� ������ �Ӹ������ �ƴϴ�.
		// i ~ j ���� -> i ~ j - 1�� Ȧ��? ¦��?
		// Ȧ����� j-1�� i + 1, j�� i�� ������? => ������ �Ӹ����, �ƴϸ� �ƴ�
		// ¦����� i ~ j - 2�� �Ӹ�����̰� j-2, j-1, j�� ���� ���� ���ΰ�? => ������ �Ӹ����, �ƴϸ� �ƴ�



		cin >> m;
		int k, l;
		for (int i = 0; i < m; ++i)
		{
			cin >> k >> l;

			int ans = 0;
			if ((k - l) % 2 == 0)
			{
				// Ȧ�� ���� ����
				int center = (k + l) / 2;
				int wingLength = l - center;
				ans = dp[center][wingLength];
			}
			else
			{
				// ¦�� ����
				int length = l - k + 1;
				ans = sDP[k][length];
			}

			cout << ans << '\n';
		}

		return 0;
	}
}