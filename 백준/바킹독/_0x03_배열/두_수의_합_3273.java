package _0x03_배열;

import java.io.*;

public class 두_수의_합_3273 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int N = Integer.parseInt(br.readLine());
        int[] arr = new int[10];

        while (N > 0) {
            int n = N % 10;
            ++arr[n];
            N /= 10;
        }

        int maxValue = 0;
        for (int i=0; i<10; ++i) {
            if (arr[i] > maxValue) {
                if (i == 6 || i == 9) {
                    int sum = (arr[6] + arr[9] + 1) / 2;
                    if (sum > maxValue) {
                        maxValue = sum;
                    }
                } else {
                    maxValue = arr[i];
                }
            }
        }

        bw.write(String.valueOf(maxValue));
        bw.close();
    }
}
