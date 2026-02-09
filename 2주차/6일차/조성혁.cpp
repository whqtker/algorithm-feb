#include <iostream>
#include <queue>

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	int tc = 0;
	while (1) {
		tc++;
		int n;
		cin >> n;
		if (!n) return 0;

		// 시작 좌표 기준으로 정렬, 같다면 길이 순으로 정렬
		priority_queue<pair<double, double>, vector<pair<double, double>>, greater<pair<double, double>>> pq;
		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			pq.push({ a,b });
		}

		double t = 8; // 파티 시작 시간
		int cnt = 0;
		while (!pq.empty() && t < 24) {
			// 종료 시간이 현재 시간보다 앞인 경우 제거
			while (!pq.empty() && pq.top().second <= t) {
				pq.pop();
			}

			// 시작 시간이 현재 시간보다 앞인 경우 보정
			while (!pq.empty() && pq.top().first < t) {
				double first = t;
				double second = pq.top().second;
				pq.pop();
				pq.push({ first,second });
			}

			if (pq.empty()) break;

			// 파티 시간 범위가 유효한 경우
			int start = pq.top().first;
			int end = pq.top().second;
			if (start <= t && t <= end) {
				cnt++;
				pq.pop();
			}

			t += 0.5;
		}

		cout << "On day " << tc << " Emma can attend as many as " << cnt << " parties.\n";
	}
}
