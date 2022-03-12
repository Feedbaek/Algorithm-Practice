import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		StringBuilder sb = new StringBuilder();
		int n = sc.nextInt();
		int[] arr = new int[n];
		int[] sort = new int[n];
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		for (int i=0; i<n; i++) {
			arr[i] = sc.nextInt();
			sort[i] = arr[i];
		}
		Arrays.sort(sort);
		for (int i=0, rank=0; i<n; i++) {
			if (!map.containsKey(sort[i])) {
				map.put(sort[i], rank);
				rank++;
			}
		}
		for (int i=0; i<n; i++) {
			sb.append(map.get(arr[i]));
			sb.append(" ");
		}
		System.out.println(sb.toString());
	}
}
