import java.util.ArrayList;
import java.util.Collections;

class Solution {
	public ArrayList<Integer> solution(int[] numbers) {
		ArrayList<Integer> answer = new ArrayList<Integer>();
		for (int i=0; i<numbers.length-1; i++) {
			for (int j=i+1; j<numbers.length; j++) {
				if (!answer.contains(numbers[i] + numbers[j]))
					answer.add(numbers[i] + numbers[j]);
			}
		}
		Collections.sort(answer);
		return answer;
	}
}
