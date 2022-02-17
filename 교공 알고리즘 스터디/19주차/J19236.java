import java.io.*;
import java.util.*;

public class J19236 {

    public static class Fish {
        int x;
        int y;
        int dir;
        boolean alive = true;

        public Fish(int x, int y, int dir) {
            this.x = x;
            this.y = y;
            this.dir = dir;
        }
    }

    public static int[] dx = { -1, -1, 0, 1, 1, 1, 0, -1 }; // 상, 상좌, 좌, 좌하, 하, 하우, 우, 상우 순서
    public static int[] dy = { 0, -1, -1, -1, 0, 1, 1, 1 };
    static int answer = 0;

    public static void main(String[] args) throws IOException {
        Fish[] fishes = new Fish[17]; // 물고기
        int[][] map = new int[4][4]; // 전체 어항

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        for (int i = 0; i < 4; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < 4; j++) {
                int number = Integer.parseInt(st.nextToken());
                int dir = Integer.parseInt(st.nextToken()) - 1;
                fishes[number] = new Fish(i, j, dir);
                map[i][j] = number;
            }
        }
        move(map, fishes, 0, 0, 0);
        System.out.println(answer);
    }

    public static void move(int[][] map, Fish[] fishes, int sx, int sy, int sum) {
        int[][] copyMap = new int[4][4];
        Fish[] copyFishes = new Fish[17];

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                copyMap[i][j] = map[i][j];
            }
        }
        for (int i = 1; i < 17; i++) {
            copyFishes[i] = new Fish(fishes[i].x, fishes[i].y, fishes[i].dir);
        }

        // 상어가 먹음 + 물고기 죽음
        int eatNumber = copyMap[sx][sy];
        int sDir = copyFishes[eatNumber].dir;
        copyMap[sx][sy] = -1;
        copyFishes[eatNumber].alive = false;

        // 먹은 물고기 계산
        sum += eatNumber;
        answer = Math.max(answer, sum);

        // 물고기 이동
        for (int i = 1; i < 17; i++) {
            if (copyFishes[i].alive) {
                int x = copyFishes[i].x;
                int y = copyFishes[i].y;
                int dir = copyFishes[i].dir;

                int nx = x + dx[dir % 8];
                int ny = y + dy[dir % 8];

                // 범위 확인
                while (nx < 0 || nx > 3 || ny < 0 || ny > 3 || (sx == nx && sy == ny)) {
                    dir++;
                    nx = x + dx[dir % 8];
                    ny = y + dy[dir % 8];
                }

                // 물고기 swap
                if (copyMap[nx][ny] != -1) { // 살아있는 물고기 대상
                    int swapFish = copyMap[nx][ny];
                    copyFishes[i].x = nx;
                    copyFishes[i].y = ny;
                    copyFishes[i].dir = dir;

                    copyFishes[swapFish].x = x;
                    copyFishes[swapFish].y = y;

                    copyMap[x][y] = swapFish;
                    copyMap[nx][ny] = i;
                } else { // 죽은 물고기 대상
                    copyFishes[i].x = nx;
                    copyFishes[i].y = ny;
                    copyFishes[i].dir = dir;

                    copyMap[x][y] = -1;
                    copyMap[nx][ny] = i;
                }
            }
        }

        // 상어이동, 최대 3칸 앞으로.
        for (int i = 1; i < 4; i++) {
            int nx = sx + dx[sDir % 8] * i;
            int ny = sy + dy[sDir % 8] * i;

            if (nx < 0 || nx > 3 || ny < 0 || ny > 3) {
                break;
            }

            if (copyMap[nx][ny] != -1) {
                move(copyMap, copyFishes, nx, ny, sum);
            }
        }

    }
}
