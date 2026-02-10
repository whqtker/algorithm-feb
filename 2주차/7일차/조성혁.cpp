#include <iostream>
#include <string>

using namespace std;

int n;

bool able(string str) {
	int cnt = 1;
	int len = str.length();

	while (1) {
		int patternStart = len - 2 * cnt;
		int targetStart = len - cnt;

		if (patternStart < 0) break;

		if (str.substr(patternStart, cnt) == str.substr(targetStart, cnt)) {
			return false;
		}

		cnt++;
	}

	return true;
}

void dfs(string str) {
	if (able(str)) {
		if (str.length() == n) {
			cout << str;
			exit(0);
		}

		for (int i = 1; i <= 3; i++) {
			dfs(str + (char)(i + '0'));
		}
	}
}

int main() {
	cin >> n;

	dfs("");
}
