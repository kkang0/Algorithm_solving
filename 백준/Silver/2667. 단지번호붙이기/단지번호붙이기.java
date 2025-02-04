import java.util.*;
import java.io.*;

public class Main {
    static int N;
    static int[][] arr;
    static boolean[][] visited;
    static int[] dx = {1, -1, 0, 0};
    static int[] dy = {0, 0, 1, -1};
    static List<Integer> result;

    static int dfs(int x, int y) {
        int count = 1;
        visited[x][y] = true;

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny] || arr[nx][ny] != 1) continue;
            count += dfs(nx, ny);
        }

        return count;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        result = new ArrayList<>();
        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        visited = new boolean[N][N];

        for(int i = 0; i < N; i++) {
            String str = br.readLine();
            for(int j = 0; j < N; j++) {
                arr[i][j] = str.charAt(j) - '0';
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(arr[i][j] == 1 && !visited[i][j]) {
                    result.add(dfs(i, j));
                }
            }
        }

        Collections.sort(result);

        System.out.println(result.size());
        for(int r : result) {
            System.out.println(r);
        }
    }
}