import java.io.*;
import java.util.*;

public class Main {
    static final int[] dy = new int[]{-1, 1, 0, 0};
    static final int[] dx = new int[]{0, 0, -1, 1};
    static int n, m;
    static int[][] arr;

    static int CalcDist(int y, int x) {
        return Math.abs(y - n) + Math.abs(x - m);
    }

    static int Dijkstra() {
        int result = 0;
        Set<Pos> visited = new HashSet<>();
        PriorityQueue<Pos> pq = new PriorityQueue<>(new Comparator<Pos>() {
            @Override
            public int compare(Pos o1, Pos o2) {
                if (o1.broken == o2.broken) {
                    return o1.dist - o2.dist;
                }
                return o1.broken - o2.broken;
            }
        });
        pq.add(new Pos(1, 1, 0, CalcDist(1, 1)));
        while (!pq.isEmpty()) {
            Pos frt = pq.poll();
            for (int k = 0; k < 4; k++) {
                int yy = frt.y + dy[k];
                int xx = frt.x + dx[k];
                if (yy >= 1 && yy <= n && xx >= 1 && xx <= m) {
                    if (yy == n &&
                            xx == m) {
                        result = frt.broken;
                        return result;
                    }
                    if (arr[yy][xx] == 0) {
                        Pos newpos = new Pos(yy, xx, frt.broken, CalcDist(yy, xx));
                        if (visited.contains(newpos)) {
                            continue;
                        }
                        pq.add(newpos);
                        visited.add(newpos);
                    } else if (arr[yy][xx] == 1) {
                        Pos newpos = new Pos(yy, xx, frt.broken + 1, CalcDist(yy, xx));
                        if (visited.contains(newpos)) {
                            continue;
                        }
                        pq.add(newpos);
                        visited.add(newpos);
                    }
                }
            }
        }
        return result;
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
        System.out.println(Dijkstra());
    }
}

class Pos {
    int y, x;
    int broken;
    int dist;

    public Pos(int y, int x, int broken, int dist) {
        this.y = y;
        this.x = x;
        this.broken = broken;
        this.dist = dist;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Pos) {
            if (this.y == ((Pos) obj).y &&
                    this.x == ((Pos) obj).x &&
                    this.broken == ((Pos) obj).broken) {
                return true;
            }
        }
        return false;
    }

    @Override
    public int hashCode() {
        return this.y * 101 + this.x + this.broken * 10101;
    }
}

