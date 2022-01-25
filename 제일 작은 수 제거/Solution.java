class Solution {
	public int[] solution(int[] arr) {
		if (arr.length == 1) {
			int[] ret = {-1};
			return ret;
		}
		int[] answer = new int[arr.length - 1];
		int min = arr[0];
		for (int i=0; i<arr.length; i++) {
			if (arr[i] < min)
				min = arr[i];
		}
		for (int i=0,j=0; i<arr.length; i++) {
			if (arr[i] != min) {
				answer[j] = arr[i];
				j++;
			}
		}
		return answer;
	}
}
