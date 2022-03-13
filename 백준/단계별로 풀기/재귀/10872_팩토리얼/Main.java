import java.io.*;

public class Main {
	static int factorial(int n) {
		if (n == 0)
			return 1;
		return n * factorial(n-1);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		bw.write(String.valueOf(factorial(Integer.valueOf(br.readLine()))) + "\n");
		bw.close();
	}
}
