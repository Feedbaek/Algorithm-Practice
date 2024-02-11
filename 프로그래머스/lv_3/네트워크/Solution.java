package 네트워크;

class Solution {
	private void dfs(int start, int[][] computers, boolean[] visited) {
		visited[start] = true;

		for (int i = 0; i < computers.length; i++) {
			if (computers[start][i] == 1 && !visited[i]) {
				dfs(i, computers, visited);
			}
		}
	}

	public int solution(int n, int[][] computers) {
		int answer = 0;
		boolean[] visited = new boolean[n];

		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				dfs(i, computers, visited);
				answer++;
			}
		}

		return answer;
	}
}
