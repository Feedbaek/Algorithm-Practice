class Solution {
	public int solution(int[] numbers) {
		int answer = 1+2+3+4+5+6+7+8+9;
		for (int i=0; i< numbers.length; answer -= numbers[i], i++);
		return answer;
	}
}
