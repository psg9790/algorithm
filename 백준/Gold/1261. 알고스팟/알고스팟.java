import java.io.*;
import java.util.*;

public class Main {
    static final int[] dy = new int[]{-1, 1, 0, 0};
    static final int[] dx = new int[]{0, 0, -1, 1};
    static int n, m;
    static int[][] arr;

    static int BFS_01() {
        int[][] dp = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            Arrays.fill(dp[i], -1);
        }
        LinkedList<Pos> q = new LinkedList<>();
        q.add(new Pos(1, 1));
        dp[1][1] = 0;
        while (!q.isEmpty()) {
            Pos frt = q.poll();

            for (int k = 0; k < 4; k++) {
                int yy = frt.y + dy[k];
                int xx = frt.x + dx[k];
                if (yy < 1 | yy > n | xx < 1 | xx > m) {
                    continue;
                }
                if (dp[yy][xx] != -1) {
                    continue;
                }
                if (arr[yy][xx] == 0) {
                    dp[yy][xx] = dp[frt.y][frt.x];
                    q.add(0, new Pos(yy, xx));
                } else if (arr[yy][xx] == 1) {
                    dp[yy][xx] = dp[frt.y][frt.x] + 1;
                    q.add(new Pos(yy, xx));
                }
            }
        }
        return dp[n][m];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        m = Integer.parseInt(st.nextToken());
        n = Integer.parseInt(st.nextToken());
        arr = new int[n + 1][m + 1];
        for (int i = 1; i <= n; i++) {
            String line = br.readLine();
            for (int j = 1; j <= m; j++) {
                arr[i][j] = line.charAt(j - 1) - '0';
            }
        }
        System.out.println(BFS_01());
    }
}

class Pos {
    int y, x;
    int broken;

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}

