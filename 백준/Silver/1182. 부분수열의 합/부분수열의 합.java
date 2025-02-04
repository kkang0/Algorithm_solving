import java.io.*;
import java.util.*;

public class Main {
    static int[] v;
    static int N, S, result = 0;

    static void dfs(int i, int sum) {
        if(i == N) {
            if(sum == S) result++;
            return;
        }

        dfs(i + 1, sum);
        dfs(i + 1, sum + v[i]);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        S = Integer.parseInt(st.nextToken());
        v = new int[N];

        st = new StringTokenizer(br.readLine(), " ");
        for(int i = 0; i < N; i++) {
            v[i] = Integer.parseInt(st.nextToken());
        }

        dfs(0, 0);

        if(S == 0) result--;
        System.out.println(result);

        bw.flush();
        bw.close();
        br.close();
    }
}