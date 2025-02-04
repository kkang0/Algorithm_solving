import java.io.*;
import java.util.*;

public class Main {
    static int N, M, V;
    static List<Integer>[] graph;
    static boolean[] visited;

    public static void bfs(int cur) {
        Queue<Integer> queue = new LinkedList<>();
        visited[cur] = true;
        queue.add(cur);
        
        while (!queue.isEmpty()) {
            int n = queue.poll();
            System.out.print(n + " ");
            
            for (int next : graph[n]) {
                if (!visited[next]) {
                    visited[next] = true;
                    queue.add(next);
                }
            }
        }
    }

    public static void dfs(int cur) {
        System.out.print(cur + " ");
        visited[cur] = true;
        
        for (int next : graph[cur]) {
            if (!visited[next]) {
                dfs(next);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());
        V = Integer.parseInt(st.nextToken());
        
        graph = new ArrayList[N + 1];
        for (int i = 1; i <= N; i++) {
            graph[i] = new ArrayList<>();
        }
        
        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            graph[a].add(b);
            graph[b].add(a);
        }
        
        for (int i = 1; i <= N; i++) {
            Collections.sort(graph[i]);
        }
        
        visited = new boolean[N + 1];
        dfs(V);
        System.out.println();
        
        Arrays.fill(visited, false);
        bfs(V);
        System.out.println();
    }
}