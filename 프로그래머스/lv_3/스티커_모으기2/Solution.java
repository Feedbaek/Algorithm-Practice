package 스티커_모으기2;

public class Solution {
	public int solution(int sticker[]) {
		int answer = sticker[0];
		int n = sticker.length;

		int[] dp = new int[n];
		dp[0] = sticker[0];
		// 첫번째 원소를 처음 선택한 경우
		for (int i=2; i<n-1; ++i) {
			dp[i] = sticker[i];
			if (i < 3 || dp[i-2] > dp[i-3]) {
				dp[i] += dp[i-2];
			} else {
				dp[i] += dp[i-3];
			}
			if (answer < dp[i]) {
				answer = dp[i];
			}
		}

		dp = new int[n];
		// n의 길이가 1또는 2인 경우를 대비
		if (n > 2) {
			dp[1] = sticker[1];
			if (dp[1] > answer) {
				answer = dp[1];
			}
		}
		// 첫번째 원소를 선택 안한 경우
		for (int i=2; i<n; ++i) {
			dp[i] = sticker[i];
			if (i < 3 || dp[i-2] > dp[i-3]) {
				dp[i] += dp[i-2];
			} else {
				dp[i] += dp[i-3];
			}
			if (answer < dp[i]) {
				answer = dp[i];
			}
		}

		return answer;
	}
}
