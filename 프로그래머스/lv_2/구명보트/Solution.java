import java.util.Arrays;

class Solution {
	public int solution(int[] people, int limit) {
		int answer = 0;
		Arrays.sort(people);
		for (int i=people.length-1, j=0; i>=j; i--) {
			answer++;
			int sum = people[i];
			if (sum+people[j] <= limit)
				sum+=people[j++];
		}
		return answer;
	}
}
