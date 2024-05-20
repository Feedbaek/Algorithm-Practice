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
		int currentSize = 0;
		int busTime = startTime;
		int currentRound = 0;
		int lastCrewTime = 0;
		int lastBusTime = endTime;
		int ans = endTime;
		for (int crewTime : crewTimeTable) {
			// 버스 탑승 시작
			if (busTime < crewTime) {  // 시간 지나서 다음 버스 타야 함
				while (busTime < crewTime) {
					++currentRound;
					busTime += t;
					if (currentRound == n || busTime > endTime) {
						break;
					}
					lastBusTime = busTime;
					lastCrewTime = busTime;
					currentSize = 0;
				}
				//currentRound += (crewTime - busTime) / t + 1;
				//busTime += ((crewTime - busTime) / t + 1) * t;
				if (currentRound >= n || busTime > endTime) {  // 막차였다면
					if (currentSize == m) {  // 인원이 가득 찼다면
						ans = lastCrewTime - 1;
					} else {  // 가득찬게 아니였다면
						ans = lastBusTime;
					}
					break;
				}
				currentSize = 1;
			} else {  // 오는 버스 탈 수 있음
				if (currentSize < m) {  // 탑승
					++currentSize;
				} else {  // 만석이라 다음 버스 타야 함
					currentRound += (crewTime - busTime) / t + 1;
					busTime += ((crewTime - busTime) / t + 1) * t;
					if (currentRound >= n || busTime > endTime) {  // 막차였다면
						ans = lastCrewTime - 1;
						break;
					}
					currentSize = 1;
				}
			}
			lastBusTime = busTime;
			lastCrewTime = crewTime;
		}

		if (busTime <= endTime) {  // 모든 크루가 탑승한 경우
			ans = endTime;
			if (busTime == endTime && currentSize == m) {
				ans = lastCrewTime - 1;
			}
		}
		//  문자열로 시간을 바꿔서 반환
		return convertMinutesToTime(ans);
	}
}
