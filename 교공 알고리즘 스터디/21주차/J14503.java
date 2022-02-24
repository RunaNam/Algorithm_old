import java.io.*;
import java.util.*;

public class J14503 {
    private static class Cleaner {
        int x, y, dir;

        public Cleaner(int x, int y, int dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }
    }

    static int[][] map;
    static boolean[][] dirty; // 청소 필요한 것만 true로 두기.

    static int N, M;
    static Cleaner cleaner;
    static int cleanNumber = 0; // 청소한 횟수

    static int[] dx = { -1, 0, 1, 0 }; // 북동남서
    static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        map = new int[N][M];
        dirty = new boolean[N][M];

        st = new StringTokenizer(br.readLine());
        int x = Integer.parseInt(st.nextToken());
        int y = Integer.parseInt(st.nextToken());
        int dir = Integer.parseInt(st.nextToken());
        cleaner = new Cleaner(x, y, dir);

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());

            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());

                if (map[i][j] == 0) {
                    dirty[i][j] = true;
                }
            }
        }

        move();
        System.out.println(cleanNumber);
    }

    private static void move() {
        while (true) {
            int xpos = cleaner.x;
            int ypos = cleaner.y;
            int dir = cleaner.dir;

            // 현재 위치 청소.
            if (dirty[xpos][ypos]) {
                cleanNumber++;
                dirty[xpos][ypos] = false;
            }

            // 먼저 모두 청소되었는지 확인
            if (allClean(xpos, ypos)) {
                if (canGoBack(xpos, ypos, dir)) {
                    // 모두 청소되어있고 + 뒤로 갈 수 있음
                    int back = (dir + 2) % 4;
                    cleaner.x = xpos + dx[back];
                    cleaner.y = ypos + dy[back];

                } else {
                    // 모두 청소되어있고 + 뒤로 갈 수 없음 = 종료
                    return;
                }
            } else {
                int left = (dir + 3) % 4;
                if (canGoLeft(xpos, ypos, dir)) {
                    // 왼쪽 공간 O
                    cleaner.x = xpos + dx[left];
                    cleaner.y = ypos + dy[left];

                    cleaner.dir = left;
                } else {
                    // 왼쪽 공간 X
                    cleaner.dir = left;
                }
            }

        }
    }

    public static boolean allClean(int xpos, int ypos) {
        for (int i = 0; i < 4; i++) {
            int nx = xpos + dx[i];
            int ny = ypos + dy[i];
            if (dirty[nx][ny]) {
                return false;
            }
        }
        return true;
    }

    public static boolean canGoBack(int xpos, int ypos, int dir) {
        int back = (dir + 2) % 4;
        int nx = xpos + dx[back];
        int ny = ypos + dy[back];

        return (map[nx][ny] != 1);
    }

    public static boolean canGoLeft(int xpos, int ypos, int dir) {
        int left = (dir + 3) % 4;
        int nx = xpos + dx[left];
        int ny = ypos + dy[left];
        return (dirty[nx][ny]);
    }

}