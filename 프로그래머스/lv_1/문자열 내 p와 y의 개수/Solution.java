class Solution {
	boolean solution(String s) {
		int p = 0;
		int y = 0;
		for (int i=0; i<s.length(); i++) {
			char ch = s.charAt(i);
			if (Character.isUpperCase(ch))
				ch += 32;
			if (ch == 'p')
				p++;
			if (ch == 'y')
				y++;
		}
		if (p == y)
			return true;
		return false;
	}
}
