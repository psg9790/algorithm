import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    static int[] inDegree;

    static ArrayList<Integer> topology() {
        ArrayList<Integer> result = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();

        // inDegree 0인 요소 큐에 추가
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                q.add(i);
            }
        }
        // 분기 커트, n번 반복하기 전에 큐가 비면 사이클이 있어 위상정렬 불가
        for (int i = 1; i <= n; i++) {
            if (q.isEmpty()) {
            }
            int frt = q.poll();
            for (int j = 0; j < adj.get(frt).size(); j++) {
                if (--inDegree[adj.get(frt).get(j)] == 0) {
                    q.add(adj.get(frt).get(j));
                }
            }
            result.add(frt);
        }

        return result;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        inDegree = new int[n + 1];
        Arrays.fill(inDegree, 0);
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken());
            b = Integer.parseInt(st.nextToken());
            adj.get(a).add(b);
            inDegree[b]++;
        }

        ArrayList<Integer> topology = topology();
        StringBuilder sb = new StringBuilder();
        for (Integer x : topology) {
            sb.append(x + " ");
        }
        System.out.println(sb.toString());
    }
}
