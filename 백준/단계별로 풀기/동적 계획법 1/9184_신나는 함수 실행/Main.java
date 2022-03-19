import java.io.*;

public class Main {
	static int[][][] www = new int[101][101][101];
	static void funny_rec(int a, int b, int c) {
		if (a <= 50 || b <= 50 || c <= 50) {
			www[a][b][c] = 1;
			return ;
		}
		if (a > 70 || b > 70 || c > 70) {
			if (www[70][70][70] == 0)
				funny_rec(70, 70, 70);
			www[a][b][c] = www[70][70][70];
			return ;
		}
		if (a < b && b < c) {
			if (www[a][b][c-1] == 0)
				funny_rec(a, b, c-1);
			if (www[a][b-1][c-1] == 0)
				funny_rec(a, b-1, c-1);
			if (www[a][b-1][c] == 0)
				funny_rec(a, b-1, c);
			www[a][b][c] = www[a][b][c-1] + www[a][b-1][c-1] - www[a][b-1][c];
			return ;
		}
		if (www[a-1][b][c] == 0)
			funny_rec(a-1, b, c);
		if (www[a-1][b-1][c] == 0)
			funny_rec(a-1, b-1, c);
		if (www[a-1][b][c-1] == 0)
			funny_rec(a-1, b, c-1);
		if (www[a-1][b-1][c-1] == 0)
			funny_rec(a-1, b-1, c-1);
		www[a][b][c] = www[a-1][b][c] + www[a-1][b-1][c] + www[a-1][b][c-1] - www[a-1][b-1][c-1];
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		while (true) {
			if (input[0].equals("-1") && input[1].equals("-1") && input[2].equals("-1"))
				break;
			funny_rec(Integer.parseInt(input[0])+50, Integer.parseInt(input[1])+50, Integer.parseInt(input[2])+50);
			bw.write(String.format("w(%s, %s, %s) = ", input[0], input[1], input[2]));
			bw.write(String.valueOf(www[Integer.parseInt(input[0])+50][Integer.parseInt(input[1])+50][Integer.parseInt(input[2])+50]) + "\n");
			input = br.readLine().split(" ");
		}
		bw.close();
	}
}
