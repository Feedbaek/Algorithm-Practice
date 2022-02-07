class Solution {
	public long solution(int n) {
		long answer = 0;
		long three = 0;

		while (n > 0) {
			three = (three * 10) + (n % 3);
			n /= 3;
		}
		StringBuilder sb = new StringBuilder(String.valueOf(three));
		three = Long.parseLong(sb.reverse().toString());
		while (three > 0) {
			answer = (answer * 3) + (three % 10);
			three /= 10;
		}
		return answer;
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.solution(45));
	}
}

