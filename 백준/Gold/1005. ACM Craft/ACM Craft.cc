#include <iostream>
#include <vector>
#include <cstring>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 1001
using namespace std;

int dfs(int x, vector<vector<int>>& road, vector<int>& dist, vector<int>& T) {
    if (dist[x] != -1) return dist[x];  // 메모이제이션 체크
    int result = 0;
    for (int i : road[x]) {
        result = max(result, dfs(i, road, dist, T));
    }
    return dist[x] = result + T[x];
}

int main() {
    FIO;
    int t;
    cin >> t;
    while (t--) {
        vector<vector<int>> road(MAX_SIZE);
        vector<int> dist(MAX_SIZE, -1);  // 초기값을 -1로 설정
        vector<int> T(MAX_SIZE);
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> T[i];
        }
        for (int i = 0; i < k; i++) {
            int from, to;
            cin >> from >> to;
            road[to].push_back(from);
        }
        int target;
        cin >> target;
        cout << dfs(target, road, dist, T) << "\n";
    }
    return 0;
}
