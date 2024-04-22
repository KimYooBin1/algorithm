#include<cstring>
#include<iostream>
#include<queue>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    int s_x, s_y;
    int map[n][m];
    int dist[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>map[i][j];
            dist[i][j] = -1;
            if(map[i][j] == 2){
                s_x = i;
                s_y = j;
            }
            else if(map[i][j] == 0){
                dist[i][j] = 0;
            }
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(s_x, s_y));
    dist[s_x][s_y] = 0;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || n<=nx || ny<0 || m<=ny) continue;
            if(dist[nx][ny] != -1) continue;
            q.push(make_pair(nx, ny));
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout<<dist[i][j]<<" ";
        }
        cout << "\n";
    }
}