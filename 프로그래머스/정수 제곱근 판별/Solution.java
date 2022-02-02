class Solution {
	public long solution(long n) {
		for (long i=1,s=0; s<n; i++) {
			s = i * i;
			if (s == n)
				return ((i + 1) * (i + 1));
		}
		return (-1);
		//if (Math.pow(n, 0.5) % 1 == 0)
		//	return ((long)Math.pow(Math.pow(n, 0.5) + 1, 2));
		//return -1;
	}
}
