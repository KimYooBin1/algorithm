#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define MAX_SIZE 5
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int c = 0;

bool dfs(int x, int y){
    if(3 < dist[x][y]) return false;
    if (2 <= c) return true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || MAX_SIZE <= nx || ny < 0 || MAX_SIZE <= ny) continue;
        if (dist[nx][ny] != -1 || map[nx][ny] == -1) continue;
        if(map[nx][ny] == 1) c++;
        dist[nx][ny]  = dist[x][y] + 1;
        if(dfs(nx, ny)) return true;
        dist[nx][ny] = -1;
        if(map[nx][ny] == 1) c--;
    }
    return false;
}

int main(){
    FIO;
    for (auto & i : map) {
        for (int & j : i) {
            cin>>j;
        }
    }
    int r, c;
    cin >> r >> c;
    memset(dist, -1, sizeof(dist));
    if(map[r][c] == 1) c++;
    dist[r][c] = 0;
    if (dfs(r, c)) {
        cout << 1 << "\n";
    } else {
        cout << 0 << "\n";
    }

    return 0;
}