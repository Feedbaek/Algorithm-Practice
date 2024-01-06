import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

public class 삼각김밥_월드 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		int[] arr = new int[151];
		arr[1] = 1;

		// 1 2 4 7 11 16 22 29 37 46 56 67 79 92 106 ...
		for (int i=2; i<151; ++i) {
			arr[i] = arr[i-1] + (i-1);
		}

		int T = Integer.parseInt(br.readLine());
		for (int i=0; i<T; ++i) {
			int answer = 0;
			StringTokenizer st = new StringTokenizer(br.readLine());
			int s = Integer.parseInt(st.nextToken());
			int e = Integer.parseInt(st.nextToken());

			// s가 e보다 크면 swap
			if (s > e) {
				int temp = s;
				s = e;
				e = temp;
			}
			// s와 e의 행 위치를 찾는다.
			int sRow = 0;
			int eRow = 0;
			for (int j=1; j<151; ++j) {
				if (s >= arr[j]) {
					sRow = j;
				}
				if (e >= arr[j]) {
					eRow = j;
				} else {
					break;
				}
			}
			// s와 e의 열 위치를 찾는다.
			int sCol = s - arr[sRow] + 1;
			int eCol = e - arr[eRow] + 1;

			// s에서 한 칸씩 올라가면서 e와 같아지는 지점을 찾는다.
			// 왼쪽으로 이동하면서 올라가면 값은 해당 행의 값 만큼 증가,
			// 오른쪽으로 이동하면서 올라가면 값은 해당 행의 값 + 1 만큼 증가
			while (sRow != eRow) {
				if (sCol < eCol) {
					s += sRow + 1;
					++sCol;
				} else {
					s += sRow;
				}
				++sRow;
				++answer;
			}
			// s와 e의 값 차이만큼 answer에 더해준다.
			answer += Math.abs(s - e);
			bw.write("#" + (i+1) + " " + answer + "\n");
			bw.flush();
		}
		bw.close();
	}
}
