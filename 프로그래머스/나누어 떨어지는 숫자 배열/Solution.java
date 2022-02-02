import java.util.ArrayList;
import java.util.Arrays;

class Solution {
	public Integer[] solution(int[] arr, int divisor) {
		ArrayList<Integer> num = new ArrayList<Integer>();
		for (int i=0; i< arr.length; i++) {
			if (arr[i] % divisor == 0)
				num.add(arr[i]);
		}
		if (num.size() == 0) {
			Integer [] answer = {-1};
			return answer;
		}
		Integer answer[] = num.toArray(new Integer[num.size()]);
		Arrays.sort(answer);
		return answer;
	}
}
