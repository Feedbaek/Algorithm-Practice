package 가장_긴_팰린드롬;

public class Solution {
	public int solution(String s) {
		int answer = 1;
		int len = s.length();
		int[][] dp = new int[len][len];

		// 크기 2인 서브 문자열까지 회문이 가능한 경우 1로 표현
		for (int i=0; i<len; ++i) {
			dp[i][i] = 1;
			if (i + 1 < len && s.charAt(i) == s.charAt(i + 1)) {
				answer = 2;
				dp[i][i+1] = 1;
			}
		}
		// 크기 3인 서브 문자열부터 회문이 가능한지 검사
		for (int size=3; size<=len; ++size) {
			for (int st=0, en=st+size-1; en<len; ++st, ++en) {
				if (dp[st+1][en-1] == 1 && s.charAt(st) == s.charAt(en)) { // [st+1,en-1] 범위가 회문이고 s[st] == s[en]이면
					answer = en - st + 1;
					dp[st][en] = 1;
				}
			}
		}
		return answer;
	}
}
