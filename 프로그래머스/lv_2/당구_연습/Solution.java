package 당구_연습;

public class Solution {
	int getDistance(int x1, int y1, int x2, int y2) {
		return (int) (Math.pow(x1-x2, 2) + Math.pow(y1-y2, 2));
	}

	public int[] solution(int m, int n, int startX, int startY, int[][] balls) {
		int[] answer = new int[balls.length];
		for (int i=0; i<balls.length; ++i) {
			int targetX = balls[i][0];
			int targetY = balls[i][1];
			int d1 = 1000000, d2 = 1000000, d3 = 1000000, d4 = 1000000;
			if (startY != targetY || startX < targetX) {
				d1 = getDistance(startX, startY, -targetX, targetY);
			}
			if (startY != targetY || startX > targetX) {
				d2 = getDistance(startX, startY, m + (m-targetX), targetY);
			}
			if (startX != targetX || startY < targetY) {
				d3 = getDistance(startX, startY, targetX, -targetY);
			}
			if (startX != targetX || startY > targetY) {
				d4 = getDistance(startX, startY, targetX, n + (n-targetY));
			}
			// 제일 작은 거리를 구한다.
			answer[i] = Math.min(d1, Math.min(d2, Math.min(d3, d4)));
		}
		return answer;
	}
}
