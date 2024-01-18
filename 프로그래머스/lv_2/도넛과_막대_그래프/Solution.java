package 도넛과_막대_그래프;

import java.util.HashMap;
import java.util.List;
import java.util.ArrayList;
import java.util.Map;

public class Solution {
	public int[] solution(int[][] edges) {
		int[] answer = new int[4];
		int n = 0; // 노드의 개수
		Map<Integer, List<Integer>> inEdge = new HashMap<>();
		Map<Integer, List<Integer>> outEdge = new HashMap<>();

		for (int i=0; i<edges.length; ++i) {
			int from = edges[i][0];
			int to = edges[i][1];
			n = Math.max(n, from);
			n = Math.max(n, to);
			if (inEdge.containsKey(to)) {
				inEdge.get(to).add(from);
			} else {
				inEdge.put(to, new ArrayList<>());
				inEdge.get(to).add(from);
			}
			if (outEdge.containsKey(from)) {
				outEdge.get(from).add(to);
			} else {
				outEdge.put(from, new ArrayList<>());
				outEdge.get(from).add(to);
			}
		}
		for (int i=1; i<=n; ++i) {
			if (!inEdge.containsKey(i) && outEdge.get(i).size() >= 2) {
				answer[0] = i;
				break;
			}
		}
		List<Integer> nodeList = outEdge.get(answer[0]);
		while (!nodeList.isEmpty()) {
			int startNode = nodeList.get(0);
			nodeList.remove(0);
			boolean[] visited = new boolean[n+1];
			// 그래프 탐색
			while (true) {
				visited[startNode] = true;
				if (outEdge.get(startNode) == null) {
					answer[2] += 1;
					break;
				}
				if (outEdge.get(startNode).size() == 2) {
					answer[3] += 1;
					break;
				}
				if (visited[outEdge.get(startNode).get(0)]) {
					answer[1] += 1;
					break;
				}
				startNode = outEdge.get(startNode).get(0);
			}
		}

		return answer;
	}
}
