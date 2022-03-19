import java.io.*;

public class Main {
	static int min = -1;
	static int[][] arr;

	static void get_diff(int[] people, int[] start, int[] link) {
		int start_sum = 0;
		int link_sum = 0;

		int len = people.length;
		for (int i=0, j=0; i<len; i++)
			if (people[i] == 0) {
				link[j] = i;
				j++;
			}
		len = start.length;
		for (int i=0; i<len; i++)
			for (int j=0; j<len; j++)
				start_sum += arr[start[i]][start[j]];
		for (int i=0; i<len; i++)
			for (int j=0; j<len; j++)
				link_sum += arr[link[i]][link[j]];
		int tmp = Math.abs(start_sum - link_sum);
		if (min == -1 || tmp < min)
			min = tmp;
	}

	static void pick_team(int[] people, int[] start, int[] link, int n) {
		if (n == start.length) {
			get_diff(people, start, link);
			return ;
		}
		int len = people.length;
		for (int i=0; i<len; i++)
			if (people[i] == 0) {
				people[i] = 1;
				start[n] = i;
				pick_team(people, start, link, n+1);
				people[i] = 0;
			}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int[] people = new int[n];
		int[] link = new int[n];
		int[] start = new int[n/2];
		arr = new int[n][n];
		for (int i=0; i<n; i++) {
			String[] input = br.readLine().split(" ");
			for (int j=0; j<n; j++)
				arr[i][j] = Integer.valueOf(input[j]);
		}
		pick_team(people, start, link, 0);
		bw.write(String.valueOf(min)+"\n");
		bw.close();
	}
}
