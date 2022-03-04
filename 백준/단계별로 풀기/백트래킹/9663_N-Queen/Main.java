import java.io.*;

public class Main {
	static int[][] chess;
	static int answer = 0;
	public static void dfs(int row, int column) {
		if (row == chess.length) {
			answer += 1;
			return ;
		}
		for (int n=row; n<chess.length; n++) {
			for (int m=column; m<chess.length; m++) {
				for (int i=0; i<=n; i++)
					if (chess[i][m] == 1)
						return ;
				for (int i=0; i<=m; i++)
					if (chess[n][i] == 1)
						return ;
				for (int i=n, j=m; i>=0&&j>=0; i--, j--)
					if (chess[i][j] == 1)
						return ;
				chess[n][m] = 1;
				if (m+1 == chess.length)
					dfs(n+1, 0);
				else
					dfs(n, m+1);
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		chess = new int[n][n];
		dfs(0, 0);
		bw.write(String.valueOf(answer));
		bw.close();
	}
}
