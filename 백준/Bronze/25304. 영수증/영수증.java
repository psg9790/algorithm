//package baekjoon.b25304;

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        StringTokenizer st = new StringTokenizer(br.readLine());
        int ans = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int cnt = Integer.parseInt(st.nextToken());
        int sum= 0;
        for (int i =0 ; i< cnt; i++){
            st = new StringTokenizer(br.readLine());
            int price = Integer.parseInt(st.nextToken());
            int amount = Integer.parseInt(st.nextToken());
            sum += price * amount;
        }
        if(sum == ans){
            bw.append("Yes");
        }else{
            bw.append("No");
        }
        bw.flush();
        bw.close();
    }
}
