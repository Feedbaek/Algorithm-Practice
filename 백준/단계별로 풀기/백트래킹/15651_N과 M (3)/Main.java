import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int[] answer;

	public static void dfs(int n, int m, int dept) throws IOException {
		if (dept == m) {
			for (int i=0; i<m; i++)
				bw.write(String.valueOf(answer[i]) + " ");
			bw.newLine();
			return ;
		}
		for (int i=1; i<=n; i++) {
			answer[dept] = i;
			dfs(n, m, dept+1);
		}
	}
	public static void main(String[] args) throws IOException {
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);
		answer = new int[m];
		dfs(n, m, 0);
		bw.flush();
		bw.close();
	}
}
