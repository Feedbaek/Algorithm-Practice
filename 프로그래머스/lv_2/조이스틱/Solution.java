class Solution {
	public StringBuilder sb;
	public String name;
	public int answer = 0;
	public int right_move(int idx) {
		for (int i=idx, cnt=0; ; i++, cnt++) {
			if (i == name.length())
				i = 0;
			if (name.charAt(i) != sb.charAt(i))
				return cnt;
		}
	}
	public int left_move(int idx) {
		for (int i=idx, cnt=0; ; i--, cnt++) {
			if (i == -1)
				i = name.length()-1;
			if (name.charAt(i) != sb.charAt(i))
				return cnt;
		}
	}
	public int ascii_diff(char name_ch) {
		if (name_ch - 'A' < ('Z' - name_ch) + 1)
			return name_ch - 'A';
		return ('Z' - name_ch) + 1;
	}
	public void step_back(int i, int move) {
		int new_move;
		int idx;

		if (sb.toString().equals(name)) {
			if (answer == 0 || answer > move)
				answer = move;
			return ;
		}
		idx = i - left_move(i);
		if (idx < 0)
			idx += name.length();
		new_move = move + left_move(i);
		new_move += ascii_diff(name.charAt(idx));
		sb.deleteCharAt(idx);
		sb.insert(idx, name.charAt(idx));
		step_back(idx, new_move);
		sb.deleteCharAt(idx);
		sb.insert(idx, 'A');
		idx = i + right_move(i);
		if (idx >= name.length())
			idx -= name.length();
		new_move = move + right_move(i);
		new_move += ascii_diff(name.charAt(idx));
		sb.deleteCharAt(idx);
		sb.insert(idx, name.charAt(idx));
		step_back(idx, new_move);
		sb.deleteCharAt(idx);
		sb.insert(idx, 'A');
	}
	public int solution(String input) {
		name = input;
		sb = new StringBuilder();
		for (int i=0; i<name.length(); i++)
			sb.append('A');
		step_back(0, 0);
		return answer;
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.solution("JAN"));
	}
}

//name = input;
//for (int i=0; i<name.length(); i++)
//	sb.append('A');
//for (int i=0, move; !sb.toString().equals(name); ) {
//	if (left_move(name, sb, i) < right_move(name, sb, i)) {
//		move = left_move(name, sb, i);
//		i -= move;
//		if (i < 0)
//			i += name.length();
//	}
//	else {
//		move = right_move(name, sb, i);
//		i += move;
//		if (i >= name.length())
//			i -= name.length();
//	}
//	answer += move;
//	answer += ascii_diff(name.charAt(i));
//	sb.deleteCharAt(i);
//	sb.insert(i, name.charAt(i));
//}
//return answer;
