package 이중우선순위큐;

import java.util.TreeMap;

public class Solution {
	public int[] solution(String[] operations) {
		TreeMap<Integer, Integer> rbTree = new TreeMap<>();
		for (String operation : operations) {
			String[] split = operation.split(" ");
			String command = split[0];
			int number = Integer.parseInt(split[1]);
			if (command.equals("I")) {  // 삽입
				if (rbTree.containsKey(number)) {
					rbTree.put(number, rbTree.get(number) + 1);
				} else {
					rbTree.put(number, 1);
				}
			} else {  // 삭제
				if (!rbTree.isEmpty()) {
					if (number == 1) {  // 최댓값 삭제
						if (rbTree.get(rbTree.lastKey()) > 1) {
							rbTree.put(rbTree.lastKey(), rbTree.get(rbTree.lastKey()) - 1);
						} else {
							rbTree.remove(rbTree.lastKey());
						}
					} else {  // 최솟값 삭제
						if (rbTree.get(rbTree.firstKey()) > 1) {
							rbTree.put(rbTree.firstKey(), rbTree.get(rbTree.firstKey()) - 1);
						} else {
							rbTree.remove(rbTree.firstKey());
						}
					}
				}
			}
		}
		if (rbTree.isEmpty()) {
			return new int[]{0, 0};
		}
		return new int[]{rbTree.lastKey(), rbTree.firstKey()};
	}
}
