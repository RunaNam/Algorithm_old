import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class J13458 {
    static int n, b, c;
    static long result = 0;
    static List<Integer> a = new ArrayList<>();

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        for (int i = 0; i < n; i++) {
            int tmp = Integer.parseInt(st.nextToken());
            a.add(tmp);
        }
        st = new StringTokenizer(br.readLine());

        b = Integer.parseInt(st.nextToken());
        c = Integer.parseInt(st.nextToken());

        for (int i = 0; i < n; i++) {
            int tmp = a.get(i) - b;
            result += 1; // 총감독관

            if (tmp > 0) {
                if ((a.get(i) - b) % c != 0) {
                    result += 1 + (a.get(i) - b) / c; // 총감독관 + 모자라는 인원용 1명 추가
                } else {
                    result += (a.get(i) - b) / c;
                }
            }
        }
        System.out.println(result);
    }
}