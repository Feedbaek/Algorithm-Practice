package 택배_배달과_수거하기;

class Solution {
	public long solution(int cap, int n, int[] deliveries, int[] pickups) {
		long answer = 0;
		int d_pos = n-1;
		int p_pos = n-1;

		while (d_pos >= 0 && deliveries[d_pos] == 0) d_pos--;
		while (p_pos >= 0 && pickups[p_pos] == 0) p_pos--;

		while (d_pos >= 0 || p_pos >= 0) {
			int box = cap;
			answer += d_pos+1;
			answer += Math.abs(p_pos - d_pos);
			answer += p_pos+1;

			while (d_pos >= 0) {
				if (deliveries[d_pos] <= box) {
					box -= deliveries[d_pos];
					deliveries[d_pos] = 0;
					d_pos--;
				} else {
					deliveries[d_pos] -= box;
					box = 0;
					break;
				}
			}
			box = 0;
			while (p_pos >= 0) {
				if (box + pickups[p_pos] <= cap) {
					box += pickups[p_pos];
					pickups[p_pos] = 0;
					p_pos--;
				} else {
					pickups[p_pos] -= cap - box;
					box = cap;
					break;
				}
			}
		}
		return answer;
	}
	public static void main(String[] args) {
		Solution sol = new Solution();
		int cap = 4;
		int n = 5;
		int[] deliveries = {1, 0, 3, 1, 2};
		int[] pickups = {0, 3, 0, 4, 0};
		System.out.println(sol.solution(cap, n, deliveries, pickups));
		cap = 2;
		n = 7;
		deliveries = new int[]{1, 0, 2, 0, 1, 0, 2};
		pickups = new int[]{0, 2, 0, 1, 0, 2, 0};
		System.out.println(sol.solution(cap, n, deliveries, pickups));
	}
}
