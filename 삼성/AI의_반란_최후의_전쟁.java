import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class AI의_반란_최후의_전쟁 {
	static int minValue = Integer.MAX_VALUE;
	static int agentA = -1;
	static int agentB = -1;
	static int agentC = -1;

	public static void rec(boolean[] status, int[] agent, int[][] a, int[][] b, int[][] c) {
		// 모든 능력치가 선택되었으면
		if (status[0] && status[1] && status[2]) {
			int sum = 0;
			int tmpA = -1;
			int tmpB = -1;
			int tmpC = -1;

			for (int i=0; i<agent.length; ++i) {
				if (agent[i] == 1) {
					sum += a[i][0];
					tmpA = i;
				} else if (agent[i] == 2) {
					sum += b[i][0];
					tmpB = i;
				} else if (agent[i] == 3) {
					sum += c[i][0];
					tmpC = i;
				}
			}
			if (sum < minValue) {
				minValue = sum;
				agentA = tmpA;
				agentB = tmpB;
				agentC = tmpC;
			}
			return;
		}

		for (int i=0; i<status.length; ++i) {
			// 선택되지 않은 능력치
			if (!status[i]) {
				status[i] = true;
				// a 능력치 합이 가장 작은 요원을 찾는다.
				if (i == 0) {
					for (int j=0; j<a.length; ++j) {
						int agentIndex = a[j][1];
						// 선택되지 않은 요원
						if (agent[agentIndex] == 0) {
							agent[agentIndex] = 1;
							rec(status, agent, a, b, c);
							agent[agentIndex] = 0;
						}
					}
				} else if (i == 1) {
					for (int j=0; j<b.length; ++j) {
						int agentIndex = b[j][1];
						// 선택되지 않은 요원
						if (agent[agentIndex] == 0) {
							agent[agentIndex] = 2;
							rec(status, agent, a, b, c);
							agent[agentIndex] = 0;
						}
					}
				} else {
					for (int j=0; j<c.length; ++j) {
						int agentIndex = c[j][1];
						// 선택되지 않은 요원
						if (agent[agentIndex] == 0) {
							agent[agentIndex] = 3;
							rec(status, agent, a, b, c);
							agent[agentIndex] = 0;
						}
					}
				}
				status[i] = false;
			}
		}
	}
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

		// 테스트 케이스의 개수
		int T = Integer.parseInt(br.readLine());

		for (int i=0; i<T; ++i) {
			int answer = 0;
			// 요원의 수
			int n = Integer.parseInt(br.readLine());
			// 각 능력치 별로 요원이 버리는 능력치의 합을 저장하는 배열
			int[][] a = new int [n][2];
			int[][] b = new int [n][2];
			int[][] c = new int [n][2];
			int[] arr = new int[n];

			for (int j=0; j<n; ++j) {
				String[] input = br.readLine().split(" ");
				a[j][0] = Integer.parseInt(input[1]) + Integer.parseInt(input[2]);
				a[j][1] = j;
				b[j][0] = Integer.parseInt(input[0]) + Integer.parseInt(input[2]);
				b[j][1] = j;
				c[j][0] = Integer.parseInt(input[0]) + Integer.parseInt(input[1]);
				c[j][1] = j;

				// 요원의 가장 높은 능력치를 제외하고 버리는 능력치의 합을 저장
				arr[j] = Integer.parseInt(input[0]) + Integer.parseInt(input[1]) + Integer.parseInt(input[2])
				 - Math.max(Integer.parseInt(input[0]), Math.max(Integer.parseInt(input[1]), Integer.parseInt(input[2])));
			}
			// 능력의 합을 기준으로 오름차순 정렬
			Arrays.sort(a, (o1, o2) -> o1[0] - o2[0]);
			Arrays.sort(b, (o1, o2) -> o1[0] - o2[0]);
			Arrays.sort(c, (o1, o2) -> o1[0] - o2[0]);

			rec(new boolean[3], new int[n], a, b, c);

			answer += minValue;
			minValue = Integer.MAX_VALUE;

			for (int j=0; j<n; ++j) {
				if (j != agentA && j != agentB && j != agentC) {
					answer += arr[j];
				}
			}

			if (n < 3) {
				answer = -1;
			}

			bw.write("#" + (i+1) + " " + answer + "\n");
		}
		bw.close();
	}
}
