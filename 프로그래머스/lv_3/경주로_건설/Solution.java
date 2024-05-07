package 경주로_건설;

public class Solution {
	int answer = 1000000000;
	int[][] dir = {{0, -1, 0}, {0, 1, 1}, {-1, 0, 2}, {1, 0, 3}};

	void dfs(int cost, int row, int col, int direction, int [][] board, int[][] costBooks) {
		if (row == board.length - 1 && col == board.length - 1) {
			if (cost < answer) {
				answer = cost;
			}
			return;
		}
		for (int i=0; i<4; ++i) {
			int r = row + dir[i][0];
			int c = col + dir[i][1];
			if (r >= 0 && r < board.length && c >= 0 && c < board.length && board[r][c] == 0) {  // 비어 있는 길
				if (direction == dir[i][2] && (costBooks[r][c] == 0 || cost + 100 < costBooks[r][c] + 500)) {  // 같은 방향
					costBooks[r][c] = cost + 100;
					dfs(cost + 100, r, c, dir[i][2], board, costBooks);
				} else if (costBooks[r][c] == 0 || cost + 600 < costBooks[r][c] + 500) {  // 코너링
					costBooks[r][c] = cost + 600;
					dfs(cost + 600, r, c, dir[i][2], board, costBooks);
				}
			}
		}
	}

	public int solution(int[][] board) {
		for (int i=0; i<4; ++i) {
			dfs(0, 0, 0, i, board, new int[board.length][board.length]);
		}
		return answer;
	}
}
