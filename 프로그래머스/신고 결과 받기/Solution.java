import java.util.HashMap;
import java.util.Map;

class Solution {
	public int[] solution(String[] id_list, String[] report, int k) {
		int[] answer = new int[id_list.length];
		Map<String, String> reportMap = new HashMap<>(); // 유저당 신고한 유저들 이름
		Map<String, Integer> mailMap = new HashMap<>();  // 유저들이 메일 받는 수
		for (int i=0; i<id_list.length; i++)
			mailMap.put(id_list[i], 0);	// 초기화
		for (int i=0; i<report.length; i++) {
			String[] tmp = report[i].split(" ");
			if (reportMap.containsKey(tmp[1])) {
				if (reportMap.get(tmp[1]).contains(tmp[0]))	// 중복신고 패스
					continue;
				String str = reportMap.get(tmp[1]);
				reportMap.put(tmp[1], str + " " + tmp[0]);
			}
			else
				reportMap.put(tmp[1], tmp[0]);
		}
		for (int i=0; i<id_list.length; i++) {
			if (!reportMap.containsKey(id_list[i]))
				continue;
			String[] tmp = reportMap.get(id_list[i]).split(" ");
			if (tmp.length < k)
				continue ;
			for (int j=0; j< tmp.length; j++) {
				int value = mailMap.get(tmp[j]);
				mailMap.put(tmp[j], value + 1);
			}
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
		String[] report2 = {"ryan con", "ryan con", "ryan con", "ryan con"};
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
