package 연속_펄스_부분_수열의_합;

class Solution {
	public long solution(int[] sequence) {
		int n = sequence.length;
		// 크기 n 배열 2개를 생성한다.
		long [][] arr = new long[2][n];
		// 연속 펄스 1 -1 1 -1 ... 경우와 -1 1 -1 1 ... 경우를 나눠서 저장한다.
		for (int i=0; i<n; ++i) {
			if (i % 2 == 0) {
				arr[0][i] = sequence[i];
				arr[1][i] = -sequence[i];
			} else {
				arr[0][i] = -sequence[i];
				arr[1][i] = sequence[i];
			}
		}
		// 가장 큰 연속 부분 수열을 찾는다.
		// maxSoFar는 처음부터 i까지 가장 큰 부분 수열 합.
		// maxEnd는 i까지 연속된 부분 수열의 합이다. 합이 음수가 나오면 0으로 초기화 한다.
		long maxSoFar1 = 0, maxEnd1 = 0, maxSoFar2 = 0, maxEnd2 = 0;
		for (int i=0; i<n; ++i) {
			maxEnd1 = Math.max(maxEnd1 + arr[0][i], 0);
			maxSoFar1 = Math.max(maxSoFar1, maxEnd1);
			maxEnd2 = Math.max(maxEnd2 + arr[1][i], 0);
			maxSoFar2 = Math.max(maxSoFar2, maxEnd2);
		}

		return Math.max(maxSoFar1, maxSoFar2);
	}
}
