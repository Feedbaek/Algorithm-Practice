import java.io.*;

public class Main {
	static int rec_add(String str, boolean minus) {
		int sum = 0;
		int num = 0;

		for (int i=0; i<str.length(); i++) {
			if (Character.isDigit(str.charAt(i)))
				num = num * 10 + (str.charAt(i) - '0');
			else if (str.charAt(i) == '+') {
				sum += num;
				num = 0;
			}
			else {
				sum += num;
				if (minus)
					return sum + rec_add(str.substring(i+1, str.length()), true);
				return sum - rec_add(str.substring(i+1, str.length()), true);
			}
		}
		return sum + num;
	}
	static int joono_theory(String str) {
		int sum = 0;
		int num = 0;
		boolean first_minus = false;

		for (int i=0; i<str.length(); i++) {
			if (Character.isDigit(str.charAt(i)))
				num = num * 10 + (str.charAt(i) - '0');
			else if (!first_minus) {
				if (str.charAt(i) == '-')
					first_minus = true;
				sum += num;
				num = 0;
			}
			else {
				sum -= num;
				num = 0;
			}
		}
		if (first_minus)
			return sum - num;
		return sum + num;
	}
	static int half_joono_theory(String str) {
		int sum = 0;
		String[] arr = str.split("\\-", 2);		// 처음 "-"를 기준으로 문자열 2개로 나눔
		for (String num : arr[0].split("\\+"))			// "-"이전 값들을 더해줌
			sum += Integer.parseInt(num);
		if (arr.length == 2)		// "-" 가 존재하면
			for (String num : arr[1].split("\\+|\\-"))		// "-" 이후 값들은 빼줌
				sum -= Integer.parseInt(num);
		return sum;
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String str = br.readLine();

		bw.write("rec_add: " + String.valueOf(rec_add(str, false)));
		bw.newLine();
		bw.write("joono_theory: " + String.valueOf(joono_theory(str)));
		bw.newLine();
		bw.write("half_joono_theory: " + String.valueOf(half_joono_theory(str)));
		bw.newLine();
		bw.close();
	}
}
