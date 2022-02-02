import java.util.*;

class Solution {
	public long solution(long n) {
		char[] arr = String.valueOf(n).toCharArray();
		Arrays.sort(arr);
		return Long.parseLong(new StringBuffer(new String(arr)).reverse().toString());
	}
}

//char[] arr = String.valueOf(n).toCharArray();
//Arrays.sort(arr);
//StringBuilder sb = new StringBuilder(new String(arr,0,arr.length));
//return (Integer.parseInt(sb.reverse().toString()));
