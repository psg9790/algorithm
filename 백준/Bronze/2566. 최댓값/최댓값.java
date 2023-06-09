//package baekjoon.b2566;

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
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
        bw.append(String.valueOf(mxv));
        bw.append("\n");
        bw.append(String.valueOf(pos[0]));
        bw.append(" ");
        bw.append(String.valueOf(pos[1]));
        bw.flush();
        bw.close();
    }
}
