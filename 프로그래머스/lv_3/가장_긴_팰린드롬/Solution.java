package 가장_긴_팰린드롬;

public class Solution {
	public int solution(String s) {
		int answer = 0;

		for (int i=0; i<s.length(); ++i) {
			for (int j=1; j<=i; ++j) {
				if (i + j >= s.length()) break;

				char l = s.charAt(i - j);
				char r = s.charAt(i + j);
			}
		}
		return answer;
	}
}
