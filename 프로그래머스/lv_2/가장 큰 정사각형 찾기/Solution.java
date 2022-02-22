class Solution {
	public int solution(int [][]board) {
		int answer = 0;
		for (int i=1; i<board.length; i++)
			for (int j=1; j<board[0].length; j++)
				if (board[i][j] == 1) {
					int tmp = (board[i-1][j] < board[i][j-1]) ? board[i-1][j] : board[i][j-1];
					board[i][j] = tmp < board[i-1][j-1] ? tmp+1 : board[i-1][j-1]+1;
				}
		for (int i=0; i<board.length; i++)
			for (int j=0; j<board[0].length; j++)
				if (answer < board[i][j])
					answer = board[i][j];
		return answer * answer;
	}
}
