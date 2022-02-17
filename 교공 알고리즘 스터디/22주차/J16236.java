import java.io.*;
import java.util.*;

public class J16236 {
    private static class Iceberg {
        int x, y;

        public Iceberg(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    static int[][] map;

    static int N, M;

    static int[] dx = { -1, 0, 1, 0 }; // 북동남서
    static int[] dy = { 0, 1, 0, -1 };

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        N = Integer.parseInt(st.nextToken());
        M = Integer.parseInt(st.nextToken());

        int ans = 0;
        int cnt = 0;

        map = new int[N][M];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < M; j++) {
                map[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        while ((cnt = isSeperate()) < 2) {
            if (cnt == 0) {
                ans = 0;
                break;
            }
            melt();
            ans++;
        }

        melt();
        System.out.println(ans);
    }

    private static int isSeperate() {
        boolean[][] visited = new boolean[N][M];

        int cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] != 0 && !visited[i][j]) {
                    DFS(i, j, visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }

    private static void DFS(int x, int y, boolean[][] visited) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                continue;
            }

            if (map[nx][ny] != 0 && !visited[nx][ny]) {
                DFS(nx, ny, visited);
            }
        }
    }

    private static void melt() {
        Queue<Iceberg> icebergs = new LinkedList<>();
        boolean[][] ice = new boolean[N][M]; // 얼음이 녹은 자리를 바로 확인하지 않기 위해서.

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (map[i][j] != 0) {
                    icebergs.add(new Iceberg(i, j));
                    ice[i][j] = true;
                }
            }
        }

        while (!icebergs.isEmpty()) {
            Iceberg iceberg = icebergs.poll();
            for (int i = 0; i < 4; i++) {
                int nx = iceberg.x + dx[i];
                int ny = iceberg.y + dy[i];
                if (nx < 0 || nx >= N || ny < 0 || ny >= M) {
                    continue;
                }
                if (!ice[nx][ny] && map[nx][ny] == 0 && map[iceberg.x][iceberg.y] > 0) {
                    map[iceberg.x][iceberg.y]--;
                }
            }
        }

    }

}