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

			if (h == s && m == s && s == 0) {
				checkH = false;
			}

			if (checkH) {
				answer++;
				//System.out.println(h + " " + m + " " + s);
				checkH = false;
			}
			if (checkM) {
				answer++;
				//System.out.println(h + " " + m + " " + s);
				checkM = false;
			}

			if (h == s) {
				checkH = true;
				//System.out.print("1: ");
				//System.out.println(h + " " + m + " " + s);
			}
			if (m == s) {
				checkM = true;
				//System.out.print("2: ");
				//System.out.println(h + " " + m + " " + s);
			}
			if (h == s && m == s && s == 0) {
				//System.out.print("3: ");
				//System.out.println(h + " " + m + " " + s);
				checkH = false;
			}

		}
		//if (checkH) {
		//	answer++;
		//}
		//if (checkM) {
		//	answer++;
		//}

		return answer;
	}

	public static void main(String[] args) {
		Solution s = new Solution();
		// 11	58	59	11	59	0	1
		System.out.println(s.solution(11, 58, 59, 11, 59, 0));
	}
}
