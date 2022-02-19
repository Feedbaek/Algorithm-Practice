class Solution {
	public String[] solution(int n, int[] arr1, int[] arr2) {
		String[] answer = new String[n];
		int[] map = new int[n];
		for (int i=0; i<n; i++) {
			map[i] = arr1[i] | arr2[i];
			answer[i] = "";
			for (int j=0; j<n; j++) {
				if ((map[i] & (int)Math.pow(2, n-1-j)) > 0)
					answer[i] += "#";
				else
					answer[i] += " ";
			}
		}
		return answer;
	}
}
