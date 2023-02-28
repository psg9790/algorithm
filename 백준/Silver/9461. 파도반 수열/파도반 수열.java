import java.io.*;
import java.util.*;

public class Main {
    static int t;
    static Long[] dp = new Long[101];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        Arrays.fill(dp, (long) 0);
        dp[1] = (long) 1;
        dp[2] = (long) 1;
        dp[3] = (long) 1;
        dp[4] = (long) 2;
        dp[5] = (long) 2;
        for (int i = 6; i <= 100; i++) {
            dp[i] = dp[i - 1] + dp[i - 5];
        }

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            bw.write(dp[Integer.parseInt(br.readLine())] + "\n");
        }
        bw.flush();
        bw.close();
    }
}
