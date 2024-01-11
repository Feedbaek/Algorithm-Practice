package _3_x_n_타일링;

class Solution {
	public int solution(int n) {
		int mod = 1000000007;
		long[] dp = new long[n+1];
		long[] sum = new long[n+1];

		dp[0] = 1; sum[0] = 1;
		dp[1] = 0; sum[1] = 0;
		dp[2] = 3; sum[2] = 4;
		dp[3] = 0; sum[3] = 0;

		for (int i=4; i<=n; ++i) {
			dp[i] = (dp[i-2] * 3) % mod;
			dp[i] = (dp[i] + sum[i-4] * 2) % mod;
			sum[i] = sum[i-2] + dp[i];
		}
		return (int) dp[n];
	}
}
