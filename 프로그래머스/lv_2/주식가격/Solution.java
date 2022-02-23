import java.util.Stack;

class Solution {
	public int[] solution(int[] prices) {
		Stack<Integer> stack = new Stack<>();
		int[] answer = new int[prices.length];
		for (int i=0, sec=0; i<prices.length; i++) {
			if (!stack.empty() && stack.peek() > prices[i]) {
				for (; !stack.empty()&&stack.peek() > prices[i]; ) {
					stack.pop();
					System.out.println("pop");
				}
				// i = 3, size = 1, sec = 2, index = 1,
				System.out.println("sec1: "+sec);
				for (int index=i - sec; index<i; index++) {
					System.out.println("i "+i+"size: "+stack.size() +"sec: "+sec+"index: "+ index);
					answer[index] = sec;
					sec--;
				}
			}
			sec++;
			stack.push(prices[i]);
		}
		for (int i=0; i<prices.length && !stack.empty(); i++) {
			if (stack.peek() == prices[prices.length-1-i]) {
				answer[prices.length-1-i] = i;
				stack.pop();
			}
		}
		return answer;
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		// 1
		int[] prices = {1, 3, 5, 7, 9, 4, 5, 2, 1, 0};
		int[] ret = s.solution(prices);
		for (int i=0; i<ret.length; i++)
			System.out.println(ret[i]);
	}
}

//int[] answer = new int[prices.length];
//for (int i=0; i<prices.length-1; i++) {
//	int sec = 0;
//	for (int j=i+1; j<prices.length; j++) {
//		sec++;
//		if (prices[i] > prices[j])
//			break;
//	}
//	answer[i] = sec;
//}
//return answer;
