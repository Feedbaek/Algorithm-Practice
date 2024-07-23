package _0x03_배열;

import java.io.*;

public class 방_번호_1475 {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int A, B, C, mul;
        int[] arr = new int[10];

        A = Integer.parseInt(br.readLine());
        B = Integer.parseInt(br.readLine());
        C = Integer.parseInt(br.readLine());
        mul = A * B * C;

        while (mul > 0) {
            int n = mul % 10;
            arr[n] += 1;
            mul /= 10;
        }

        for (int i=0; i<10; ++i) {
            bw.write(String.valueOf(arr[i]) + "\n");
        }
        bw.close();
    }
}
