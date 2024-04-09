package 섬_연결하기;

import java.util.*;

public class Solution {
	LinkedList<Integer> path = new LinkedList<>();  // 지나온 경로를 저장하는 리스트
	int[][] direction = new int[101][101];
	int[] visited = new int[101];
	int answer = 0;

	void dfs(int prev, int island) {
		visited[island] = 1;
		path.addFirst(island);
		System.out.println("방문 " + prev + " >> " + island);
		System.out.println("answer = " + answer);

		for (int target=0; target<101; ++target) {
			if (direction[island][target] == -1 || target == prev || visited[target] == 2) {
				continue;
			}

			answer += direction[island][target];
			if (visited[target] == 1) {  // 사이클 발견
				System.out.println("중복발견: " + island + "-" + target);
				Iterator<Integer> iter = path.iterator();
				int before = target;
				int maxCost = 0;
				while (iter.hasNext()) {
					Integer next = iter.next();
					System.out.println("next: " + next);
					if (direction[before][next] > maxCost) {
						maxCost = direction[before][next];
					}
					if (next == target) {  // 사이클의 시작지점
						answer -= maxCost;
						System.out.println("제거: " + target + "=>" + maxCost + " answer: " + answer);
						break;
					}
					before = next;
				}
			} else if (visited[target] == 0) {  // 처음 방문
				dfs(island, target);
			}
		}
		visited[island] = 2;  // 탐색 끝
		path.removeFirst();
	}

	public int solution(int n, int[][] costs) {
		// 사이클을 찾아서 제거하는 문제
		for (int i=0; i<101; ++i) {
			for (int j=0; j<101; ++j) {
				direction[i][j] = -1;
			}
		}

		for (int i=0; i<costs.length; ++i) {
			direction[costs[i][0]][costs[i][1]] = costs[i][2];
			direction[costs[i][1]][costs[i][0]] = costs[i][2];
		}

		dfs(-1, costs[0][0]);
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

		System.out.println(s.solution(5, new int[][]{{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {3, 1, 2}, {3, 0, 4}, {2, 4, 6}, {4, 0, 7}}) + " == " + 15);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {3, 4, 1}, {1, 2, 2}, {2, 3, 4}}) + " == " + 8);
		System.out.println(s.solution(4, new int[][]{{0, 1, 5}, {1, 2, 3}, {2, 3, 3}, {1, 3, 2}, {0, 3, 4}}) + " == " + 9);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {3, 1, 1}, {0, 2, 2}, {0, 3, 2}, {0, 4, 100}}) + " == " + 104);
		System.out.println(s.solution(6, new int[][]{{0, 1, 5}, {0, 3, 2}, {0, 4, 3}, {1, 4, 1}, {3, 4, 10}, {1, 2, 2}, {2, 5, 3}, {4, 5, 4}}) + " == " + 11);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {2, 3, 1}, {3, 4, 2}, {1, 2, 2}, {0, 4, 100}}) + " == " + 6);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {0, 4, 5}, {2, 4, 1}, {2, 3, 1}, {3, 4, 1}}) + " == " + 8);
		System.out.println(s.solution(5, new int[][]{{0, 1, 1}, {0, 2, 2}, {0, 3, 3}, {0, 4, 4}, {1, 3, 1}}) + " == " + 8);
	}
}
