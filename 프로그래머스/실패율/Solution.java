class Solution {
	public int[] solution(int N, int[] stages) {
		int[] answer = new int[N];
		double[][] arr = new double[N+1][2];
		double[][] fail = new double[N+1][2];
		double[] tmp;
		for (int i=0; i<arr.length; i++)
			arr[i][0] = i+1;
			fail[i][0] = i+1;
		for (int i=0; i<stages.length; i++)
			for (int j=0; j<stages[i]; j++)
				arr[j][1] += 1;
		for (int i=0; i<fail.length-1; i++)
			fail[i][1] = (arr[i][1] - arr[i+1][1]) / arr[i][1];
		for (int i=0; i<fail.length-2; i++) {
			for (int j=0; j<fail.length-2-i; j++) {
				if (fail[j][1] < fail[j+1][1]) {
					tmp = fail[j];
					fail[j] = fail[j+1];
					fail[j+1] = tmp;
				}
			}
		}
		for (int i=0; i<answer.length; i++)
			answer[i] = (int)fail[i][0];

		return answer;
	}
}
