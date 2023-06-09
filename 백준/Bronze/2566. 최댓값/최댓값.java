//package baekjoon.b2566;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int mxv = -1;
        int[] pos = new int[2];
        for(int i = 1; i<=9; i++){
            st = new StringTokenizer(br.readLine());
            for(int j =1; j<= 9; j++){
                int token = Integer.parseInt(st.nextToken());
                if(token > mxv){
                    mxv = token;
                    pos[0] = i;
                    pos[1] = j;
                }
            }
        }
        System.out.println(mxv);
        System.out.println(pos[0] + " " + pos[1]);
    }
}
