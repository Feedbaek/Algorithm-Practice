package 가장_먼_노드;

import java.util.*;

public class Solution {
	List<Integer>[] dir = new ArrayList[20001];
	public int solution(int n, int[][] edge) {
		int answer = 0;

		for (int i=0; i<edge.length; ++i) {
			List<Integer> arr1 = new ArrayList();
			List<Integer> arr2 = new ArrayList();
			arr1.add(edge[i][0]);
			arr2.add(edge[i][1]);

			dir[edge[i][1]] = arr1;
			dir[edge[i][0]] = arr2;
		}
		return answer;
	}
}
