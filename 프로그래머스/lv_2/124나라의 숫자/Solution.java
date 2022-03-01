class Solution {
	public char[] _124 = {'4', '1', '2'};
	public StringBuilder sb = new StringBuilder();
	public void rec(int n) {
		int x = n / 3; // 자릿 수 확인
		if (n % 3 == 0) // 3의 배수인 경우
			x--; // 앞에 자릿 수를 하나 감소
		if (x > 0) // 다음 자릿 수가 있으면
			rec(x); // 재귀 호출
		sb.append(_124[n % 3]); // 문자를 추가
	}
	public String solution(int n) {
		rec(n);
		return sb.toString();
	}
}
/*
class Solution {
	public char rec_3(int n, char[] s, StringBuilder sum) {		// 재귀함수
		int x = n / 3;		// 몫을 구한다
		if (n % 3 == 0)		// 자릿수가 처음 바뀔 때는
			x--;		// 자릿수를 바꾸지 않는다
		if (x > 0)
			sum.append(rec_3(x, s, sum));		// 반환되는 문자를 추가
		return (s[n % 3]);
	}
	public String solution(int n) {
		char s[] = {'4','1','2'};
		StringBuilder sb = new StringBuilder();		// 스트링빌더 선언
		sb.append(rec_3(n, s, sb));
		return (sb.toString());
	}
}
*/
