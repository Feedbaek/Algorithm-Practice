package 단어_변환;

class Solution {
	private boolean isPossible(String st, String en) {
		int cnt = 0;
		for (int i=0; i<st.length(); ++i) {
			if (st.charAt(i) != en.charAt(i)) {
				++cnt;
			}
		}
		if (cnt == 1) {
			return true;
		}
		return false;
	}

	private int dfs(boolean[][] possible, boolean[] visited, String[] words, String target, int curIdx, int step) {
		int minRet = 0;
		if (words[curIdx].equals(target)) {
			return step;
		}
		visited[curIdx] = true;
		for (int i=0; i<words.length; ++i) {
			if (possible[curIdx][i] && !visited[i]) {
				int ret = dfs(possible, visited, words, target, i, step + 1);
				if (ret != 0 && (minRet == 0 || ret < minRet)) {
					minRet = ret;
				}
			}
		}
		visited[curIdx] = false;
		return minRet;
	}

	public int solution(String begin, String target, String[] words) {
		int answer = 0;
		// 변환 가능한 단어 쌍을 체크하는 배열
		boolean[][] possible = new boolean[words.length][words.length];
		// 변환 여부 체크 배열
		boolean[] visited = new boolean[words.length];
		// 변환이 가능한지 체크
		for (int i=0; i<words.length; ++i) {
			for (int j=0; j<words.length; ++j) {
				if (isPossible(words[i], words[j])) {
					possible[i][j] = true;
				}
			}
		}
		// 변환 가능한지 탐색 시작
		for (int i=0; i<words.length; ++i) {
			if (isPossible(begin, words[i])) {
				int ret = dfs(possible, visited, words, target, i, 1);
				if (ret != 0 && (answer == 0 || ret < answer)) {
					answer = ret;
				}
			}
		}
		return answer;
	}
}
