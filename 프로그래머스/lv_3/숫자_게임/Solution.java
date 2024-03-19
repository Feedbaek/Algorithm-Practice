package 숫자_게임;

import java.util.Arrays;

public class Solution {
	public int solution(int[] A, int[] B) {
		int answer = 0;
		// 일단 정렬
		Arrays.sort(A);
		Arrays.sort(B);

		// 절대 못이기는 수는 내어준다.
		int aMaxIdx = A.length - 1;
		int bMaxIdx = B.length - 1;
		for (int i=0; i<A.length; ++i) {
			if (A[aMaxIdx] < B[bMaxIdx]) {
				++answer;
				--bMaxIdx;
			}
			--aMaxIdx;
		}
		return answer;
	}
}
