package N개의_최소공배수;

class Solution {
	public int gcd(int a, int b) {
		if (a < b)
			return gcd(b, a);
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
	public int lcm(int a, int b) {
		return (a * b) / gcd(a, b);
	}
	public int solution(int[] arr) {
		int answer = arr[0];
		for (int i=0; i<arr.length; i++) {
			if (i == 0)
				answer = lcm(arr[0], arr[1]);
			else if (answer < lcm(answer, arr[i]))
				answer = lcm(answer, arr[i]);
		}
		return answer;
	}
}
