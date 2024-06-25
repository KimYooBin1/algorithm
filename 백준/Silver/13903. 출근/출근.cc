#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 1001
using namespace std;
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
vector<int> dx;
vector<int> dy;
int main(){
    FIO;
    int r, c;
    cin >> r >> c;
    queue<pair<int,int>> q;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin>>map[i][j];
            if (!i && map[i][j]) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }
    int n, x, y;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        dx.push_back(x);
        dy.push_back(y);
    }
    while(!q.empty()){
        tie(x, y) = q.front(); q.pop();
//        cout << x << " " << y << " " << dist[x][y] << "\n";
        for (int i = 0; i < n; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || r<=nx || ny < 0 || c<=ny) continue;
            if(!map[nx][ny]) continue;
            if(dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
            if(nx == r - 1){
                cout << dist[nx][ny] << "\n";
                return 0;
            }
        }
    }
    cout << -1 << "\n";
    return 0;
}