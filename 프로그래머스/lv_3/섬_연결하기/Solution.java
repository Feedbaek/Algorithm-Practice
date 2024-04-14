package 섬_연결하기;

import java.util.*;

public class Solution {
	public int solution(int n, int[][] costs) {
		Map<Integer, Map<Integer, Integer>> direction = new HashMap<>();
		Map<Integer, Boolean> visited = new HashMap<>();
		PriorityQueue<Integer[]> heap = new PriorityQueue<>((a, b) -> {
			return a[2] - b[2];
		});
		int answer = 0;
		int edgeCount = 0;

		// 사이클을 찾아서 제거하는 문제
		for (int i=0; i<costs.length; ++i) {
			if (direction.get(costs[i][0]) == null) {
				direction.put(costs[i][0], new HashMap<>());
			}
			if (direction.get(costs[i][1]) == null) {
				direction.put(costs[i][1], new HashMap<>());
			}
			direction.get(costs[i][0]).put(costs[i][1], costs[i][2]);
			direction.get(costs[i][1]).put(costs[i][0], costs[i][2]);
		}

		visited.put(costs[0][0], true);
		for (Integer i : direction.get(costs[0][0]).keySet()) {
			heap.add(new Integer[] {costs[0][0], i, direction.get(costs[0][0]).get(i)});
		}
		// 시작 노드 추가
		while (edgeCount != n - 1) {
			Integer[] p = heap.poll();

			if (visited.get(p[1]) != null) {  // 사이클
				continue;
			}

			visited.put(p[1], true);
			answer += p[2];
			edgeCount++;

			for (Integer i : direction.get(p[1]).keySet()) {
				if (visited.get(i) == null) {
					heap.add(new Integer[] {p[1], i, direction.get(p[1]).get(i)});
				}
			}
		}

		return answer;
	}

	public static void main(String[] args) {
		Solution s = new Solution();
		//n / costs / answer
		//5 [[0, 1, 5], [1, 2, 3], [2, 3, 3], [3, 1, 2], [3, 0, 4], [2, 4, 6], [4, 0, 7]] 15
		//5 [[0, 1, 1], [3, 4, 1], [1, 2, 2], [2, 3, 4]] 8
		//4 [[0, 1, 5], [1, 2, 3], [2, 3, 3], [1, 3, 2], [0, 3, 4]] 9
		//5 [[0, 1, 1], [3, 1, 1], [0, 2, 2], [0, 3, 2], [0, 4, 100]] 104
		//6 [[0, 1, 5], [0, 3, 2], [0, 4, 3], [1, 4, 1], [3, 4, 10], [1, 2, 2], [2, 5, 3], [4, 5, 4]] 11
		//5 [[0, 1, 1], [2, 3, 1], [3, 4, 2], [1, 2, 2], [0, 4, 100]] 6
		//5 [[0, 1, 1], [0, 4, 5], [2, 4, 1], [2, 3, 1], [3, 4, 1]] 8
		//5 [[0, 1, 1], [0, 2, 2], [0, 3, 3], [0, 4, 4], [1, 3, 1]] 8
		// 4 [[0,1,1],[2,3,1],[1,2,4]] 6
		// 3 [[0,1,1],[1,2,1],[2,0,10]] 2

		System.out.println(s.solution(5, new int[][]{{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}, {2, 4, 6}, {4, 0, 7}}) + " == " + 15);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {3, 4, 1}, {1, 2, 2}, {2, 3, 4}}) + " == " + 8);
		System.out.println(s.solution(4, new int[][]{{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {1, 3, 2}, {0, 3, 4}}) + " == " + 9);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {3, 1, 1}, {0, 2, 2}, {0, 3, 2}, {0, 4, 100}}) + " == " + 104);
		System.out.println(s.solution(6, new int[][]{{0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3}, {4, 5, 4}}) + " == " + 11);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {2, 3, 1}, {3, 4, 2}, {1, 2, 2}, {0, 4, 100}}) + " == " + 6);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {0, 4, 5}, {2, 4, 1}, {2, 3, 1}, {3, 4, 1}}) + " == " + 8);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {0, 2, 2}, {0, 3, 3}, {0, 4, 4}, {1, 3, 1}}) + " == " + 8);
		System.out.println(s.solution(4, new int[][]{{0, 1, 1}, {2, 3, 1}, {1, 2, 4}}) + " == " + 6);
		System.out.println(s.solution(3, new int[][]{{0, 1, 1}, {1, 2, 1}, {2, 0, 10}}) + " == " + 2);
	}
}
