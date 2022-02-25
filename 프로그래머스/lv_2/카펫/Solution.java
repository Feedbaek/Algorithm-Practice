class Solution {
	public int[] solution(int brown, int yellow) {
		int[] answer = new int[2];
		int area = brown+yellow;
		for (int height=1; height*height<=area; height++)
			if (area % height == 0)
				if (brown == ((area / height) * 2) + (2*(height-2))) {
					answer[0] = area / height;
					answer[1] = height;
					break;
				}
		return answer;
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		s.solution(10, 2);
	}
}
