#include<cstring>
#include<iostream>
#include<queue>
#include<tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 501
using namespace std;
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int g = 0;
int main(){
    FIO;
    int n, m, k, x, y;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>map[i][j];
        }
    }
    queue<pair<int,int>> q;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(dist[i][j] != -1) continue;
            dist[i][j] = g++;
            q.push({i, j});
            while(!q.empty()){
                tie(x, y) = q.front(); q.pop();
                for (int z = 0; z < 4; z++) {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
                    if(dist[nx][ny] != -1) continue;
                    if (k < abs(map[nx][ny] - map[x][y])) continue;
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y];
                }
            }
        }
    }
    cout << g << "\n";

    return 0;
}