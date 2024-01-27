package 아날로그_시계;

public class Solution {
	public int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
		int answer = 0;
		int time1 = h1 * 3600 + m1 * 60 + s1;
		int time2 = h2 * 3600 + m2 * 60 + s2;
		boolean checkH = false;
		boolean checkM = false;

		for (int time=time1; time<=time2; time++) {
			int h = (time / 720) % 60;
			int m = (time % 3600) / 60;
			int s = time % 60;

			if (m == s && s == 0) {  // 정각인 경우
				++answer;
				checkH = false;
				checkM = false;
				continue;
			}
			if (checkH) {
				++answer;
				checkH = false;
			}
			if (checkM) {
				++answer;
				checkM = false;
			}
			if (h == s) {
				checkH = true;
			}
			if (m == s) {
				checkM = true;
			}
		}
		return answer;
	}

	public static void main(String[] args) {
		Solution s = new Solution();
		// 	0, 5, 30, 0, 7, 0
		System.out.println("테스트 1");
		System.out.println("2 vs " + s.solution(0, 5, 30, 0, 7, 0));
		System.out.println();
		// 12, 0, 0, 12, 0, 30
		System.out.println("테스트 2");
		System.out.println("1 vs " + s.solution(12, 0, 0, 12, 0, 30));
		System.out.println();
		// 0, 6, 1, 0, 6, 6
		System.out.println("테스트 3");
		System.out.println("0 vs " + s.solution(0, 6, 1, 0, 6, 6));
		System.out.println();
		// 11, 59, 30, 12, 0, 0
		System.out.println("테스트 4");
		System.out.println("1 vs " + s.solution(11, 59, 30, 12, 0, 0));
		System.out.println();
		// 11	58	59	11	59	0	1
		System.out.println("테스트 5");
		System.out.println("1 vs " + s.solution(11, 58, 59, 11, 59, 0));
		System.out.println();
		// 	1, 5, 5, 1, 5, 6
		System.out.println("테스트 6");
		System.out.println("2 vs " + s.solution(1, 5, 5, 1, 5, 6));
		System.out.println();
		// 	0, 0, 0, 23, 59, 59
		System.out.println("테스트 7");
		System.out.println("2852 vs " + s.solution(0, 0, 0, 23, 59, 59));
	}
}
