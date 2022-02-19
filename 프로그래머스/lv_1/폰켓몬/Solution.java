import java.util.ArrayList;

class Solution {
	public int solution(int[] nums) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		for (int i=0; i<nums.length; i++)
			if (!list.contains(nums[i]))
				list.add(nums[i]);
		if (nums.length / 2 > list.size())
			return list.size();
		return nums.length / 2;
	}
}
