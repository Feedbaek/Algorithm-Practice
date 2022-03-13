import java.io.*;

public class Main {
	static BufferedWriter bw;
	static void is_end(int[][] map) throws IOException{	// 스도쿠가 완성되면 출력 후 종료
		for (int i=0; i<9; i++)
			for (int j=0; j<9; j++)
			if (map[i][j] == 0)
					return ;
		for (int i=0; i<9; i++) {
			for (int j=0; j<9; j++)
			bw.write(String.valueOf(map[i][j])+" ");
			bw.newLine();
		}
		bw.close();
		System.exit(0);
	}
	static int[] find_next_zero(int[][] map, int row, int column) {	// 다음 0 위치 찾기
		for (int i=row; i<9; i++)		// 입력받은 위치부터 찾기
			for (int j=column; j<9; j++)
				if (map[i][j] == 0)
					return (new int[] {i, j});
		for (int i=0; i<9; i++)			// 처음부터 한번 더 찾기
			for (int j=0; j<9; j++)
				if (map[i][j] == 0)
					return (new int[] {i, j});
		return (new int[] {0, 0});		// 사실상 실행될 일 없음
	}
	static boolean check_num(int[][] map, int row, int column, int num) {
		for (int i=(row/3)*3; i<(row/3+1)*3; i++)	// 사각형 검사
			for (int j=(column/3)*3; j<(column/3+1)*3; j++)
				if (map[i][j] == num)
					return false;
		for (int i=0; i<9; i++) {		// 가로 세로 검사
			if (map[i][column] == num)
				return false;
			if (map[row][i] == num)
				return false;
		}
		return true;
	}
	static void sudoku(int[][] map, int row, int column) throws IOException {
		int[] loc;
		for (int i=1; i<=9; i++) {
			if (check_num(map, row, column, i)) {
				map[row][column] = i;
				is_end(map);
				loc = find_next_zero(map, row, column+1);
				sudoku(map, loc[0], loc[1]);
				map[row][column] = 0;
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int[][] map = new int[9][9];
		int[] loc = new int[2];
		for (int i=0; i<9; i++) {
			String[] split = br.readLine().split(" ");
			for (int j=0; j<9; j++)
				map[i][j] = Integer.parseInt(split[j]);
		}
		is_end(map);
		loc = find_next_zero(map, 0, 0);
		sudoku(map, loc[0], loc[1]);
	}
}
