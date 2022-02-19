class Solution {
	public int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}

	public int[] solution(int n, int m) {
		int[] answer = new int[2];
		answer[0] = gcd(n, m);
		answer[1] = n * m / gcd(n, m);
		return answer;
	}
}
