package 빛의_경로_사이클;

import java.util.ArrayList;
import java.util.List;

// 0 아래, 1 왼쪽, 2 위, 3 오른쪽
public class Solution {
	public int loop(int step, int dir, int x, int y, boolean[][][] visited, String[] grid) {
		while (true) {
			if (visited[x][y][dir]) {
				return step;
			}
			visited[x][y][dir] = true;
			int xSize = grid.length;
			int ySize = grid[0].length();
			if (grid[x].charAt(y) == 'L') {
				if (dir == 0) { // 아래에서 옴
					dir = 3;
					y = (y-1 + ySize) % ySize;
				} else if (dir == 1) { // 왼쪽에서 옴
					dir = 0;
					x = (x-1 + xSize) % xSize;
				} else if (dir == 2) { // 위에서 옴
					dir = 1;
					y = (y+1) % ySize;
				} else { // 오른쪽에서 옴
					dir = 2;
					x = (x+1) % xSize;
				}
			} else if (grid[x].charAt(y) == 'R') {
				if (dir == 0) { // 아래에서 옴
					dir = 1;
					y = (y+1) % ySize;
				} else if (dir == 1) { // 왼쪽에서 옴
					dir = 2;
					x = (x+1) % xSize;
				} else if (dir == 2) { // 위에서 옴
					dir = 3;
					y = (y-1 + ySize) % ySize;
				} else { // 오른쪽에서 옴
					dir = 0;
					x = (x-1 + xSize) % xSize;
				}
			} else { // 직진 S
				if (dir == 0) { // 아래에서 옴
					x = (x-1 + xSize) % xSize;
				} else if (dir == 1) { // 왼쪽에서 옴
					y = (y+1) % ySize;
				} else if (dir == 2) { // 위에서 옴
					x = (x+1) % xSize;
				} else { // 오른쪽에서 옴
					y = (y-1 + ySize) % ySize;
				}
			}
			step++;
		}
	}

	public Integer[] solution(String[] grid) {
		List<Integer> answer = new ArrayList<>();
		boolean[][][] visited = new boolean[grid.length][grid[0].length()][4];
		for (int i=0; i<grid.length; i++) {
			for (int j=0; j<grid[i].length(); j++) {
				for (int k=0; k<4; k++) {
					if (!visited[i][j][k]) {
						int ret = loop(0, k, i, j, visited, grid);
						if (ret != 0) {
							answer.add(ret);
						}
					}
				}
			}
		}
		// 오름차순 정렬
		answer.sort((a, b) -> a - b);
		return answer.toArray(new Integer[0]);
	}
}
