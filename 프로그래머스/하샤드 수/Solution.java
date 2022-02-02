class Solution {
	public boolean solution(int x) {
		int sum = 0;
		int tmp = x;
		while (tmp > 0) {
			sum += tmp % 10;
			tmp /= 10;
		}
		if (x % sum == 0)
			return true;
		return false;
	}
}
