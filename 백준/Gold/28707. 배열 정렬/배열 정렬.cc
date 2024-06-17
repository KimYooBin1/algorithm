#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define FIO cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 9
using namespace std;
int main() {
	FIO;
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int m;
	cin >> m;
	int l, r, c;
	vector<tuple<int, int, int>> change;
	for (int i = 0; i < m; i++) {
		cin >> l >> r >> c;
		l--; r--;
		change.push_back({ l, r, c });
	}
	map<vector<int>, int> check;
	check[v] = 0;
	priority_queue<pair<int, vector<int>>> pq;
	pq.push({ 0, v });
	while (!pq.empty()) {
		auto cost = -pq.top().first;
		auto now = pq.top().second;
		pq.pop();
		for (int i = 0; i < change.size(); i++) {
			auto tmp = change[i];
			l = get<0>(tmp);
			r = get<1>(tmp);
			c = get<2>(tmp);
			swap(now[l], now[r]);
			
			if (check.find(now) == check.end() || cost + c < check[now]) {
				pq.push({ -(check[now] = cost + c), now });
			}

			swap(now[l], now[r]);
		}
	}
	sort(v.begin(), v.end());
	if (check.find(v) != check.end()) {
		cout << check[v] << "\n";
	}
	else {
		cout << -1 << "\n";
	}
	return 0;
}