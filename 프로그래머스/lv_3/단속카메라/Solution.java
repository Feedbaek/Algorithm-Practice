package 단속카메라;

import java.util.Arrays;

class Solution {
	public int solution(int[][] routes) {
		int answer = 1;

		Arrays.sort(routes, (a, b) -> {
			return Integer.compare(a[1], b[1]);
		});

		int prev = routes[0][1];
		for (int i=1; i<routes.length; ++i) {
			if (routes[i][0] > prev) {
				++answer;
				prev = routes[i][1];
			}
		}
		return answer;
	}
}
