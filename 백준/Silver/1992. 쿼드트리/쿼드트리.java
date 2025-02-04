import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static String[] video;

    public static void quadtree(int size, int y, int x) {
        char cur = video[y].charAt(x);

        for(int i = y; i < y + size; i++)
            for(int j = x; j < x + size; j++) {
                if(video[i].charAt(j) != cur) {
                    System.out.print("(");
                    quadtree(size / 2, y, x);
                    quadtree(size / 2, y, x + size / 2);
                    quadtree(size / 2, y + size / 2, x);
                    quadtree(size / 2, y + size / 2, x + size / 2);
                    System.out.print(")");
                    return;
                }
            }

        System.out.print(cur);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        video = new String[N];

        for(int i = 0; i < N; i++) {
            String str = br.readLine();
            for(int j = 0; j < N; j++) {
                video[i] = str;
            }
        }

        quadtree(N, 0, 0);
        System.out.println();
    }
}