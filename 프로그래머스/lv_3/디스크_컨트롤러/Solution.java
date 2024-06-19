package 디스크_컨트롤러;

import java.util.*;

public class Solution {
	public int solution(int[][] jobs) {
		int answer = 0;
		// 작업 시간이 작은 것을 우선으로 우선순위큐 생성
		PriorityQueue<Integer[]> q = new PriorityQueue<>((a, b) -> {
			return a[1] - b[1];
		});
		// 시작 시간을 기준으로 정렬
		Arrays.sort(jobs, (a, b)-> {
			if (a[0] != b[0]) return a[0] - b[0];
			return a[1] - b[1];
		});
		// 작업을 탐색. 시작 시간 0ms
		int endTime = 0;
		for (int i=0; i<jobs.length; ) {
			if (endTime < jobs[i][0] && !q.isEmpty()) {  // 작업 완료 후 대기 작업이 존재하는 경우
				Integer[] job = q.poll();  // 큐에서 꺼내서 실행
				endTime = endTime > job[0] ? endTime + job[1] : job[0] + job[1];
				answer += endTime - job[0];
			} else {  // 이전 작업중 요청된 작업 또는 진행 중인 작업이 없는 경우
				q.add(new Integer[] {jobs[i][0], jobs[i][1]});  // 대기 큐에 추가
				++i;
			}
		}
		// 대기 큐에 남은 작업 모두 실행
		while (!q.isEmpty()) {
			Integer[] job = q.poll();
			endTime += job[1];
			answer += endTime - job[0];
		}
		// 평균 값 반환
		return answer / jobs.length;
	}
}
