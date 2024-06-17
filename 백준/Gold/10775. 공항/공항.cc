#include <cstring>
#include <iostream>
#define FIO cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100001
using namespace std;
int arr[MAX_SIZE];
int next_gate[MAX_SIZE];
int find(int x) {
	if (next_gate[x] == x) return x;
	return next_gate[x] = find(next_gate[next_gate[x]]);
}
void U(int x, int y) {
	int nx = find(x);
	int ny = find(y);
	if (nx == ny) return;
	next_gate[nx] = ny;
}
int main() {
	FIO;
	int g, p, to;
	cin >> g >> p;
	for (int i = 1; i <= p; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= g; i++) {
		next_gate[i] = i;
	}
	int result = 0;
	for (int i = 1; i <= p; i++) {
		int gate = find(arr[i]);
		if (gate == 0) break;
		U(gate, gate - 1);
		result++;
	}
	cout << result << "\n";
	return 0;
}