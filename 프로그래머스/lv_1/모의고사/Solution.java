import java.util.ArrayList;

class Solution {
	public ArrayList<Integer> solution(int[] answers) {
		ArrayList<Integer> list = new ArrayList<Integer>();
		int[][] students_answer = {{1, 2, 3, 4, 5}, {2, 1, 2, 3, 2, 4, 2, 5}, {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};
		int[] ret = new int[3];
		int high = 0;
		for (int i=0; i<answers.length; i++)
			for (int j=0; j<3; j++)
				if (students_answer[j][i % students_answer[j].length] == answers[i])
					ret[j]++;
		for (int i=0; i<3; i++)
			if (high < ret[i])
				high = ret[i];
		for (int i=0; i<3; i++)
			if (high == ret[i])
				list.add(i+1);
		return list;
	}
}

// 무지성 if문

//for (int i=0; i<answers.length; i++) {
	//if (answers[i] == i % 5 + 1)
	//	ret[0]++;
	//if ((i%2 == 0 && answers[i] == 2) || (i%8 == 1 && answers[i] == 1) || (i%8 == 3 && answers[i] == 3) || (i%8 == 5 && answers[i] == 4) || (i%8 == 7 && answers[i] == 5))
	//	ret[1]++;
	//if (((i%10 == 0 || i%10 == 1) && answers[i] == 3) || ((i%10 == 2 || i%10 == 3) && answers[i] ==1) || ((i%10 == 4 || i%10 == 5 ) && answers[i] ==2) || ((i%10 == 6 || i%10 == 7) && answers[i] == 4) || ((i%10 == 8 || i%10 == 9) && answers[i] == 5))
	//	ret[2]++;
//}
