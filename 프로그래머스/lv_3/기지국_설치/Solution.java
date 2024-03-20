package 기지국_설치;

public class Solution {
	public int solution(int n, int[] stations, int w) {
		int answer = 0;
		int scope = 2 * w + 1;
		int prev = 1;

		for (int station : stations) {
			int pos = station - prev;
			int required = pos / scope;
			if (pos - (scope * required) > w) {
				++required;
			}
			answer += required;
			prev = station + w + 1;
		}
		if (prev <= n) {
			answer += (n - prev) / scope;
			++answer;
		}
		return answer;
	}
}
