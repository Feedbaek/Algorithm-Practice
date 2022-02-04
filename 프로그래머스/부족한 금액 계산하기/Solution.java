class Solution {
	public long solution(int price, long money, int count) {
		for (int i=0; i<count; i++)
			money -= price * (i+1);
		if (money < 0)
			return -money;
		return 0;
	}
}
