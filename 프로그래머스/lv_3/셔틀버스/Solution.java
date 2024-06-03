package 셔틀버스;

import java.util.Arrays;

class Solution {
	int convertTimeToMinutes(String time) {
		int h = Integer.parseInt(time.substring(0, 2));
		int m = Integer.parseInt(time.substring(3));

		return h * 60 + m;
	}
	String convertMinutesToTime(int minutes) {
		String h = String.valueOf(minutes / 60);
		String m = String.valueOf(minutes % 60);

		if (minutes / 60 < 10) {
			h = "0" + h;
		}
		if (minutes % 60 < 10) {
			m = "0" + m;
		}
		return h + ":" + m;
	}
	// 마지막 셔틀버스 도착시간 혹은 마지막 셔틀버스 마지막 인원보다 1분 빨리 도착해야함
	// 도착시간 맞추는 것은 탑승이 바로 가능할 때만 가능
	public String solution(int n, int t, int m, String[] timetable) {
		// 우선 timetable 분 단위로 정렬
		int[] crewTimeTable = new int[timetable.length];
		for (int i=0; i<timetable.length; ++i) {
			crewTimeTable[i] = convertTimeToMinutes(timetable[i]);
		}
		Arrays.sort(crewTimeTable);

		int startTime = convertTimeToMinutes("09:00");
		int endTime = startTime + ((n-1) * t);
		int[] busSize = new int[n];
		int busTime = startTime;
		int lastCrewTime = 0;
		int busIdx = 0;
		int ans = 0;

		for (int i=0; i<crewTimeTable.length && busIdx < n; ) {
			// 버스 시간을 맞춤
			while (busTime < crewTimeTable[i] || (busIdx < n && busSize[busIdx] == m)) {
				busTime += t;
				busIdx += 1;
			}
			// 탑승 승객을 맞춤
			while (busIdx < n && busSize[busIdx] < m && i<crewTimeTable.length && crewTimeTable[i] <= busTime) {
				busSize[busIdx] += 1;
				lastCrewTime = crewTimeTable[i];
				++i;
			}
		}

		if (busSize[n-1] < m) {
			ans = endTime;
		} else {
			ans = lastCrewTime - 1;
		}

		//  문자열로 시간을 바꿔서 반환
		return convertMinutesToTime(ans);
	}
}
