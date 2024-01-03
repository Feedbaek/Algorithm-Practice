package 올바른_괄호;

class Solution {
	boolean solution(String s) {
		int check = 0;
		for (int i=0; i<s.length()&&check>=0; i++) {
			if (s.charAt(i) == '(')
				check++;
			else
				check--;
		}
		if (check == 0)
			return true;
		return false;
	}
}
