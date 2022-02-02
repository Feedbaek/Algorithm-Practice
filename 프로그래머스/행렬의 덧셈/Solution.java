class Solution {
	public int[][] solution(int[][] arr1, int[][] arr2) {
		int[][] answer = {};
		int height = arr1.length;
		int width = arr1[0].length;
		answer = new int[height][width];
		for (int i=0; i<height; i++) {
			for (int j=0; j<width; j++) {
				answer[i][j] = arr1[i][j] + arr2[i][j];
			}
		}
		return answer;
	}
}
