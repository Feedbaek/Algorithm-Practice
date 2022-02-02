import java.util.ArrayList;

class Solution {
	public ArrayList solution(long n) {
		ArrayList<Long> answer = new ArrayList<Long>();
		for (;n > 0; n /= 10)
			answer.add(n % 10);
		return answer;
	}
}

