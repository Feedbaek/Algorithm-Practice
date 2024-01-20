package 아날로그_시계;

public class Solution {
	public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
		int answer = 0;
		int time1 = h1 * 3600 + m1 * 60 + s1;
		int time2 = h2 * 3600 + m2 * 60 + s2;
		for (int time=time1; time<=time2; time++) {
			//int h = time / 720;
			//int m = time % 3600;
			int s = time % 60;
			int m = s * 60; // 초 단위로 분을 구함
			int h = m * 12; // 초 단위로 시를 구함
			if (time % (720 * 12) == h || time % 3600 == m) {
				++answer;
			}
			//if (h == s || m == s) {
			//	System.out.println(h + ":" + m + ":" + s);
			//	++answer;
			//}
		}

		return answer;
	}
}
