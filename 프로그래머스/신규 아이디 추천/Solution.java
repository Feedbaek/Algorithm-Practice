class Solution {
	public String solution(String new_id) {
		StringBuilder sb = new StringBuilder();
		String s = "";
		for (int i=0; i<new_id.length(); i++) {
			if (new_id.charAt(i) >= 'A' && new_id.charAt(i) <= 'Z')
				sb.append(String.valueOf(new_id.charAt(i)).toLowerCase());
			else if (new_id.charAt(i) >= 'a' && new_id.charAt(i) <= 'z')
				sb.append(new_id.charAt(i));
			else if (new_id.charAt(i) >= '0' && new_id.charAt(i) <= '9') {
				sb.append(new_id.charAt(i));
			}
			else if (new_id.charAt(i) == '-' || new_id.charAt(i) == '_' || new_id.charAt(i) == '.') {
				if ((i == 0 && new_id.charAt(i) == '.') || (i == new_id.length()-1 && new_id.charAt(i) == '.'))
					continue;
				if (sb.length()>0 && sb.charAt(sb.length()-1) == '.' && new_id.charAt(i) == '.')
					continue;
				sb.append(new_id.charAt(i));
			}
		}
		if (sb.length() == 0)
			sb.append("a");
		s = sb.toString();
		if (sb.length() >= 16)
			s = sb.substring(0, 15);
		StringBuilder answer = new StringBuilder(s);
		if (answer.charAt(0) == '.')
			answer.deleteCharAt(0);
		if (answer.length()>0 && answer.charAt(answer.length()-1) == '.')
			answer.deleteCharAt(answer.length()-1);
		if (answer.length() == 0)
			answer.append('a');
		for (int i=0; i<2; i++)
			if (answer.length() == i+1)
				answer.append(answer.charAt(i));
		return answer.toString();
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.solution("...!@BaT#*..y.abcdefghijklm"));
		System.out.println(s.solution("z-+.^."));
		System.out.println(s.solution("=.="));
		System.out.println(s.solution("/.a..n..d.da."));
	}
}
