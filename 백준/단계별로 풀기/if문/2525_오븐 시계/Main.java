import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String[] input = br.readLine().split(" ");
		int[] current_time = {Integer.parseInt(input[0]), Integer.parseInt(input[1])};
		int cooking_time = Integer.parseInt(br.readLine());
		current_time[0] += (current_time[1] + cooking_time) / 60;
		current_time[1] = (current_time[1] + cooking_time) % 60;
		current_time[0] = current_time[0] % 24;
		bw.write(String.valueOf(current_time[0]) + " " + String.valueOf(current_time[1]));
		bw.newLine();
		bw.close();
	}
}
