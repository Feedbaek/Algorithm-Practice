import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Main {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
	static StringBuilder sb = new StringBuilder();

	public static void rec_print(int n, int m, int dept) throws IOException {
		if (dept > m) {	// m개만큼 수열 만들었으면
			bw.write(sb.toString());	// 수열 출력
			bw.newLine();	// 출력 후 개행
			return ;
		}
		sb.append(" ");	// 공백 추가
		for (int i=1; i<=n; i++) {
			if (sb.indexOf(String.valueOf(i)) != -1)	// 중복이면 패스
				continue ;
			sb.append(i);	// 숫자 추가
			rec_print(n, m, dept+1);	// 다음 숫자탐색
			sb.delete((dept-1) * 2, (dept-1) * 2 + 1);	// 숫자 삭제
		}
		sb.delete((dept-1) * 2 - 1, (dept-1) * 2);	// 공백 삭제
	}
	public static void main(String[] args) throws IOException {
		String[] input = br.readLine().split(" ");
		int n = Integer.parseInt(input[0]);
		int m = Integer.parseInt(input[1]);

		for (int i=1; i<=n; i++) {	// 첫 자릿 수만 따로 계산
			sb.append(i);	// 첫 숫자 추가
			rec_print(n, m, 2);	// 다음 숫자탐색
			sb.delete(0, 1);	// 첫 숫자 삭제
		}
		bw.flush();	// 버퍼에 남은 문자열 출력
		bw.close();	// 출력 스트림 닫기 (사실 내부적으로 flush메소드 호출)
	}
}
