class Solution {
	public int solution(int n) {
		int answer = 0;
		for (int i=2; i<=n; i++) {
			boolean check = true;
			for (int j=2; j*j<=i; j++) {
				if (i % j == 0) {
					check = false;
					break;
				}
			}
			if (check)
				answer += 1;
		}
		return answer;
	}
}
