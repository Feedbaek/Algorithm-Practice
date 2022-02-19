import java.util.*;

public class Solution {
	public ArrayList<Integer> solution(int []arr) {
		ArrayList<Integer> answer = new ArrayList<Integer>();
		for (int i=0; i<arr.length; i++) {
			if (i > 0 && arr[i-1] == arr[i])
				continue;
			answer.add(arr[i]);
		}
		return answer;
	}
}

//int[] tmp = new int[arr.length];
//int cnt = 0;
//for (int i=0; i<arr.length; i++) {
//	if (i > 0 && arr[i-1] == arr[i])
//		continue;
//	tmp[cnt] = arr[i];
//	cnt++;
//}
//int[] answer = new int[cnt];
//for (int i=0; i<cnt; i++)
//	answer[i] = tmp[i];
//return answer;
