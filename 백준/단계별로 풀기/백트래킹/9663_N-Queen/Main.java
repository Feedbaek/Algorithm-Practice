import java.io.*;

public class Main {
	static int answer = 0;
	static void queen_is_back(int row, int column, int[][] chess, int n) {
		for (int i=0; i<row; i++)		// 세로 검사
			if (chess[i][column] == 1)
				return ;
		for (int i=0; i<column; i++)	// 가로 검사
			if (chess[row][i] == 1)
				return ;
		for (int i=0; row-i>=0 && column-i>=0; i++)	// 왼쪽위 대각선 검사
			if (chess[row-i][column-i] == 1)
				return ;
		for (int i=0; row-i>=0 && column+i<n; i++)	// 오른쪽위 대각선 검사
			if (chess[row-i][column+i] == 1)
				return ;
		if (row == n-1) {		// 마지막 행이였으면
			answer++;
			return ;
		}
		chess[row][column] = 1;	// 퀸 배치
		for (int i=0; i<n; i++)
			queen_is_back(row+1, i, chess, n);	// 다음 행 퀸 검사
		chess[row][column] = 0;	// 퀸 회수
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int[][] chess = new int[n][n];
		for (int i=0; i<n; i++)
			queen_is_back(0, i, chess, n);
		bw.write(String.valueOf(answer));
		bw.newLine();
		bw.close();
	}
}
