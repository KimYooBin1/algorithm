#include<cstring>
#include<iostream>
#include<queue>
#include<tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 101
using namespace std;
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int g_size[10001];
int g = 1;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(){
    FIO;
    int n, m, k, x, y;
    cin >> n >> m >> k;
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>map[i][j];
        }
    }
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(map[i][j]) continue;
            if(dist[i][j] != -1) continue;
            q.push({i, j});
            dist[i][j] = g++;
            g_size[dist[i][j]] = 1;
            while(!q.empty()){
                tie(x, y) = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || n<= nx || ny<0 || n<= ny) continue;
                    if(map[nx][ny] == 1) continue;
                    if(dist[nx][ny] != -1) continue;
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y];
                    g_size[dist[nx][ny]]++;
                }
            }
        }
    }
    for (int i = 1; i < g; i++) {
        int tmp = g_size[i]/k;
        if(g_size[i]%k){
            tmp++;
        }
        m -= tmp;
        if(m<0) {
            cout<<"IMPOSSIBLE\n";
            return 0;
        }
    }
    if(g == 1){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    cout << "POSSIBLE\n" << m;
    return 0;
}