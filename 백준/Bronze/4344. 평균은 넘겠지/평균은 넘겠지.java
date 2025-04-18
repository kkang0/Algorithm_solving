import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int C = Integer.parseInt(br.readLine());

        for(int i = 0; i < C; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int N = Integer.parseInt(st.nextToken());
            int[] score = new int[N];
            double sum = 0;
            for(int j = 0; j < N; j++) {
                score[j] = Integer.parseInt(st.nextToken());
                sum += score[j];
            }

            double avg = sum / N;
            int count = 0;
            for(int j = 0; j < N; j++) {
                if(score[j] > avg) count++;
            }

            double ratio = (double)count/ N * 100;
            bw.write(String.format("%.3f%%\n", ratio));
        }

        bw.flush();
        br.close();
        bw.close();
    }
}