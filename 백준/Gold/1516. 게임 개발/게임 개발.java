import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] cost;
    static ArrayList<ArrayList<Integer>> adj = new ArrayList<>();
    static int[] inDegree;
    static int[] dp;

    static void topology() {
        dp = new int[n + 1];
        Arrays.fill(dp, 0);
        
        Queue<Integer> q = new LinkedList<>();
        for (int i = 1; i <= n; i++) {
            if (inDegree[i] == 0) {
                q.add(i);
                dp[i] = cost[i];
            }
        }

        for (int i = 1; i <= n; i++) {
            int frt = q.poll();
            for (int j = 0; j < adj.get(frt).size(); j++) {
                int ele = adj.get(frt).get(j);
                if (--inDegree[ele] == 0) {
                    q.add(ele);
                }
                dp[ele] = Math.max(dp[ele], dp[frt] + cost[ele]);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());
        cost = new int[n + 1];
        Arrays.fill(cost, 0);
        for (int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }
        inDegree = new int[n + 1];
        Arrays.fill(inDegree, 0);

        for (int i = 1; i <= n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            cost[i] = Integer.parseInt(st.nextToken());
            while (st.hasMoreTokens()) {
                int token = Integer.parseInt(st.nextToken());
                if (token == -1) {
                    break;
                }
                adj.get(token).add(i);
                inDegree[i]++;
            }
        }

        topology();
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 1; i <= n; i++) {
            bw.write(dp[i] + "\n");
        }
        bw.flush();
        bw.close();

    }
}
