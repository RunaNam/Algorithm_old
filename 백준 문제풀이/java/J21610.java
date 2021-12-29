import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.StringTokenizer;

public class J21610 {

    public static class Pair {

        int x;
        int y;

        Pair(int x, int y) {
            this.x = x;
            this.y = y;

        }
    }

    static int n, m;
    static ArrayList<Pair> clouds = new ArrayList<>();
    static boolean[][] checked;
    static int[][] sky;

    static int[] dx = { 0, -1, -1, -1, 0, 1, 1, 1 };
    static int[] dy = { -1, -1, 0, 1, 1, 1, 0, -1 };

    static int[] ddx = { 1, 1, -1, -1 };
    static int[] ddy = { 1, -1, 1, -1 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());
        m = Integer.parseInt(st.nextToken());
        sky = new int[n + 1][n + 1];

        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 1; j <= n; j++) {
                sky[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        clouds.add(new Pair(n, 1));
        clouds.add(new Pair(n, 2));
        clouds.add(new Pair(n - 1, 1));
        clouds.add(new Pair(n - 1, 2));

        for (int i = 0; i < m; i++) {
            checked = new boolean[n + 1][n + 1];
            st = new StringTokenizer(br.readLine());
            int d = Integer.parseInt(st.nextToken()); // 방향
            int s = Integer.parseInt(st.nextToken()); // 거리

            moveCloud(d - 1, s % n);
            copyWater();
        }

        System.out.println(getSum());

    }

    private static void moveCloud(int d, int s) {
        for (Pair cloud : clouds) {
            int x = cloud.x + dx[d] * s;
            int y = cloud.y + dy[d] * s;

            if (x < 1) {
                x += n;
            } else if (x > n) {
                x -= n;
            }

            if (y < 1) {
                y += n;
            } else if (y > n) {
                y -= n;
            }

            cloud.x = x;
            cloud.y = y;

            sky[x][y]++;
            checked[x][y] = true;
        }
        checkWater();

        clouds.clear();
    }

    private static void checkWater() {
        for (Pair cloud : clouds) {
            int x = cloud.x;
            int y = cloud.y;

            for (int i = 0; i < 4; i++) {
                int nx = x + ddx[i];
                int ny = y + ddy[i];

                if (0 < nx && nx <= n && 0 < ny && ny <= n) {
                    if (sky[nx][ny] > 0) {
                        sky[x][y]++;
                    }
                }
            }
        }
    }

    private static void copyWater() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (sky[i][j] >= 2 && !checked[i][j]) {
                    clouds.add(new Pair(i, j));
                    sky[i][j] -= 2;
                }
            }
        }
    }

    private static int getSum() {
        int result = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                result += sky[i][j];
            }
        }
        return result;
    }
}