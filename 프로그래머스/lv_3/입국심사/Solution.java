package 입국심사;

import java.util.*;

public class Solution {
	boolean check(long mid, int[] times, long n) {
		for (int i=0; i<times.length; ++i) {
			long div = mid / times[i];
			n -= div;
		}
		if (n > 0) {
			return false;
		}
		return true;
	}

	public long solution(int n, int[] times) {
		// 이분탐색으로 심사 시간을 정함
		// 심사 시간을 넘지 않게 앞에서 부터 모든 심사관들에게 사람들을 할당함
		// 성공한 경우 시간을 낮추고, 실패한 경우 시간을 높임
		long st = 1L;
		long en = 1000000000000000L;
		long answer = 0L;

		// 오름차순 정렬
		Arrays.sort(times);
		while (st < en) {
			long mid = (st + en) / 2;
			System.out.println(mid);
			if (check(mid, times, n)) {
				answer = mid;
				en = mid;
			} else {
				st = mid + 1;
			}
		}
		return answer;
	}
}
