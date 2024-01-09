import java.util.ArrayList;
import java.util.List;

public class 교점에_별_만들기 {

	int[] findCrossPoint(long a, long b, long e, long c, long d, long f) {
		int[] crossPoint = new int[2];
		if (a * d - b * c == 0)
			return null;
		if((b * f - e * d) % (a * d - b * c) != 0 || (e * c - a * f) % (a * d - b * c) != 0) {
			return null;
		}
		int x = (int) (((b * f) - (e * d)) / ((a * d) - (b * c)));
		int y = (int) (((e * c) - (a * f)) / ((a * d) - (b * c)));
		crossPoint[0] = x;
		crossPoint[1] = y;
		return crossPoint;
	}

	public String[] solution(int[][] line) {
		int minX = Integer.MAX_VALUE;
		int maxX = Integer.MIN_VALUE;
		int minY = Integer.MAX_VALUE;
		int maxY = Integer.MIN_VALUE;

		List<int[]> list = new ArrayList<>();

		for (int i = 0; i < line.length; i++) {
			for (int j = i + 1; j < line.length; j++) {
				int[] crossPoint = findCrossPoint(line[i][0], line[i][1], line[i][2], line[j][0], line[j][1],
						line[j][2]);
				if (crossPoint != null) {
					if (crossPoint[0] < minX)
						minX = crossPoint[0];
					if (crossPoint[1] < minY)
						minY = crossPoint[1];
					if (crossPoint[0] > maxX)
						maxX = crossPoint[0];
					if (crossPoint[1] > maxY)
						maxY = crossPoint[1];

					list.add(crossPoint);
				}
			}
		}

		char[][] map = new char[maxY - minY + 1][maxX - minX + 1];
		for (int i=0; i<map.length; i++) {
			for (int j=0; j<map[i].length; j++) {
				map[i][j] = '.';
			}
		}
		for (int i=0; i<list.size(); i++) {
			int[] crossPoint = list.get(i);
			map[crossPoint[1] - minY][crossPoint[0] - minX] = '*';
		}
		String[] answer = new String[map.length];
		for (int i=0; i<map.length; i++) {
			answer[map.length-i-1] = String.valueOf(map[i]);
		}

		return answer;
	}
}
