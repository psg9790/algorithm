import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static int[] dp = new int[1000001];
    static int[] p = new int[1000001];


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        Arrays.fill(dp, Integer.MAX_VALUE);
        Arrays.fill(p, 0);
        dp[1] = 0;
        for (int i = 1; i < n; i++) {
            if (i * 3 <= n && dp[i * 3] > dp[i] + 1) {
                dp[i * 3] = dp[i] + 1;
                p[i * 3] = i;
            }
            if (i * 2 <= n && dp[i * 2] > dp[i] + 1) {
                dp[i * 2] = dp[i] + 1;
                p[i * 2] = i;
            }
            if (i + 1 <= n && dp[i + 1] > dp[i] + 1) {
                dp[i + 1] = dp[i] + 1;
                p[i + 1] = i;
            }
        }
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        bw.write(String.valueOf(dp[n]) + "\n");
        int ptr = n;
        while (ptr >= 1) {
            bw.write(String.valueOf(ptr) + " ");
            ptr = p[ptr];
        }
        bw.flush();
        bw.close();
    }
}
