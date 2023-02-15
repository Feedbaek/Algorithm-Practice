using namespace std;

long long solution(int k, int d) {
	long long answer = 0;
	long long dp[1000001] = {};
	long long d_sq = d;
	long long cnt = 0, num = 0;
	d_sq *= d;
	for (long long b=0; b<=d; ++b) {
		if (b * k <= d) {
			++dp[0];
			++answer;
			num = b * k;
		}
	}
	long long sum = d;
	sum *= d;
	for (long long a=1; a*k<=d; ++a) {
		cnt = 0;
		while (sum + (a*k) * (a*k) > d_sq) {
			++cnt;
			num -= k;
			if (num < 0)
				break;
			sum = num * num;
		}
		if (num < 0)
			break;
		dp[a] = dp[a-1] - cnt;
		answer += dp[a];
	}
	return answer;
}

int main(int argc, char const *argv[])
{
	solution(1, 5);
	return 0;
}

