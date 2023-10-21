#include <string>
#include <vector>
#include <iostream>

using namespace std;

int percent[4] = {40, 30, 20, 10};
int max_price = 0;
int max_plus_cnt = 0;

void rec(vector<vector<int>> &users, vector<int> &emoticons, vector<double> &sale_percent, int idx) {
	if (idx == emoticons.size()) {
		int total_price = 0;
		int plus_cnt = 0;
		for (int i=0; i<users.size(); ++i) {
			int user_price = 0;
			for (int j=0; j<emoticons.size(); ++j) {
				if (users[i][0] <= sale_percent[j])
					user_price += emoticons[j] * ((100 - sale_percent[j]) / 100);
			}
			if (user_price >= users[i][1])
				++plus_cnt;
			else
				total_price += user_price;
		}
		if (max_plus_cnt < plus_cnt) {
			max_plus_cnt = plus_cnt;
			max_price = total_price;
		}
		else if (max_plus_cnt == plus_cnt) {
			if (max_price < total_price)
				max_price = total_price;
		}
		return ;
	}
	for (int i=0; i<4; ++i) {
		sale_percent.push_back(percent[i]);
		rec(users, emoticons, sale_percent, idx+1);
		sale_percent.pop_back();
	}
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
	vector<int> answer;
	vector<double> sale_percent;
	rec(users, emoticons, sale_percent, 0);
	answer.push_back(max_plus_cnt);
	answer.push_back(max_price);
	return answer;
}
