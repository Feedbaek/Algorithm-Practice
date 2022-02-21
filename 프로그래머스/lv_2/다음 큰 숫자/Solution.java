class Solution {
	public int one_num(int n) {
		String bi = Integer.toBinaryString(n);
		int cnt = 0;
		for (int i=0; i<bi.length(); i++)
			if (bi.charAt(i) == '1')
				cnt++;
		return cnt;
	}
	public int solution(int n) {
		int orgin = one_num(n);
		int answer = 0;
		for (int i=n+1; ;i++)
			if (one_num(i) == orgin) {
				answer = i;
				break;
			}
		return answer;
	}
}
