package 야근_지수;

import java.util.Arrays;
import java.util.Collections;

public class Solution {
	private boolean check(int target, int n, Integer[] works) {
		for (int i=0; i<works.length; ++i) {
			if (works[i] <= target) return true;
			if (works[i] - target > n) return false;

			n -= works[i] - target;
		}
		return true;
	}

	public long solution(int n, int[] works) {
		long answer = 0;
		Integer[] myWorks = Arrays.stream(works).boxed().toArray(Integer[]::new);

		// 내림차순 정렬
		Arrays.sort(myWorks, Collections.reverseOrder());

		// 이분탐색으로 작업량의 최대 편차를 줄일 수 있는 값을 찾음
		int st = -1;
		int en = myWorks[0];
		int target = en;
		while (st < en) {
			int mid = (st + en + 1) / 2;
			if (check(mid, n, myWorks)) {
				target = mid;
				en = mid - 1;
			} else {
				st = mid;
			}
		}

		// 야근 피로도를 최소화 하도록 일함
		for (int i=0; i<myWorks.length; ++i) {
			if (myWorks[i] > target) {
				n -= myWorks[i] - target;
				myWorks[i] = target;
			}
		}
		for (int i=0; i<myWorks.length; ++i) {
			if (n != 0 && myWorks[i] > 0) {
				myWorks[i] -= 1;
				--n;
			}
			long work = myWorks[i];
			answer += work * work;
		}

		return answer;
	}

	public static void main(String[] args) {
		// test case
		// 	4, [4, 3, 3] => 12
		// 	1, [2, 1, 2] => 6
		// 	3, [1, 1] => 0
		Solution s = new Solution();
		System.out.println(s.solution(4, new int[]{4, 3, 3}));
		System.out.println("=====================================");
		System.out.println(s.solution(1, new int[]{2, 1, 2}));
		System.out.println("=====================================");
		System.out.println(s.solution(3, new int[]{1, 1}));
		System.out.println("=====================================");
	}
}
