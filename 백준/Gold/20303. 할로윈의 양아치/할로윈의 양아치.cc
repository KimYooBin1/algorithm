#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define FIO cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 30001
using namespace std;
int arr[MAX_SIZE];
int dist[MAX_SIZE];
int g_size[MAX_SIZE];
int g_value[MAX_SIZE];
int result[MAX_SIZE][3001];
int main() {
    FIO;
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    int a, b;
    vector<vector<int>> v(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    int g = 1;
    for (int i = 1; i <= n; i++) {
        if (dist[i] != 0) continue;
        g_size[g]++;
        g_value[g] = arr[i];
        dist[i] = g++;
        q.push(i);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (int j = 0; j < v[x].size(); j++) {
                int nx = v[x][j];
                if (dist[nx] != 0) continue;
                dist[nx] = dist[x];
                q.push(nx);
                g_size[dist[x]]++;
                g_value[dist[x]] += arr[nx];
            }
        }
    }
    int out = 0;
    for (int i = 1; i < g; i++) {
        for (int j = 1; j < k; j++) {
            result[i][j] = result[i-1][j];
            if(0<=j-g_size[i]){
                result[i][j] = max(result[i][j], result[i-1][j - g_size[i]] + g_value[i]);
            }
            out = max(out, result[i][j]);
        }
    }
    cout << out << "\n";
    return 0;
}