package 유사_칸토어_비트열;

public class Solution {
	public long rec(int n, long pos, long remainder, long[] arr) {
		if (pos == 0) {
			return 0;
		}
		if (n == 0) {
			return 1;
		}
		long sum = 0;
		long r = remainder / 5;
		if (pos <= r * 1) {  // 1
			sum += rec(n-1, pos, r, arr);
		} else if (pos <= r * 2) {  // 1
			sum = arr[n-1] * 1;
			sum += rec(n-1, pos - r * 1, r, arr);
		} else if (pos <= r * 3) {  // 0
			sum = arr[n-1] * 2;
		} else if (pos <= r * 4) {  // 1
			sum = arr[n-1] * 2;
			sum += rec(n-1, pos - r * 3, r, arr);
		} else {  // 1
			sum = arr[n-1] * 3;
			sum += rec(n-1, pos - r * 4, r, arr);
		}
		return sum;
	}

	public int solution(int n, long l, long r) {
		// n번째 에서 1의 개수를 저장하는 배열
		long[] arr = new long[21];
		long s = 1;
		arr[0] = 1;
		for (int i=1; i<=n; ++i) {
			arr[i] = arr[i-1] * 4;
			s *= 5;
		}
		return (int) (rec(n, r, s, arr) - rec(n, l-1, s, arr));
	}
}
