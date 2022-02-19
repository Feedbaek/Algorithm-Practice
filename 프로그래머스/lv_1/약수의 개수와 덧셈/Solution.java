class Solution {
	public int solution(int left, int right) {
		int answer = 0;
		int cnt = 0;
		for (int i=left; i<=right; i++) {
			cnt = 0;
			for (int div=1; div<= i; div++)
				if (i % div == 0)
					cnt++;
			if (cnt % 2 == 0)
				answer += i;
			else
				answer -= i;
		}
		return answer;
	}
}
