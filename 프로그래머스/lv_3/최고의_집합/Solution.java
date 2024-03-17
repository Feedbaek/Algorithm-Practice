package 최고의_집합;

public class Solution {
	public int[] solution(int n, int s) {
		int avg = s / n;
		int[] answer = new int[n];
		for (int i=0; i<n; ++i) {
			if (avg == 0) {
				return new int[]{-1};
			} else {
				s -= avg;
				answer[i] = avg;
			}
		}
		for (int j=n-1; j>=0; --j) {
			if (s == 0) break;
			answer[j] += 1;
			--s;
		}

		return answer;
	}
}
