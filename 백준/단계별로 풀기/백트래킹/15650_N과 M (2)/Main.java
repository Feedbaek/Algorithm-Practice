import java.io.*;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static int[] answer;

	public static void dfs(int n, int m, int dept, int prev) throws IOException{
		if (dept == m) {
			for (int i=0; i<m; i++)
				bw.write(String.valueOf(answer[i] + 1) + " ");
			bw.newLine();
			return ;
		}

		for (int i=prev + 1; i<n; i++) {
			Boolean flag = true;
			for (int j=0; j<dept; j++)
				if (answer[j] == i)
					flag = false;
			if (flag) {
				answer[dept] = i;
				dfs(n, m, dept + 1, i);
			}
		}
	}
	public static void main(String[] args) throws IOException {
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);
		answer = new int[m];

		dfs(n, m, 0, -1);
		bw.flush();
		bw.close();
	}
}
