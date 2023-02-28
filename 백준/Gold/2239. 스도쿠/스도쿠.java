import java.io.*;
import java.util.*;


public class Main {
    static int[][] arr = new int[9][9];
    static boolean[][] rowban = new boolean[9][10];
    static boolean[][] colban = new boolean[9][10];
    static boolean[][] boxban = new boolean[9][10];
    static ArrayList<Pos> zeroPos = new ArrayList<>();
    static boolean success = false;

//    static void PrintArr() {
//        System.out.println("==============================");
//        for (int i = 0; i < 9; i++) {
//            for (int j = 0; j < 9; j++) {
//                System.out.print(arr[i][j]);
//            }
//            System.out.println();
//        }
//        System.out.println("==============================");
//    }

    static int calcBox(int y, int x) {
        return 3 * (y / 3) + x / 3;
    }

    static boolean possible(int a, int y, int x) {
        if (rowban[y][a]) {
            return false;
        }
        if (colban[x][a]) {
            return false;
        }
        if (boxban[calcBox(y, x)][a]) {
            return false;
        }
        return true;
    }

    static void ban(int a, int y, int x) {
        rowban[y][a] = true;
        colban[x][a] = true;
        boxban[calcBox(y, x)][a] = true;
        arr[y][x] = a;
    }

    static void unban(int a, int y, int x) {
        rowban[y][a] = false;
        colban[x][a] = false;
        boxban[calcBox(y, x)][a] = false;
        arr[y][x] = 0;
    }

    static void BackTracking(int idx) {
        if (idx >= zeroPos.size()) {
            // 성공
            success = true;
            return;
        }
        Pos _pos = zeroPos.get(idx);
        for (int k = 1; k <= 9; k++) {
            if (possible(k, _pos.y, _pos.x)) {
                ban(k, _pos.y, _pos.x);
//                System.out.println("pos: " + _pos.y + " " + _pos.x + " " + arr[_pos.y][_pos.x]);
                BackTracking(idx + 1);
                if (success) {
                    return;
                }
                unban(k, _pos.y, _pos.x);
            }
        }
    }


    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 10; j++) {
                rowban[i][j] = false;
                colban[i][j] = false;
                boxban[i][j] = false;
            }
        }
        for (int i = 0; i < 9; i++) {
            String line = br.readLine();
            for (int j = 0; j < 9; j++) {
                arr[i][j] = line.charAt(j) - '0';
                if (arr[i][j] > 0) {
                    rowban[i][arr[i][j]] = true;
                    colban[j][arr[i][j]] = true;
                    boxban[calcBox(i, j)][arr[i][j]] = true;
                } else {
                    zeroPos.add(new Pos(i, j));
                }
            }
        }
        BackTracking(0);

        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                bw.write(String.valueOf(arr[i][j]));
            }
            bw.write("\n");
        }
        bw.flush();
        bw.close();

    }
}

class Pos {
    int y, x;

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}