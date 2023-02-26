import java.io.*;
import java.lang.reflect.Array;
import java.nio.Buffer;
import java.util.*;

class Shark {
    int y, x;
    int dir;
    int num;
    boolean dead = false;

    public Shark() {
    }

    public Shark(int y, int x, int dir, int num) {
        this.y = y;
        this.x = x;
        this.dir = dir;
        this.num = num;
    }
}

class Smell {
    int y, x;
    int k;
    int num;

    public Smell(Shark shark, int k) {
        this.y = shark.y;
        this.x = shark.x;
        this.k = k;
        this.num = shark.num;
    }

    public Smell(Smell smell) {
        this.y = smell.y;
        this.x = smell.x;
        this.k = smell.k;
        this.num = smell.num;
    }
}

public class Main {
    static final int[] dy = new int[]{-1, 1, 0, 0};
    static final int[] dx = new int[]{0, 0, -1, 1};
    static int n, m, k;
    static int[][][] adj;
    static Shark[] sharks;
    static ArrayList<Smell> smells = new ArrayList<>();

    static boolean deadExcept1() {
        for (int i = 2; i <= m; i++) {
            if (!sharks[i].dead) {
                return false;
            }
        }
        return true;
    }

    static boolean isBlank(int y, int x) {
        for (Smell smell : smells) {
            if (smell.y == y && smell.x == x) {
                return false;
            }
        }
        return true;
    }

    static boolean findMySmell(int y, int x, int num) {
        for (Smell smell : smells) {
            if (smell.y == y && smell.x == x) {
                if (smell.num == num) {
                    return true;
                }
            }
        }
        return false;
    }

    static void removeBoxSmell(int y, int x) {
        for (int i = 0; i < smells.size(); i++) {
            if (smells.get(i).y == y && smells.get(i).x == x) {
                smells.remove(i);
                --i;
            }
        }
    }

    static void Simulate() {
        // 이동
        // 새로운 냄새를 별도의 리스트에 일단 저장
        ArrayList<Smell> news = new ArrayList<>();
        for (int i = 1; i <= m; i++) {
            if (!sharks[i].dead) {
                boolean blankMove = false;
                for (int j = 0; j < 4; j++) {
                    int dirToken = adj[i][sharks[i].dir][j];
                    int yy = sharks[i].y + dy[dirToken];
                    int xx = sharks[i].x + dx[dirToken];
                    if (yy < 1 || yy > n || xx < 1 || xx > n) {
                        continue;
                    }
                    if (isBlank(yy, xx)) {
                        blankMove = true;
                        sharks[i].y = yy;
                        sharks[i].x = xx;
                        sharks[i].dir = dirToken;
                        news.add(new Smell(sharks[i], k));
                        break;
                    }
                }
                if (!blankMove) {
                    for (int j = 0; j < 4; j++) {
                        int dirToken = adj[i][sharks[i].dir][j];
                        int yy = sharks[i].y + dy[dirToken];
                        int xx = sharks[i].x + dx[dirToken];
                        if (yy < 1 || yy > n || xx < 1 || xx > n) {
                            continue;
                        }
                        if (findMySmell(yy, xx, i)) {
                            sharks[i].y = yy;
                            sharks[i].x = xx;
                            sharks[i].dir = dirToken;
                            news.add(new Smell(sharks[i], k));
                            break;
                        }
                    }
                }
            }
        }

        // 새로 이동한 상어 위치의 냄새를 모두 없앰
        for (int i = 1; i <= m; i++) {
            if (sharks[i].dead) {
                continue;
            }
            removeBoxSmell(sharks[i].y, sharks[i].x);
        }

        // 같은 위치에 자신보다 높은 번호의 상어가 있으면 죽음
        for (int i = 1; i <= m; i++) {
            if (sharks[i].dead) {
                continue;
            }
            for (int j = i + 1; j <= m; j++) {
                if (sharks[i].y == sharks[j].y && sharks[i].x == sharks[j].x) {
                    sharks[j].dead = true;
                }
            }
        }

        // 기존 냄새 카운트 다운
        for (int i = 0; i < smells.size(); i++) {
            if (--smells.get(i).k <= 0) {
                smells.remove(i);
                --i;
            }
        }

        // 새로운 냄새 추가
        for (Smell smell : news) {
            smells.add(new Smell(smell));
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        k = Integer.parseInt(st.nextToken());
        sharks = new Shark[m + 1];
        adj = new int[m + 1][4][4];

        for (int i = 0; i <= m; i++) {
            sharks[i] = new Shark();
        }

        // 보드 입력
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                int box = Integer.parseInt(st.nextToken());
                if (box > 0) {
                    sharks[box].y = i;
                    sharks[box].x = j;
                    sharks[box].num = box;
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            smells.add(new Smell(sharks[i], k));
        }
        // 방향 입력
        st = new StringTokenizer(br.readLine());
        for (int i = 1; i <= m; i++) {
            sharks[i].dir = Integer.parseInt(st.nextToken()) - 1;
        }
        // 우선순위 입력
        for (int i = 1; i <= m; i++) {
            for (int j = 0; j < 4; j++) {
                st = new StringTokenizer(br.readLine());
                for (int k = 0; k < 4; k++) {
                    adj[i][j][k] = Integer.parseInt(st.nextToken()) - 1;
                }
            }
        }
        // *** 입력 끝 ***

        int result = 0;
        while (!deadExcept1()) {
            Simulate();
            result++;
            if (result > 1000) {
                System.out.println(-1);
                return;
            }
        }
        System.out.println(result);
    }
}