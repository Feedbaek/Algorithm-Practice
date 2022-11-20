#include <string>
#include <cstring>
#include <vector>
#include <list>
using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	list<string> li;
	for (int i=0; i<cities.size(); ++i) {
		list<string>::iterator iter = li.begin();
		while (!li.empty() && iter != li.end()) {
			if (strcasecmp((*iter).c_str(), cities[i].c_str()) == 0)
				break;
			++iter;
		}
		li.push_front(cities[i]);
		if (iter == li.end())
			answer += 5;
		else {
			li.erase(iter);
			answer += 1;
		}
		if (li.size() > cacheSize)
			li.pop_back();
	}
	return answer;
}
