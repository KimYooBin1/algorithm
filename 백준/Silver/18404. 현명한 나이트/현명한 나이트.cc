#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 1001
using namespace std;
int dist[MAX_SIZE][MAX_SIZE];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    queue<pair<int,int>> q;
    memset(dist, -1, sizeof(dist));
    int x, y;
    cin >> x >> y;
    q.push({--x, --y});
    dist[x][y] = 0;
    vector<pair<int,int>> v;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        v.push_back({--x, --y});
    }
    while(!q.empty()){
        tie(x, y) = q.front(); q.pop();

        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
    for (int i = 0; i < v.size(); i++) {
        cout << dist[v[i].first][v[i].second] << " ";
    }
    cout << "\n";
    return 0;
}