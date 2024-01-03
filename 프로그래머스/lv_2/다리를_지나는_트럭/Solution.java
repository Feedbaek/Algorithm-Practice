package 다리를_지나는_트럭;

import java.util.LinkedList;
import java.util.Queue;

class Solution {
	public int solution(int bridge_length, int weight, int[] truck_weights) {
		int answer = 0;
		int sum = 0;
		Queue<Integer> queue = new LinkedList<>();
		for (int pass_cnt=0, index=0, tmp; pass_cnt<truck_weights.length;) {
			answer++; // 시간 카운트
			if (queue.size() == bridge_length) { // 다리를 지난 트럭 검사
				tmp = queue.poll(); // 다리를 통과한 것 뽑기
				sum -= tmp; // 다리를 통과한 것의 무게를 합에서 빼기
				if (tmp > 0) // 공기가 아닌 트럭이 통과 해야 인정하고
					pass_cnt++; // 통과 트럭 카운트
			}
			if (index < truck_weights.length && sum + truck_weights[index] <= weight) { // 트럭이 올라가도 괜찮으면
				queue.offer(truck_weights[index]); // 트럭 추가요
				sum += truck_weights[index]; // 무게 추가요
				index++; // 트럭 인덱스번호 증가
			}
			else
				queue.offer(0); // 트럭이 못올라가면 공기 추가
		}
		return answer;
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		int[] truck_weights = {7,4,5,6};
		System.out.println(s.solution(2, 10, truck_weights));
	}
}
