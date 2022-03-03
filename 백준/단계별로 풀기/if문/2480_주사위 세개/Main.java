import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		int cnt = 0;
		int same_num = 0;
		int big = Integer.parseInt(input[2]);
		int money = 0;
		for (int i=0; i<2; i++) {
			if (big < Integer.parseInt(input[i]))
				big = Integer.parseInt(input[i]);
			if (input[i].equals(input[i+1])) {
				same_num = Integer.parseInt(input[i]);
				cnt++;
			}
		}
		if (input[0].equals(input[2])) {
			same_num = Integer.parseInt(input[0]);
			cnt++;
		}
		if (cnt == 1)
			money = 1000;
		else if (cnt > 1)
			money = 10000;
		if (cnt == 0)
			same_num = big;
		if (cnt > 1)
			money += same_num * 1000;
		else
			money += same_num * 100;
		bw.write(String.valueOf(money));
		bw.newLine();
		bw.close();
	}
}
