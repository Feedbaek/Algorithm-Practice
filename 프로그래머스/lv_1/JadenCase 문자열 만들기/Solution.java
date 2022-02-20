class Solution {
	public String solution(String s) {
		String answer = "";
		boolean flag = true;
		s = s.toLowerCase();
		for (int i=0; i<s.length(); i++) {
			if (s.charAt(i) == ' ')
				flag = true;
			else if (flag) {
				flag = false;
				if (s.charAt(i) >= 'a' && s.charAt(i) <= 'z') {
					answer += String.valueOf(s.charAt(i)).toUpperCase();
					continue;
				}
			}
			answer += s.charAt(i);
		}
		return answer;
	}
}
