package 숫자의_표현;

class Solution {
	public int solution(int n) {
		int answer = 0;
		for (int i=1; i<=n; i++) {
			int sum = 0;
			for (int num=i; sum<n; num++)
				sum += num;
			if (sum == n)
				answer++;
		}
		return answer;
	}
}
