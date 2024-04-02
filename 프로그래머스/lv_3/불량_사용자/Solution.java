import java.util.HashSet;
import java.util.Set;

public class Solution {
	boolean[] visited = new boolean[8];
	Set<Integer> set = new HashSet<>();
	int key = 0;

	boolean matchString(String user, String ban) {
		if (user.length() != ban.length()) {
			return false;
		}
		for (int i=0; i<user.length(); ++i) {
			if (user.charAt(i) != ban.charAt(i) && ban.charAt(i) != '*') {
				return false;
			}
		}
		return true;
	}

	int dfs(int banIdx, String[] user_id, String[] banned_id) {
		int answer = 0;
		if (banIdx == banned_id.length) {
			if (!set.contains(key)) {
				set.add(key);
				++answer;
			}
			return answer;
		}
		for (int i=0; i<user_id.length; ++i) {
			if (!visited[i] && matchString(user_id[i], banned_id[banIdx])) {
				visited[i] = true;
				key += 1 << i+1;
				answer += dfs(banIdx + 1, user_id, banned_id);
				key -= 1 << i+1;
				visited[i] = false;
			}
		}
		return answer;
	}

	public int solution(String[] user_id, String[] banned_id) {
		return dfs(0, user_id, banned_id);
	}
}
