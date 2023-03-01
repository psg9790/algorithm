import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static ArrayList<Pos> list = new ArrayList<>();
    static PriorityQueue<Distance> pq = new PriorityQueue<>((a, b) ->
            (int) Math.ceil(a.distance - b.distance));
    static int[] u;

    static int find(int a) {
        if (u[a] == a) {
            return a;
        }
        return u[a] = find(u[a]);
    }

    static void union(int a, int b) {
        u[find(a)] = find(b);
    }

    static boolean isunion(int a, int b) {
        return find(a) == find(b);
    }

    static double Kruskal() {
        double result = 0;

        while (!pq.isEmpty()) {
            Distance frt = pq.poll();
            if (!isunion(frt.idx1, frt.idx2)) {
                union(frt.idx1, frt.idx2);
                result += frt.distance;
            }
        }
        return result;
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        u = new int[n];
        for (int i = 0; i < n; i++) {
            u[i] = i;
        }

        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            list.add(new Pos(Double.parseDouble(st.nextToken()), Double.parseDouble(st.nextToken())));
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dis = list.get(i).Distance(list.get(j));
                pq.add(new Distance(i, j, dis));
            }
        }
        System.out.println(Kruskal());
    }
}

class Pos {
    double y, x;

    public Pos(double y, double x) {
        this.y = y;
        this.x = x;
    }

    public double Distance(Pos b) {
        double result = (this.y - b.y) * (this.y - b.y) + (this.x - b.x) * (this.x - b.x);
        return Math.sqrt(result);
    }
}

class Distance {
    int idx1, idx2;
    double distance;

    public Distance(int idx1, int idx2, double distance) {
        this.idx1 = idx1;
        this.idx2 = idx2;
        this.distance = distance;
    }
}