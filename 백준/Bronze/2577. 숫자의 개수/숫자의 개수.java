import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int A = Integer.parseInt(br.readLine());
        int B = Integer.parseInt(br.readLine());
        int C = Integer.parseInt(br.readLine());
        String mul = (A * B * C) + "";

        int[] cnt = new int[10];
        for(char ch: mul.toCharArray()) {
            int d = ch - '0';
            cnt[d]++;
        }

        for(int i = 0; i <= 9; i++) {
            bw.write(cnt[i] + "\n");
        }

        bw.flush();
        br.close();
        bw.close();
    }
}
