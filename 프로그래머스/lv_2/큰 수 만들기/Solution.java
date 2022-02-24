class Solution {
	public String solution(String number, int k) {
		StringBuilder sb = new StringBuilder();
		int start_idx=0;
		for (int i=0; i<number.length()-k && k>0; i++) {
			for (int j=0, big=-1; i+j<number.length() && k<=number.length()-i-j && j<=k; j++) {
				if (big < number.charAt(i+j)-'0') {
					big = number.charAt(i+j)-'0';
					start_idx = i+j;
				}
			}
			k -= start_idx - i;
			i = start_idx;
			sb.append(number.charAt(start_idx));
		}
		for (int i=start_idx+1; i<number.length()-k ; i++)
			sb.append(number.charAt(i));
		return sb.toString();
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.solution("654321", 1));
		System.out.println(s.solution("654321", 5));
		System.out.println(s.solution("1000100011", 5));
		System.out.println(s.solution("1924", 2));
		System.out.println(s.solution("1", 1));
	}
}
