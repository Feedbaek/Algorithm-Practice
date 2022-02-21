import java.util.Arrays;

class Solution {
		int solution(int[][] land) {
		int[][] map = land.clone();
		for (int n=1; n<map.length; n++) {
			for (int column=0; column<4; column++) {
				int high = 0;
				for (int prev=0; prev<4; prev++)
					if (prev != column)
						if (map[n-1][prev] + map[n][column] > high)
							high = map[n-1][prev] + map[n][column];
				map[n][column] = high;
			}
		}
		Arrays.sort(map[land.length-1]);
		return map[land.length-1][3];
	}
}
