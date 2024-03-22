import java.util.ArrayList;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.TreeMap;

public class Solution {
	public Integer[] solution(String[] genres, int[] plays) {
		List<Integer> answer = new ArrayList<>();
		HashMap<String, Integer> genrePlayCountMap = new HashMap<>();
		HashMap<String, TreeMap<Integer, List<Integer>>> genreMusics = new HashMap<>();
		TreeMap<Integer, String> genreRanking = new TreeMap<>((a, b) -> b - a);

		for (int i=0; i<genres.length; ++i) {
			String genre = genres[i];
			int play = plays[i];
			Integer value = genrePlayCountMap.get(genre);
			if (value == null) {
				genrePlayCountMap.put(genre, play);
				TreeMap<Integer, List<Integer>> playMusics = new TreeMap<>((a, b) -> b - a);
				playMusics.put(play, new ArrayList<>(List.of(i)));
				genreMusics.put(genre, playMusics);
			} else {
				genrePlayCountMap.put(genre, value + play);
				TreeMap<Integer, List<Integer>> playMusics = genreMusics.get(genre);
				if (playMusics.get(play) != null) {
					playMusics.get(play).add(i);
				} else {
					playMusics.put(play, new ArrayList<>(List.of(i)));
				}
			}
		}

		for (String genre : genrePlayCountMap.keySet()) {
			int play = genrePlayCountMap.get(genre);
			genreRanking.put(play, genre);
		}

		for (String genre : genreRanking.values()) {
			Collection<List<Integer>> playMusics = genreMusics.get(genre).values();
			int cnt = 0;
			for (List<Integer> musics : playMusics) {
				for (int i=0; i<musics.size() && cnt < 2; ++i) {
					answer.add(musics.get(i));
					++cnt;
				}
				if (cnt == 2) break;
			}
		}

		return answer.toArray(new Integer[answer.size()]);
	}
}
