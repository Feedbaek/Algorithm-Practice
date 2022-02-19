class Solution {
	public String solution(int[] numbers, String hand) {
		String answer = "";
		int[] left = {3, 0};
		int[] right = {3, 2};
		for (int i=0; i<numbers.length; i++) {
			if ((numbers[i]-1) % 3 == 0) {
				answer += "L";
				left[0] = (numbers[i]-1) / 3 ;
				left[1] = (numbers[i]-1) % 3 ;
			}
			else if ((numbers[i]-1) % 3 == 2) {
				answer += "R";
				right[0] = (numbers[i]-1) / 3 ;
				right[1] = (numbers[i]-1) % 3 ;
			}
			else {
				if (numbers[i] == 0)
					numbers[i] = 11;
				int left_diff = Math.abs((numbers[i]-1) / 3 - left[0]) + Math.abs((numbers[i]-1) % 3 - left[1]);
				int right_diff = Math.abs((numbers[i]-1) / 3 - right[0]) + Math.abs((numbers[i]-1) % 3 - right[1]);
				if (left_diff < right_diff || (left_diff == right_diff && hand.equals("left"))) {
					answer += "L";
					left[0] = (numbers[i]-1) / 3 ;
					left[1] = (numbers[i]-1) % 3 ;
				}
				else if (left_diff > right_diff || (left_diff == right_diff && hand.equals("right"))) {
					answer += "R";
					right[0] = (numbers[i]-1) / 3 ;
					right[1] = (numbers[i]-1) % 3 ;
				}
			}
		}
		return answer;
	}
}
