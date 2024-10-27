#include<cstring>
#include<iostream>
#include<queue>
#include<tuple>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef pair<int, pair<int, int>> pq;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(){
    FIO;
    priority_queue<pq, vector<pq>, greater<pq>> q;

    int n, m;
    cin >> n >> m;
    int map[n + 1][n + 1];
    int dist[n + 1][n + 1];
    memset(dist, -1, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> map[i][j];
            if(!map[i][j]) continue;
            q.push({map[i][j], {i, j}});
            dist[i][j] = map[i][j];
        }
    }

    priority_queue<pq, vector<pq>, greater<pq>> temp_q;
    int x, y;
    int time = 1;
    int s, tx, ty;
    cin >> s >> tx >> ty;
    if(!s){
        int result = dist[tx][ty] == -1 ? 0 : dist[tx][ty];
        cout << result << "\n";
        return 0;
    }
    int priority;
    while (!q.empty()) {
        priority = q.top().first;
        tie(x, y) = q.top().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || n < nx || ny <= 0 || n < ny) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y];
            temp_q.push({priority, {nx, ny}});
        }


        if(!q.empty()) continue;
        if(time == s){
            int result = dist[tx][ty] == -1 ? 0 : dist[tx][ty];
            cout << result << "\n";
            return 0;
        }
        time++;
        q = temp_q;
        while(!temp_q.empty()) temp_q.pop();
    }
    int result = dist[tx][ty] == -1 ? 0 : dist[tx][ty];
    cout << result << "\n";
    return 0;
}