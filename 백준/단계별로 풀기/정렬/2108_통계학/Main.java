import java.io.*;
import java.util.Arrays;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int n = Integer.parseInt(br.readLine());
		double sum = 0;
		int[] arr1 = new int[n];
		int[] arr2 = new int[8001];
		int many_num = 0;
		int cnt = 0;
		for (int i=0; i<n; i++) {
			int num = Integer.parseInt(br.readLine());
			sum += num;
			arr1[i] = num;
			arr2[num + 4000] += 1;
		}
		for (int i=0, dup=0; i<8001; i++)
			if (cnt <= arr2[i]) {
				if (cnt == arr2[i])
					dup++;
				else {
					dup = 0;
					many_num = i;
					cnt = arr2[i];
				}
				if (dup == 1) {
					many_num = i;
					cnt = arr2[i];
				}
			}
		Arrays.sort(arr1);
		bw.write(String.valueOf(Math.round(sum / n))+"\n");
		bw.write(String.valueOf(arr1[n / 2])+"\n");
		bw.write(String.valueOf(many_num-4000)+"\n");
		bw.write(String.valueOf(arr1[n-1] - arr1[0])+"\n");
		bw.close();
	}
}
