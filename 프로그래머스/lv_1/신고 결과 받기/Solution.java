import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {
	public int[] solution(String[] id_list, String[] report, int k) {
		int[] answer = new int[id_list.length];
		Map<String, ArrayList<String>> reportMap = new HashMap<>(); // 유저당 신고한 유저들 이름
		Map<String, Integer> mailMap = new HashMap<>();  // 유저들이 메일 받는 수
		for (int i=0; i<id_list.length; i++) {
			mailMap.put(id_list[i], 0);	// 초기화
			reportMap.put(id_list[i], new ArrayList<>());
		}
		for (int i=0; i<report.length; i++) {
			String[] tmp = report[i].split(" ");
			if (reportMap.get(tmp[1]).contains(tmp[0]))	// 중복신고 패스
				continue;
			reportMap.get(tmp[1]).add(tmp[0]);
		}
		for (int i=0; i<id_list.length; i++) {
			ArrayList<String> tmp = reportMap.get(id_list[i]);
			if (tmp.size() < k)
				continue ;
			for (int j=0; j< tmp.size(); j++)
				mailMap.put(tmp.get(j), mailMap.get(tmp.get(j)) + 1);
		}
		for (int i=0; i<id_list.length; i++)
			answer[i] = mailMap.get(id_list[i]);
		return answer;
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		String[] id_list1 = {"muzi", "frodo", "apeach", "neo"};
		String[] id_list2 = {"con", "ryan"};
		String[] report1 = {"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"};
		String[] report2 = {"muzi ryan", "ryan con", "ryan con", "ryan con", "ryan con", "con ryan", "con ryan", "con ryan", "con ryan"};
		for (int ans : s.solution(id_list1, report1, 2)) {
			System.out.print(ans);
		}
		System.out.println("");
		for (int ans : s.solution(id_list2, report2, 3)) {
			System.out.print(ans);
		}
		System.out.println("");
	}
}
