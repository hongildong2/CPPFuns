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
				// 홀수 팰린드롬 1 ~ 7 -> 1 ~ 5 팰린드롬 아닐 때 3 ~ 5 팰린드롬이면 1 ~ 7 팰린드롬 가능 => 2차원 dp를[시작점][길이]로
				// 꼬라지보니 top down recursive로?
				// 덩이로 ABA가 되어야함.  B도 팰린드롬이어야함
				// 길이 7 -> 313, 232, 151 여기서 A가 서로 팰린드롬이고 중간의 B가 팰린드롬이면 ㄱㄴ
				// B의 길이 k일때 k = 1부터 확인하기
				// B의 확인 시작지점은 (j - k) / 2.
				// 위치 x부터 길이 y인 팰린드롬 확인했는지 안했는지 정보 유지 필요 => DP

				// ABA 확인시작
				// 중간 3에서 팰린드롬이 아닌데 중간 5에서 팰린드롬이 가능한가?? ㄴㄴ => 3만 확인하면 됨
				
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



		// 짝수면 모든 수가 동일해야 팰린드롬
		// 1 ~ 1 은 팰린드롬
		// 1 ~ 2 를 물어봤을 때, 개수는 짝수이고 1 ~ 1이 팰린드롬이었으므로, 모든 수가 동일하지 않으면 팰린드롬이 아니다.
		// i ~ j 질문 -> i ~ j - 1이 홀수? 짝수?
		// 홀수라면 j-1가 i + 1, j가 i과 같은가? => 같으면 팰린드롬, 아니면 아님
		// 짝수라면 i ~ j - 2가 팰린드롬이고 j-2, j-1, j가 전부 같은 수인가? => 같으면 팰린드롬, 아니면 아님



		cin >> m;
		int k, l;
		for (int i = 0; i < m; ++i)
		{
			cin >> k >> l;

			int ans = 0;
			if ((k - l) % 2 == 0)
			{
				// 홀수 길이 질문
				int center = (k + l) / 2;
				int wingLength = l - center;
				ans = dp[center][wingLength];
			}
			else
			{
				// 짝수 질문
				int length = l - k + 1;
				ans = sDP[k][length];
			}

			cout << ans << '\n';
		}

		return 0;
	}
}