import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class J14889 {
	static int[][] map;
	static boolean[] check;
	static int n;
	static int result = Integer.MAX_VALUE;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		map = new int[n][n];
		check = new boolean[n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
			}
		}


		divideTeam(-1, 0);
		System.out.println(result);

	}

	private static void divideTeam(int idx, int cnt) {
		if (cnt == n / 2) {
			int diff = 0;
			int sumTeam1 = 0;
			int sumTeam2 = 0;

			List<Integer> team1 = new ArrayList<>();
			List<Integer> team2 = new ArrayList<>();

			for (int i = 0; i < n; i++) {
				if (check[i]) {
					team1.add(i);
				} else {
					team2.add(i);
				}
			}

			for (int i = 0; i < n / 2; i++) {
				for (int j = 0; j < n / 2; j++) {
					sumTeam1 += map[team1.get(i)][team1.get(j)];
					sumTeam2 += map[team2.get(i)][team2.get(j)];
				}
			}

			diff = Math.abs(sumTeam1 - sumTeam2);

			result = Math.min(diff, result);
		}
		for (int i = idx + 1; i < n; i++) {
			check[i] = true;
			divideTeam(i, cnt + 1);
			check[i] = false;
		}
	}

}
