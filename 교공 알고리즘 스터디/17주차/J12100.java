import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.PrimitiveIterator;
import java.util.StringTokenizer;

public class J12100 {
	static int n;
	static int[][] board;
	static int answer;

	static final int UP = 0;
	static final int DOWN = 1;
	static final int LEFT = 2;
	static final int RIGHT = 3;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		n = Integer.parseInt(st.nextToken());
		board = new int[n][n];
		answer = 0;

		for (int i = 0; i < n; i++) {
			st = new StringTokenizer(br.readLine());
			for (int j = 0; j < n; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		runGame(0);
		System.out.println(answer);
	}

	private static void runGame(int count) {
		if (count == 5) {
			biggestValue();
			return;
		}

		int copy[][] = new int[n][n];
		for(int i = 0; i < n; i++)
			copy[i] = board[i].clone();

		for (int i = 0; i < 4; i++) {
			moveBoard(i);
			runGame(count + 1);
			for (int j = 0; j < n; j++) {
				board[j] = copy[j].clone();
			}
		}

	}

	private static void moveBoard(int dir) {
		int index;
		int pastNumber;

		switch (dir) {
			case UP:
				for (int i = 0; i < n; i++) {
					index = 0;
					pastNumber = 0;
					for (int j = 0; j < n; j++) {
						if (board[j][i] != 0) {
							if (pastNumber == board[j][i]) {
								board[index - 1][i] = pastNumber * 2;
								pastNumber = 0;
								board[j][i] = 0;
							} else {
								pastNumber = board[j][i];
								board[j][i] = 0;
								board[index][i] = pastNumber;
								index++;
							}
						}
					}
				}
				break;

			case DOWN:
				for (int i = 0; i < n; i++) {
					index = n - 1;
					pastNumber = 0;
					for (int j = n - 1; j > -1; j--) {
						if (board[j][i] != 0) {
							if (pastNumber == board[j][i]) {
								board[index + 1][i] = pastNumber * 2;
								pastNumber = 0;
								board[j][i] = 0;
							} else {
								pastNumber = board[j][i];
								board[j][i] = 0;
								board[index][i] = pastNumber;
								index--;
							}
						}
					}
				}
				break;

			case LEFT:
				for (int i = 0; i < n; i++) {
					index = 0;
					pastNumber = 0;
					for (int j = 0; j < n; j++) {
						if (board[i][j] != 0) {
							if (pastNumber == board[i][j]) {
								board[i][index - 1] = pastNumber * 2;
								pastNumber = 0;
								board[i][j] = 0;
							} else {
								pastNumber = board[i][j];
								board[i][j] = 0;
								board[i][index] = pastNumber;
								index++;
							}
						}
					}
				}
				break;

			case RIGHT:
				for (int i = 0; i < n; i++) {
					index = n - 1;
					pastNumber = 0;
					for (int j = n - 1; j > -1; j--) {
						if (board[i][j] != 0) {
							if (pastNumber == board[i][j]) {
								board[i][index + 1] = pastNumber * 2;
								pastNumber = 0;
								board[i][j] = 0;
							} else {
								pastNumber = board[i][j];
								board[i][j] = 0;
								board[i][index] = pastNumber;
								index--;
							}
						}
					}
				}
				break;
		}

	}

	private static void biggestValue() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] > answer)
					answer = board[i][j];
			}
		}
	}

	private static void Print(int[][] board) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(board[i][j]);
			}
			System.out.println();
		}
		System.out.println();

	}
}
