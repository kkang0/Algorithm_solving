import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int N = Integer.parseInt(st.nextToken());

        PriorityQueue<Integer> pq = new PriorityQueue<>(
                (a, b) -> {
                    if(Math.abs(a) == Math.abs(b)) return a - b;
                    return Math.abs(a) - Math.abs(b);
                }
        );
        for(int i = 0; i < N; i++) {
            int num = Integer.parseInt(br.readLine());

            if(num == 0) {
                if(pq.isEmpty()) {
                    System.out.println(0);
                } else {
                    System.out.println(pq.peek());
                    pq.poll();
                }
            } else {
                pq.add(num);
            }
        }
    }
}