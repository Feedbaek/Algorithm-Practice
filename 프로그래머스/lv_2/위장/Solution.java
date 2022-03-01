import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {
	public int solution(String[][] clothes) {
		int answer = 1;
		ArrayList<String> list = new ArrayList<>();
		Map<String, ArrayList<String>> map = new HashMap<>();
		for (int i=0; i<clothes.length; i++) {
			if (!map.containsKey(clothes[i][1])) {
				map.put(clothes[i][1], new ArrayList<>());
				list.add(clothes[i][1]);
			}
			map.get(clothes[i][1]).add(clothes[i][0]);
		}
		for (int i=0; i<list.size(); i++)
			answer *= map.get(list.get(i)).size()+1;
		return answer-1;
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		String[][] clothes = {{"yellowhat", "headgear"},{"bluesunglasses", "eyewear"}, {"green_turban", "headgear"}};
		s.solution(clothes);
	}
}
