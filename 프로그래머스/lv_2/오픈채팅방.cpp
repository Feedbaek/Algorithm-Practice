#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map<string, string> id_nick;

	for (int i=0; i<record.size(); ++i) {
		int st = 0;
		int en = record[i].find(" ", st);
		string cmd = record[i].substr(st, en);
		if (cmd == "Leave")
			continue;
		st = en + 1;
		en = record[i].find(" ", st);
		string id = record[i].substr(st, en - st);
		st = en + 1;
		en = record[i].find(" ", st);
		string nick = record[i].substr(st, en - st);
		id_nick[id] = nick;
	}
	for (int i=0; i<record.size(); ++i) {
		int st = 0;
		int en = record[i].find(" ", st);
		string cmd = record[i].substr(st, en);
		if (cmd == "Change")
			continue;
		st = en + 1;
		en = record[i].find(" ", st);
		string id = record[i].substr(st, en - st);
		if (cmd == "Enter")
			answer.push_back(id_nick[id] + "님이 들어왔습니다.");
		else
			answer.push_back(id_nick[id] + "님이 나갔습니다.");
	}
	return answer;
}
