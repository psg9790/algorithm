import java.io.*;
import java.util.*;

public class Main {
    static int n;
    static boolean[] prime = new boolean[4000001];


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        n = Integer.parseInt(br.readLine());

        Arrays.fill(prime, true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 2; i <= 2000; i++) {
            for (int j = 2; i * j <= 4000000; j++) {
                prime[i * j] = false;
            }
        }

        int lft = 0, rgt = 0;
        int window = 0;
        int result = 0;
        while (rgt <= n) {
            if (window < n) {
                rgt++;
                if (rgt > n) {
                    break;
                }
                if (prime[rgt]) {
                    window += rgt;
                    if (window == n) {
                        result++;
                    }
                }
            } else {
                if (prime[lft]) {
                    window -= lft;
                    if (window == n) {
                        result++;
                    }
                }
                lft++;
            }
        }
        System.out.println(result);
    }
}
