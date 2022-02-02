import java.util.Arrays;

class Solution {
	public String solution(String s) {
		StringBuilder answer = new StringBuilder();
		char[] str = s.toCharArray();
		Arrays.sort(str);
		for (int i=str.length-1; i>=0; i--)
			answer.append(str[i]);
		return answer.toString();
	}
}
