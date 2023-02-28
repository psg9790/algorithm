import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
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

    static boolean isUnion(int a, int b) {
        return u[find(a)] == u[find(b)];
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        u = new int[n];
        for (int i = 0; i < n; i++) {
            u[i] = i;
        }

        ArrayList<Integer> as = new ArrayList<>();
        ArrayList<Integer> bs = new ArrayList<>();

        for (int i = 1; i <= m; i++) {
            st = new StringTokenizer(br.readLine());
            as.add(Integer.parseInt(st.nextToken()));
            bs.add(Integer.parseInt(st.nextToken()));
        }
        for (int i = 1; i <= m; i++) {
            if (isUnion(as.get(i - 1), bs.get(i - 1))) {
                System.out.println(i);
                return;
            } else {
                union(as.get(i - 1), bs.get(i - 1));
            }
        }

        System.out.println(0);
    }
}
