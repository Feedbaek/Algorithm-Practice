class Solution {
	public String solution(int a, int b) {
		int cnt = 0;
		String[] day = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
		for (int i=1; i<a; i++) {
			cnt += 30;
			if (i < 8) {
				if (i%2 == 1)
					cnt++;
				if (i == 2)
					cnt--;
			}
			else {
				if (i%2 == 0)
					cnt++;
			}
		}
		return day[(cnt + b) % 7];
	}
}
