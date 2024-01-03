package 큰_수_만들기;

class Solution {
	public String solution(String number, int k) {
		StringBuilder sb = new StringBuilder();
		int start_idx=0;
		for (int i=0; i<number.length()-k && k>0; i++) { // 길이 length -k 보장하면서 k가 0이상이면 동작
			for (int j=0, big=-1; j<=k; j++) { // k+1길이만큼 검사
				if (big < number.charAt(i+j)-'0') { // 최대값 찾으면 위치 저장
					big = number.charAt(i+j)-'0';
					start_idx = i+j;
				}
			}
			k -= start_idx - i; // 이동한 위치만큼 숫자 뺀거 체크
			i = start_idx; // 이동한 인덱스 반영
			sb.append(number.charAt(start_idx)); // 숫자 추가
		}
		for (int i=start_idx+1; i<number.length()-k ; i++) // 나머지 숫자 추가
			sb.append(number.charAt(i));
		return sb.toString();
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.solution("654321", 1));
		System.out.println(s.solution("654321", 5));
		System.out.println(s.solution("1000100011", 5));
		System.out.println(s.solution("5555623416", 5));
		System.out.println(s.solution("1924", 2));
	}
}
