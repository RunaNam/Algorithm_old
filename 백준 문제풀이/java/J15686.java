import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class J15686 {
	public static class Pair {
		int x;
		int y;

		Pair(int x, int y) {
			this.x = x;
			this.y = y;

		}
	}

	static int n;
	static int m;
	static int[][] map;
	static List<Pair> houses = new ArrayList<>();
	static List<Pair> chickens = new ArrayList<>();
	static boolean[] visited;
	static int chickenDistance;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		chickenDistance = 500000;

		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		map = new int[n][n];

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				map[i][j] = Integer.parseInt(st.nextToken());
				if (map[i][j] == 1) {
					houses.add(new Pair(j, i));
				} else if (map[i][j] == 2) {
					chickens.add(new Pair(j, i));
				}
			}
		}
		visited = new boolean[chickens.size()];
		checkChickenDistance(-1, 0);
		System.out.println(chickenDistance);
	}

	private static void checkChickenDistance(int idx, int cnt) {
		if (cnt == m) {
			int dist = 0;

			for (Pair house : houses) {
				int tmpChickenDist = Integer.MAX_VALUE;
				for (int i = 0; i < chickens.size(); i++) {
					if (visited[i]) {
						tmpChickenDist = Math.min(tmpChickenDist,
								Math.abs(house.x - chickens.get(i).x) + Math.abs(house.y - chickens.get(i).y));
					}
				}
				dist += tmpChickenDist;
			}
			chickenDistance = Math.min(chickenDistance, dist);
			return;
		}

		for (int i = idx + 1; i < chickens.size(); i++) {
			visited[i] = true;
			checkChickenDistance(i, cnt + 1);
			visited[i] = false;
		}
	}

}
