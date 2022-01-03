import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class J14891 {
    static int[][] gears = new int[4][8];
    static int[] gearStartPosition = { 0, 0, 0, 0 };

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int result = 0;
        int k;

        for (int i = 0; i < 4; i++) {
            String tmp = st.nextToken();
            for (int j = 0; j < 8; j++) {
                gears[i][j] = Character.getNumericValue(tmp.charAt(j));
            }
            st = new StringTokenizer(br.readLine());
        }

        k = Integer.parseInt(st.nextToken());

        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());

            int gearNumber = Integer.parseInt(st.nextToken()) - 1;
            int dir = -1 * Integer.parseInt(st.nextToken());
            int startPositionNow = moveStartPosition(gearNumber, dir);

            checkLeft(-dir, gears[gearNumber][moveStartPosition(gearNumber, -2)], gearNumber - 1);
            checkRight(-dir, gears[gearNumber][moveStartPosition(gearNumber, +2)], gearNumber + 1);
            gearStartPosition[gearNumber] = startPositionNow;

        }

        for (int i = 0; i < 4; i++) {
            result += gears[i][gearStartPosition[i]] * Math.pow(2, i);
        }

        System.out.println(result);

    }

    public static void checkLeft(int dir, int pastSN, int gearNumber) {
        if (gearNumber == -1) {
            return;
        }

        int adjPos = moveStartPosition(gearNumber, 2);
        if (pastSN == gears[gearNumber][adjPos]) {
            return;
        }

        checkLeft(-dir, gears[gearNumber][moveStartPosition(gearNumber, -2)], gearNumber - 1);
        gearStartPosition[gearNumber] = moveStartPosition(gearNumber, dir);

    }

    public static void checkRight(int dir, int pastSN, int gearNumber) {
        if (gearNumber == 4) {
            return;
        }

        int adjPos = moveStartPosition(gearNumber, -2);
        if (pastSN == gears[gearNumber][adjPos]) {
            return;
        }

        checkRight(-dir, gears[gearNumber][moveStartPosition(gearNumber, 2)], gearNumber + 1);
        gearStartPosition[gearNumber] = moveStartPosition(gearNumber, dir);

    }

    public static int moveStartPosition(int gearNumber, int move) {
        int pos = gearStartPosition[gearNumber] + move;
        if (pos > 7) {
            pos -= 8;
        } else if (pos < 0) {
            pos += 8;
        }
        return pos;
    }

}
