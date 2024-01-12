import java.util.ArrayList;
import java.util.List;

public class Solution {
	int[][] dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	public int rec(int[][] land, int r, int c, int[][] oilSpot, int oilSpotNum) {
		int ret = 1;
		oilSpot[r][c] = oilSpotNum;
		for (int i=0; i<4; ++i) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (nr < 0 || nr >= land.length || nc < 0 || nc >= land[r].length) {
				continue;
			}
			if (land[nr][nc] == 1 && oilSpot[nr][nc] == 0) {
				ret += rec(land, nr, nc, oilSpot, oilSpotNum);
			}
		}
		return ret;
	}

	public int solution(int[][] land) {
		int answer = 0;
		int[][] oilSpot = new int[land.length][land[0].length];
		List<Integer> oilSpotSize = new ArrayList<>();
		oilSpotSize.add(0);
		int oilSpotNum = 1;

		for (int i=0; i<land.length; ++i) {
			for (int j=0; j<land[i].length; ++j) {
				if (land[i][j] == 1 && oilSpot[i][j] == 0) {
					int ret = rec(land, i, j, oilSpot, oilSpotNum++);
					oilSpotSize.add(ret);
				}
			}
		}

		for (int c=0; c<land[0].length; ++c) {
			int sum = 0;
			boolean[] check = new boolean[oilSpotNum];
			for (int r=0; r<land.length; ++r) {
				if (land[r][c] == 1 && !check[oilSpot[r][c]]) {
					sum += oilSpotSize.get(oilSpot[r][c]);
					check[oilSpot[r][c]] = true;
				}
			}
			answer = Math.max(answer, sum);
		}

		return answer;
	}
}
