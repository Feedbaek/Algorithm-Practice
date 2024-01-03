package 최댓값과_최솟값;

class Solution {
	public String solution(String s) {
		String[] input = s.split(" ");
		int min = Integer.parseInt(input[0]);
		int max = Integer.parseInt(input[1]);
		for (int i=0; i<input.length; i++) {
			if (Integer.parseInt(input[i]) > max)
				max = Integer.parseInt(input[i]);
			if (Integer.parseInt(input[i]) < min)
				min = Integer.parseInt(input[i]);
		}
		return String.valueOf(min) + " " + String.valueOf(max);
	}
}
