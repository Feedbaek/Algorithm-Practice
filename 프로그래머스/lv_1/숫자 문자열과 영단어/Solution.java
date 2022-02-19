class Solution {
	public int solution(String s) {
		int answer = 0;
		String tmp = "";
		for (int i=0; i<s.length(); i++) {
			if (Character.isDigit(s.charAt(i)))
				answer = answer * 10 + s.charAt(i) - '0';
			else {
				tmp += s.charAt(i);
				if (tmp.equals("zero")) {
					answer = answer * 10;
					tmp = "";
				}
				else if (tmp.equals("one")) {
					answer = answer * 10 + 1;
					tmp = "";
				}
				else if (tmp.equals("two")) {
					answer = answer * 10 + 2;
					tmp = "";
				}
				else if (tmp.equals("three")) {
					answer = answer * 10 + 3;
					tmp = "";
				}
				else if (tmp.equals("four")) {
					answer = answer * 10 + 4;
					tmp = "";
				}
				else if (tmp.equals("five")) {
					answer = answer * 10 + 5;
					tmp = "";
				}
				else if (tmp.equals("six")) {
					answer = answer * 10 + 6;
					tmp = "";
				}
				else if (tmp.equals("seven")) {
					answer = answer * 10 + 7;
					tmp = "";
				}
				else if (tmp.equals("eight")) {
					answer = answer * 10 + 8;
					tmp = "";
				}
				else if (tmp.equals("nine")) {
					answer = answer * 10 + 9;
					tmp = "";
				}
			}
		}
		return answer;
	}
}
