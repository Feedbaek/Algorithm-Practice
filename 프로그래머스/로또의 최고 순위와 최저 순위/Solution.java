class Solution {
	public int[] solution(int[] lottos, int[] win_nums) {
		int[] answer = new int[2];
		int zero_num = 0;
		int cnt = 0;
		for (int i=0; i<lottos.length; i++) {
			if (lottos[i] == 0) {
				zero_num++;
				continue;
			}
			for (int j=0; j<win_nums.length; j++) {
				if (lottos[i] == win_nums[j]) {
					cnt++;
					break;
				}
			}
		}
		answer[0] = (7 - cnt) - zero_num;
		answer[1] = (7 - cnt);
		if (answer[0] > 6)
			answer[0] = 6;
		if (answer[1] > 6)
			answer[1] = 6;
		return answer;
	}
}
