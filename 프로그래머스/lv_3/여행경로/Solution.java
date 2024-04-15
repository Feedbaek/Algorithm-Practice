package 여행경로;

import java.util.*;

public class Solution {
	boolean endFlag;
	String[] answer;
	void dfs(Map<String, Map<String, Integer>> ticket, String airPort, List<String> path, int endSize) {
		path.add(airPort);

		if (path.size() == endSize) {
			if (endFlag == false) {
				answer = path.toArray(new String[path.size()]);
				endFlag = true;
			}
			return;
		}

		Map<String, Integer> nextAirPorts = ticket.get(airPort);
		if (nextAirPorts != null) {
			for (Map.Entry<String, Integer> entry : nextAirPorts.entrySet()) {
				if (entry.getValue() > 0) {
					int tmp = entry.getValue();
					nextAirPorts.replace(entry.getKey(), tmp - 1);
					dfs(ticket, entry.getKey(), path, endSize);
					nextAirPorts.replace(entry.getKey(), tmp);
				}
			}
		}

		path.remove(path.size()-1);
	}

	public String[] solution(String[][] tickets) {
		Map<String, Map<String, Integer>> ticket = new HashMap<>();
		List<String> path = new ArrayList<>();
		endFlag = false;

		for (int i=0; i<tickets.length; ++i) {
			Integer cnt = 0;
			if (ticket.get(tickets[i][0]) == null) {
				ticket.put(tickets[i][0], new TreeMap<>());
			} else if (ticket.get(tickets[i][0]).get(tickets[i][1]) != null) {
				cnt += ticket.get(tickets[i][0]).get(tickets[i][1]);
			}
			ticket.get(tickets[i][0]).put(tickets[i][1], cnt + 1);
		}

		String startAirPort = "ICN";
		dfs(ticket, startAirPort, path, tickets.length + 1);

		return answer;
	}

	public static void printAnswer(String[] answer) {
		for (String ans : answer) {
			System.out.print(ans + ", ");
		}
		System.out.println();
	}

	public static void main(String[] args) {
		Solution s = new Solution();
		printAnswer(s.solution(new String[][] {{"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"}}));
		printAnswer(s.solution(new String[][] {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL","SFO"}}));
		printAnswer(s.solution(new String[][] {{"ICN", "D"}, {"D", "ICN"}, {"ICN", "B"}}));
	}
}
