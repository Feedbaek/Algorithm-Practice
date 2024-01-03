package 가장_큰_수;

class Solution {
	int compare(String s1, String s2) {
		if (Long.parseLong(s1+s2) > Long.parseLong(s2+s1))
			return -1;
		else if (Long.parseLong(s1+s2) < Long.parseLong(s2+s1))
			return 1;
		return 0;
	}

	void quickSort(String[] arr,int start, int end) {
		int part = partition(arr,start,end);
		if(start<part-1) quickSort(arr,start,part-1);
		if(end>part) quickSort(arr,part,end);
	}

	int partition(String[] arr,int start,int end) {
		String pivot=arr[(start+end)/2];
		while(start<=end) {
			while(compare(arr[start], pivot) < 0) start++;
			while(compare(arr[end], pivot) > 0) end--;
			if(start<=end) {
				swap(arr,start,end);
				start++;
				end--;
			}
		}
		return start;
	}

	void swap(String[] arr,int start,int end) {
		String tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		return;
	}

	public String solution(int[] numbers) {
		StringBuilder sb = new StringBuilder();
		String[] list = new String[numbers.length];
		for (int i=0; i<numbers.length; i++)
			list[i] = String.valueOf(numbers[i]);
		quickSort(list, 0, numbers.length-1);
		if (list[0].equals("0"))
			return "0";
		for (int i=0; i<numbers.length; i++)
			sb.append(list[i]);
		return sb.toString();
	}
	public static void main(String[] args) {
		Solution s = new Solution();
		System.out.println(s.solution(new int[] {6, 10, 2}).equals("6210"));
		System.out.println(s.solution(new int[] {3, 30, 34, 5, 9}).equals("9534330"));
		System.out.println(s.solution(new int[] {40,400}).equals("40400"));
		System.out.println(s.solution(new int[] {40,404}).equals("40440"));
		System.out.println(s.solution(new int[] {48,484}).equals("48484"));
		System.out.println(s.solution(new int[] {12,121}).equals("12121"));
		System.out.println(s.solution(new int[] {3054,305}).equals("3054305"));
		System.out.println(s.solution(new int[] {3044,304}).equals("3044304"));
		System.out.println(s.solution(new int[] {340,3403}).equals("3403403"));
		System.out.println(s.solution(new int[] {340,3402}).equals("3403402"));
		System.out.println(s.solution(new int[] {340,3405}).equals("3405340"));
		System.out.println(s.solution(new int[] {40,405}).equals("40540"));
		System.out.println(s.solution(new int[] {40,404}).equals("40440"));
		System.out.println(s.solution(new int[] {40,403}).equals("40403"));
		System.out.println(s.solution(new int[] {40,405}).equals("40540"));
		System.out.println(s.solution(new int[] {40,404}).equals("40440"));
		System.out.println(s.solution(new int[] {50,403}).equals("50403"));
		System.out.println(s.solution(new int[] {50,405}).equals("50405"));
		System.out.println(s.solution(new int[] {50,404}).equals("50404"));
		System.out.println(s.solution(new int[] {30,403}).equals("40330"));
		System.out.println(s.solution(new int[] {30,405}).equals("40530"));
		System.out.println(s.solution(new int[] {30,404}).equals("40430"));
		System.out.println(s.solution(new int[] {12,121}).equals("12121"));
		System.out.println(s.solution(new int[] {2,22,223}).equals("223222"));
		System.out.println(s.solution(new int[] {41,415}).equals("41541"));
		System.out.println(s.solution(new int[] {2,22 }).equals("222"));
		System.out.println(s.solution(new int[] {70,0,0,0}).equals("70000"));
		System.out.println(s.solution(new int[] {0,0,0,1000}).equals("1000000"));
		System.out.println(s.solution(new int[] {0,0,0,0}).equals("0"));
		System.out.println(s.solution(new int[] {0,0,70}).equals("7000"));
		System.out.println(s.solution(new int[] {12,1213}).equals("121312"));
		System.out.println(s.solution(new int[] {3, 30, 34, 5, 91}).equals("91534330"));
		System.out.println(s.solution(new int[] {3, 30, 34, 5, 191}).equals("534330191"));
		System.out.println(s.solution(new int[] {3, 30, 34, 5, 191, 432789}).equals("543278934330191"));
		System.out.println(s.solution(new int[] {1,2,3,4,5,44}).equals("5444321"));
		System.out.println(s.solution(new int[] {1,2,3,4,5,66}).equals("6654321"));
		System.out.println(s.solution(new int[] {3, 30, 31, 5, 9}).equals("9533130"));
		System.out.println(s.solution(new int[] {3, 30, 31, 34, 5, 9}).equals("953433130"));
		System.out.println(s.solution(new int[] {3, 30, 31, 34, 33, 5, 9}).equals("95343333130"));
		System.out.println(s.solution(new int[] {10, 101}).equals("10110"));
		System.out.println(s.solution(new int[] {1, 11, 111, 1111}).equals("1111111111"));
		System.out.println(s.solution(new int[] {0, 0, 0, 0, 0, 0}).equals("0"));
	}
}
