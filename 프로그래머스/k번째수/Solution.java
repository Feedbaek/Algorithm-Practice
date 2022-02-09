import java.util.Arrays;

class Solution {
	public int[] solution(int[] array, int[][] commands) {
		int[] answer = new int[commands.length];
		for (int n=0; n<commands.length; n++) {
			int[] arr = Arrays.copyOfRange(array, commands[n][0]-1, commands[n][1]);
			Arrays.sort(arr);
			answer[n] = arr[commands[n][2]-1];
		}
		return answer;
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		int[] array = {1, 5, 2, 6, 3, 7, 4};
		int[][] commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
		s.solution(array, commands);
	}
}
