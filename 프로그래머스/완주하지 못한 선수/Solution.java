import java.util.HashMap;
import java.util.Iterator;

class Solution {
	public String solution(String[] participant, String[] completion) {
		String answer = "";
		HashMap<String, Integer> map = new HashMap<String, Integer>();
		for (int i=0; i<participant.length; i++) {
			if (map.containsKey(participant[i])) {
				map.replace(participant[i], 2);
			}
			map.put(participant[i], 1);
		}
		Iterator<String> iter1 = map.keySet().iterator();
		while(iter1.hasNext()) {
			System.out.println(map.get(iter1.next()));
		}
		for (int i=0; i<completion.length; i++) {
			if (map.get(completion[i]) == 1)
				map.remove(completion[i]);
			else {
				System.out.println("B");
				map.replace(completion[i], 1);
			}
		}
		Iterator<String> iter = map.keySet().iterator();
		while(iter.hasNext()) {
			System.out.println(iter.next());
		}
		//for (String k : map)
		return answer;
	}
	public static void main(String[] args) {

	}
}
