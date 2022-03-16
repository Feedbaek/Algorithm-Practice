import java.io.*;

public class Main {
	static int min = 1000000000;
	static int max = -1000000000;
	static void rec_oper(int[] numbers, int[] operator, int sum, int i) {
		if (i == numbers.length) {
			if (sum < min)
				min = sum;
			if (sum > max)
				max = sum;
			return ;
		}
		if (operator[0] > 0) {
			operator[0]--;
			rec_oper(numbers, operator, sum+numbers[i], i+1);
			operator[0]++;
		}
		if (operator[1] > 0) {
			operator[1]--;
			rec_oper(numbers, operator, sum-numbers[i], i+1);
			operator[1]++;
		}
		if (operator[2] > 0) {
			operator[2]--;
			rec_oper(numbers, operator, sum*numbers[i], i+1);
			operator[2]++;
		}
		if (operator[3] > 0) {
			operator[3]--;
			rec_oper(numbers, operator, sum/numbers[i], i+1);
			operator[3]++;
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int[] numbers = new int[n];
		int[] operator = new int[4];
		String[] input = br.readLine().split(" ");
		for (int i=0; i<n; i++)
			numbers[i] = Integer.parseInt(input[i]);
		input = br.readLine().split(" ");
		for (int i=0; i<4; i++)
			operator[i] = Integer.parseInt(input[i]);
		rec_oper(numbers, operator, numbers[0], 1);
		bw.write(String.valueOf(max)+"\n"+String.valueOf(min)+"\n");
		bw.close();
	}
}
