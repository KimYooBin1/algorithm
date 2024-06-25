#include<cstring>
#include<iostream>
#include<queue>
#include<tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 101
using namespace std;
int dx[4] = {0, 0, -1 , 1};
int dy[4] = {-1, 1, 0, 0};
//0이면 아무것도 아님, 1이면 쓰레기
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int main(){
    FIO;
    int n, m, k;
    cin >> n >> m >> k;
    int x, y;
    for (int i = 0; i < k; i++) {
        cin >> x >> y;
        map[--x][--y] = 1;
    }
    queue<pair<int,int>> q;
    int g = 1;
    int result = 0;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j] == 0) continue;
            if(dist[i][j] != -1) continue;
            q.push({i, j});
            dist[i][j] = g++;
            int size = 1;
            while(!q.empty()){
                tie(x, y) = q.front(); q.pop();
                for (int z = 0; z < 4; z++) {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if(dist[nx][ny] != -1) continue;
                    if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
                    if(map[nx][ny] == 0) continue;
                    dist[nx][ny] = dist[x][y];
                    q.push({nx, ny});
                    size++;
                }
            }
            if(result < size) result = size;
        }
    }
    cout << result << "\n";
    return 0;
}