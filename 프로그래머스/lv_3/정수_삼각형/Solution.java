package 정수_삼각형;

public class Solution {
	public int solution(int[][] triangle) {
		int answer = 0;
		int[][] dp = new int[triangle.length][triangle.length];
		dp[0][0] = triangle[0][0];
		for (int i=1; i<triangle.length; i++) {
			dp[i][0] = dp[i-1][0] + triangle[i][0];
			for (int j=1; j<triangle[i].length; j++) {
				dp[i][j] = Math.max(dp[i-1][j], dp[i-1][j-1]) + triangle[i][j];
				if (dp[i][j] > answer) {
					answer = dp[i][j];
				}
			}
		}
		return answer;
	}
}
