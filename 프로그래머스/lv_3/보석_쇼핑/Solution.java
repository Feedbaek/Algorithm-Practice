package 보석_쇼핑;

import java.util.HashMap;
import java.util.HashSet;

public class Solution {
	public int[] solution(String[] gems) {
		int[] answer = {1, gems.length};
		HashMap<String, Integer> map = new HashMap<>();
		HashSet<String> set = new HashSet<>();

		for (String g : gems) {
			set.add(g);
		}

		int n = set.size();
		int len = gems.length;
		System.out.println("n: " + n);
		for (int p1=0, p2=0; p1<gems.length; ) {
			if (map.size() < n) {
				if (p2 >= gems.length) {
					break;
				}
				Integer v = map.get(gems[p2]);
				if (v == null) {
					v = 0;
				}
				map.put(gems[p2], v + 1);
				++p2;
			} else {
				if (p2 - p1 < len) {
					answer[0] = p1 + 1;
					answer[1] = p2;
					len = p2 - p1;
				}
				Integer v = map.get(gems[p1]);
				if (v == 1) {
					map.remove(gems[p1]);
				} else {
					map.put(gems[p1], v - 1);
				}
				++p1;
			}
		}

		return answer;
	}
}
