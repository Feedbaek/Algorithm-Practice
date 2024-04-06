package 가장_먼_노드;

import java.util.*;

public class Solution {
	boolean[] visited = new boolean[20001];
	List<Integer>[] direction = new ArrayList[20001];
	int longDistance = 0;
	int answer = 0;


	void dfs(int node, int distance) {
		System.out.println("here: " + node);
		visited[node] = true;

		for (int i=0; i<direction[node].size(); ++i) {
			int nextNode = direction[node].get(i);
			if (!visited[nextNode]) {
				dfs(nextNode, distance + 1);
			}
		}

		if (distance > longDistance) {
			longDistance = distance;
			System.out.println("longD: " + longDistance);
			System.out.println("d: " + distance);
			System.out.println("node: " + node);
			answer = 1;
		} else if (distance == longDistance) {
			System.out.print("++answer");
			++answer;
		}
	}


	public int solution(int n, int[][] edge) {
		for (int i=1; i<=n; ++i) {
			direction[i] = new ArrayList();
		}

		for (int i=0; i<edge.length; ++i) {
			direction[edge[i][1]].add(edge[i][0]);
			direction[edge[i][0]].add(edge[i][1]);
		}

		// dfs가 아닌 dfs로 해결해야함
		dfs(1, 0);

		return answer;
	}
}
