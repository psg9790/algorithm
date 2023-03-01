import java.io.*;
import java.util.*;

public class Main {
    static String a, b;
    static int[][] dp = new int[1001][1001];

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        a = br.readLine();
        b = br.readLine();
        for (int i = 0; i <= 1000; i++) {
            Arrays.fill(dp[i], 0);
        }

        for (int i = 1; i <= b.length(); i++) {
            for (int j = 1; j <= a.length(); j++) {
                dp[i][j] = Math.max(dp[i - 1][j], dp[i][j - 1]);
                if (b.charAt(i - 1) == a.charAt(j - 1)) {
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
//                System.out.print(dp[i][j]);
            }
//            System.out.println();
        }


        StringBuilder sb = new StringBuilder();
        int i = b.length();
        int j = a.length();
        while (i >= 1 && j >= 1) {
            if (dp[i][j] == dp[i - 1][j]) {
                i--;
            } else if (dp[i][j] == dp[i][j - 1]) {
                j--;
            } else {
                sb.insert(0, a.charAt(j - 1));
                i--;
                j--;
            }
        }
        System.out.println(dp[b.length()][a.length()]);
        System.out.println(sb.toString());
    }
}
