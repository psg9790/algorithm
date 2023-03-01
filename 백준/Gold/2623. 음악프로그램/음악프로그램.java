import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    static int[] inDegree;

    static ArrayList<Integer> topology() {
        ArrayList<Integer> result = new ArrayList<>();
        Queue<Integer> q = new LinkedList<>();

        // inDegree == 0 in q
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                q.add(i);
            }
        }

        // if not repeat n times, there is cycle.
        for (int i = 1; i <= n; i++) {
            if (q.isEmpty()) {
                result.clear();
                return result;
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
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        inDegree = new int[n + 1];
        Arrays.fill(inDegree, 0);

        for (int i = 0; i < m; i++) {
            st = new StringTokenizer(br.readLine());
            int size = Integer.parseInt(st.nextToken());
            ArrayList<Integer> line = new ArrayList<>();
            for (int j = 0; j < size; j++) {
                line.add(Integer.parseInt(st.nextToken()));
                if (j >= 1) {
                    adj.get(line.get(j - 1)).add(line.get(j));
                    inDegree[line.get(j)]++;
                }
            }
        }

        ArrayList<Integer> topology = topology();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        if (topology.isEmpty()) {
            bw.write(0 + "\n");
            bw.flush();
            bw.close();
            return;
        }

        for (Integer x : topology) {
            bw.write(x + "\n");
        }
        bw.flush();
        bw.close();
    }
}
