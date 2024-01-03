package 소수_찾기;

import java.util.ArrayList;

class Solution {
	ArrayList<Integer> prime_list;
	ArrayList<Integer> remain_list;

	boolean is_prime(int n) {	// 소수 판별 함수
		if (n < 2)
			return false;
		for (int i=2; i*i<=n; i++)
			if (n % i == 0)
				return false;
		return true;
	}

	void make_num(int length, int current_len, int answer) {	// i자릿수 숫자 만들기
		if (current_len == length) {	// i자릿수 일떄
			if (is_prime(answer) && !prime_list.contains(answer))	// 중복되지 않는 소수면
				prime_list.add(answer);	// prime_list에 추가
			return ;
		}
		for (int idx=0, num; idx<remain_list.size(); idx++) {	// remain_list에 남은 수를 모두 사용
			num = remain_list.get(idx);
			remain_list.remove(idx);	// 뽑은 수를 remain_list에서 지우고
			make_num(length, current_len+1, (answer*10)+num);	// 뽑은 수를 반영해서 다음 자릿 수 검사
			remain_list.add(idx, num);	// 뽑았던 수 다시 remain_list에 추가
		}
	}

	public int solution(String numbers) {
		prime_list = new ArrayList<>();	// 중복없이 소수를 저장하는 리스트
		remain_list = new ArrayList<>();	// 남은 수를 저장하는 리스트
		for (int i=0; i<numbers.length(); i++)	// remain_list 초기 설정
			remain_list.add(numbers.charAt(i)-'0');
		for (int i=1; i<=numbers.length(); i++)	// 1자릿수 부터 number.length 자릿수까지 검사
			make_num(i, 0, 0);	// 1자릿수 검사, 현재 0자릿수, 초기 숫자세팅 0
		return prime_list.size();
	}
}
