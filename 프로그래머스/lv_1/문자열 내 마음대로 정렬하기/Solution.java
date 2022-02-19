import java.util.Arrays;

class Solution {
	public String[] solution(String[] strings, int n) {
		String tmp = "";
		Arrays.sort(strings);
		for (int i=0; i<strings.length-1; i++) {
			for (int j=0; j<strings.length-1-i; j++) {
				if (strings[j].charAt(n) > strings[j+1].charAt(n)) {
					tmp = strings[j];
					strings[j] = strings[i+1];;
					strings[i+1] = tmp;
				}
			}
		}
		return strings;
	}
}
//public static void main(String[] args) {
//	Solution s = new Solution();
//	String[] test1 = {"aabzz", "abbcd", "acbzz"};
//	String[] test2 = {"abce", "abcd", "cdx"};
//	String[] ret1 = s.solution(test1, 0);
//	String[] ret2 = s.solution(test2, 2);
//	for (int i=0; i<ret1.length; i++) {
//		System.out.print(ret1[i]);
//		System.out.print(" ");
//	}
//	System.out.println();
//	for (int i=0; i<ret2.length; i++) {
//		System.out.print(ret2[i]);
//		System.out.print(" ");
//	}
//}
