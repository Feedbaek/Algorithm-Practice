import java.util.Arrays;

class Solution {
	public int solution(String dartResult) {
		int[] score = {0, 0, 0};
		int idx = -1;
		for (int i=0; i<dartResult.length(); i++) {
			if (Character.isDigit(dartResult.charAt(i))) {
				idx++;
				score[idx] = dartResult.charAt(i) - '0';
				if (dartResult.charAt(i+1) == '0') {
					score[idx] = 10;
					i++;
				}
			}
			else if (dartResult.charAt(i) == 'D')	// 보너스
				score[idx] *= score[idx];
			else if (dartResult.charAt(i) == 'T')
				score[idx] *= score[idx] * score[idx];
			else if (dartResult.charAt(i) == '*') {
				score[idx] *= 2;
				if (idx > 0)	// 처음 기회가 아니면 이전 기회 점수도 2배
					score[idx - 1] *= 2;
			}
			else if (dartResult.charAt(i) == '#')
				score[idx] *= -1;
		}
		return Arrays.stream(score).sum();	// 배열의 합
	}
}
// 메인문
	//public static void main(String[] args) {
	//	Solution s = new Solution();
	//	String dartResult = "1S2D*3T";
	//	System.out.println(s.solution(dartResult));
	//	dartResult = "1D2S#10S";
	//	System.out.println(s.solution(dartResult));
	//	dartResult = "1D2S0T";
	//	System.out.println(s.solution(dartResult));
	//	dartResult = "1S*2T*3S";
	//	System.out.println(s.solution(dartResult));
	//}

// 다른 방법

//for (int i=0; i<dartResult.length();) {
//	score[idx] = dartResult.charAt(i) - '0';	// 점수 넣기
//	i++;
//	if (dartResult.charAt(i) == '0') {	// 점수가 10점이면
//		score[idx] = 10;
//		i++;
//	}
//	if (dartResult.charAt(i) == 'D')	// 보너스
//		score[idx] *= score[idx];
//	else if (dartResult.charAt(i) == 'T')
//		score[idx] *= score[idx] * score[idx];
//	i++;
//	if (i == dartResult.length())	// 3번째 기회에서 옵션이 없다면 종료
//		break;
//	if (dartResult.charAt(i) == '*') {
//		score[idx] *= 2;
//		if (idx != 0)	// 처음 기회가 아니면 이전 기회 점수도 2배
//			score[idx - 1] *= 2;
//		i++;
//	}
//	else if (dartResult.charAt(i) == '#') {
//		score[idx] *= -1;
//		i++;
//	}
//	idx++;
//}
