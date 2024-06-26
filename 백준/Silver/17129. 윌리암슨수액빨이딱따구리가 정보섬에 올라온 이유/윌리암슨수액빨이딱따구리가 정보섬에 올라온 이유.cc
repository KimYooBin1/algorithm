#include<cstring>
#include<iostream>
#include<queue>
#include<tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 3001
using namespace std;
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    string str;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j] - '0';
            if(map[i][j] == 2){
                x = i; y = j;
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if(map[nx][ny] == 1) continue;
            if(dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
            if(map[nx][ny] != 0){
                cout << "TAK\n" << dist[nx][ny] << "\n";
                return 0;
            }
        }
    }
    cout << "NIE\n";
    return 0;
}