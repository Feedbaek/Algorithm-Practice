package 가장_먼_노드;

import java.util.*;

public class Solution {
	public int solution(int n, int[][] edge) {
		boolean[] visited = new boolean[20001];
		List<Integer>[] direction = new ArrayList[20001];
		Queue<Integer[]> queue = new LinkedList<>();
		int longDistance = 0;
		int answer = 0;

		for (int i=1; i<=n; ++i) {
			direction[i] = new ArrayList();
		}

		for (int i=0; i<edge.length; ++i) {
			direction[edge[i][1]].add(edge[i][0]);
			direction[edge[i][0]].add(edge[i][1]);
		}

		queue.add(new Integer[] {1, 0});

		while (!queue.isEmpty()) {
			Integer[] poll = queue.poll();
			int node = poll[0];
			int distance = poll[1];

			if (visited[node]) {
				continue;
			}
			visited[node] = true;

			for (int i=0; i<direction[node].size(); ++i) {
				int nextNode = direction[node].get(i);
				if (!visited[nextNode]) {
					queue.add(new Integer[] {nextNode, distance + 1});
				}
			}

			if (distance > longDistance) {
				longDistance = distance;
				answer = 1;
			} else if (distance == longDistance) {
				++answer;
			}
		}

		return answer;
	}
}
