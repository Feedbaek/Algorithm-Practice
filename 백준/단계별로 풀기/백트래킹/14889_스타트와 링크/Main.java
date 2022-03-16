import java.io.*;

public class Main {
	static int min = -1;
	static int[][] arr;

	static boolean is_team(int[] team, int man) {
		for (int i=0; i<team.length; i++)
			if (team[i] == man)
				return true;
		return false;
	}

	static void get_diff(int[] people, int[] start) {
		int start_sum = 0;
		int link_sum = 0;
		int[] link = new int[start.length];

		for (int i=0, j=0; i<people.length; i++)
			if (people[i] == 0) {
				link[j] = i;
				j++;
			}
		for (int i=0; i<start.length; i++)
			for (int j=0; j<people.length; j++)
				if (is_team(start, j))
					start_sum += arr[start[i]][j];
		for (int i=0; i<link.length; i++)
			for (int j=0; j<people.length; j++)
				if (is_team(link, j))
					link_sum += arr[link[i]][j];
		if (min == -1 || Math.abs(start_sum - link_sum) < min)
			min = Math.abs(start_sum - link_sum);
	}

	static void pick_team(int[] people, int[] start, int n) {
		if (n == start.length) {
			get_diff(people, start);
			return ;
		}
		for (int i=0; i<people.length; i++)
			if (people[i] == 0) {
				people[i] = 1;
				start[n] = i;
				pick_team(people, start, n+1);
				people[i] = 0;
			}
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		int[] people = new int[n];
		int[] start = new int[n/2];
		arr = new int[n][n];
		for (int i=0; i<n; i++) {
			String[] input = br.readLine().split(" ");
			for (int j=0; j<n; j++)
				arr[i][j] = Integer.valueOf(input[j]);
		}
		pick_team(people, start, 0);
		bw.write(String.valueOf(min)+"\n");
		bw.close();
	}
}
