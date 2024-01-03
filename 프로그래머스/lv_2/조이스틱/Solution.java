package 조이스틱;

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
		idx = i - left_move(i);		// 왼쪽으로 이동한 인덱스 계산
		if (idx < 0)
			idx += name.length();
		new_move = move + left_move(i);		// 이동 횟수 추가
		new_move += ascii_diff(name.charAt(idx));	// 문자 바꾼 수 추가
		sb.deleteCharAt(idx);		// 실제로 문자 교체
		sb.insert(idx, name.charAt(idx));
		step_back(idx, new_move);		// 왼쪽으로 이동 실행
		sb.deleteCharAt(idx);		// 되돌리기
		sb.insert(idx, 'A');
		idx = i + right_move(i);	// 오른쪾으로 이동한 인덱스 계산
		if (idx >= name.length())
			idx -= name.length();
		new_move = move + right_move(i);	// 이동 횟수 추가
		new_move += ascii_diff(name.charAt(idx));		// 문자 바꾼 수 추가
		sb.deleteCharAt(idx);		// 실제로 문자 교체
		sb.insert(idx, name.charAt(idx));
		step_back(idx, new_move);		// 오른쪽으로 이동 실행
		sb.deleteCharAt(idx);		// 되돌리기
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
