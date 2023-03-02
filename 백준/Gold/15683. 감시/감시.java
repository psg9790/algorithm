import java.io.*;
import java.util.*;

public class Main {
    static final int[] dy = new int[]{-1, 1, 0, 0};
    static final int[] dx = new int[]{0, 0, -1, 1};
    static int n, m;
    static int[][] arr;
    static ArrayList<Camera> cams = new ArrayList<>();
    static int minisize = Integer.MAX_VALUE;

    static void PrintArr() {
        System.out.println("=================");
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                System.out.print(arr[i][j]);
            }
            System.out.println();
        }
        System.out.println("=================");
    }

    static ArrayList<Pos> CalcDirSight(int y, int x, int dir) {
        ArrayList<Pos> result = new ArrayList<>();
        int yy = y + dy[dir];
        int xx = x + dx[dir];
        while (yy >= 1 && yy <= n && xx >= 1 && xx <= m) {
            if (arr[yy][xx] == 0) {
                result.add(new Pos(yy, xx));
            } else if (arr[yy][xx] == 6) {
                break;
            }
            yy = yy + dy[dir];
            xx = xx + dx[dir];
        }
        return result;
    }

    static ArrayList<Pos> CalcSight(int cameraIdx, int dir) {
        ArrayList<Pos> result = new ArrayList<>();
        Camera cam = cams.get(cameraIdx);
        result.addAll(CalcDirSight(cam.y, cam.x, dir));
        switch (cams.get(cameraIdx).num) {
            case 1:
                break;
            case 2:
                if (dir == 0) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 1));
                } else if (dir == 1) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 0));
                } else if (dir == 2) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 3));
                } else if (dir == 3) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 2));
                }
                break;
            case 3:
                if (dir == 0) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 3));
                } else if (dir == 1) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 2));
                } else if (dir == 2) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 0));
                } else if (dir == 3) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 1));
                }
                break;
            case 4:
                if (dir == 0) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 2));
                    result.addAll(CalcDirSight(cam.y, cam.x, 3));
                } else if (dir == 1) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 2));
                    result.addAll(CalcDirSight(cam.y, cam.x, 3));
                } else if (dir == 2) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 0));
                    result.addAll(CalcDirSight(cam.y, cam.x, 1));
                } else if (dir == 3) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 0));
                    result.addAll(CalcDirSight(cam.y, cam.x, 1));
                }
                break;
            case 5:
                if (dir == 0) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 1));
                    result.addAll(CalcDirSight(cam.y, cam.x, 2));
                    result.addAll(CalcDirSight(cam.y, cam.x, 3));
                } else if (dir == 1) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 0));
                    result.addAll(CalcDirSight(cam.y, cam.x, 2));
                    result.addAll(CalcDirSight(cam.y, cam.x, 3));
                } else if (dir == 2) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 0));
                    result.addAll(CalcDirSight(cam.y, cam.x, 1));
                    result.addAll(CalcDirSight(cam.y, cam.x, 3));
                } else if (dir == 3) {
                    result.addAll(CalcDirSight(cam.y, cam.x, 0));
                    result.addAll(CalcDirSight(cam.y, cam.x, 1));
                    result.addAll(CalcDirSight(cam.y, cam.x, 2));
                }
                break;
        }
        return result;
    }

    static void BackTracking(int idx) {
        if (idx >= cams.size()) {
            // 빈칸 계산
            int result = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (arr[i][j] == 0) {
                        result++;
                    }
                }
            }
            minisize = Math.min(result, minisize);
            return;
        }

        // 방향 전환
        for (int i = 0; i < 4; i++) {
            // -1 배치
            ArrayList<Pos> curSight = CalcSight(idx, i);
            for (Pos yx : curSight) {
                arr[yx.y][yx.x] = -1;
            }
//            PrintArr();
            BackTracking(idx + 1);
            // -1 철회
            for (Pos yx : curSight) {
                arr[yx.y][yx.x] = 0;
            }
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        arr = new int[n + 1][m + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= m; j++) {
                arr[i][j] = Integer.parseInt(st.nextToken());
                if (arr[i][j] > 0 &&
                        arr[i][j] < 6) {
                    cams.add(new Camera(i, j, arr[i][j]));
                }
            }
        }
        BackTracking(0);
        System.out.println(minisize);

    }
}

class Camera {
    int y, x;
    int num;

    public Camera(int y, int x, int num) {
        this.y = y;
        this.x = x;
        this.num = num;
    }
}

class Pos {
    int y, x;

    public Pos(int y, int x) {
        this.y = y;
        this.x = x;
    }
}