#include<cstring>
#include<iostream>
#include<queue>
#include<tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 2001
using namespace std;
char map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int dx[7] = {-1, -1, 0, 1, -1, 1, 0};
int dy[7] = {-1, 1, 1, 1, 0, -1, -1};
int main(){
    FIO;
    int n;
    cin >> n;
    string str;
    int x, y;
    for (int i = 0; i < n; i++) {
        cin>>str;
        for (int j = 0; j < n; j++) {
            map[i][j] = str[j];
            if(map[i][j] == 'F'){
                x = i; y = j;
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    q.push({x, y});
    dist[x][y] = 0;
    int result = 0;
    while (!q.empty()) {
        tie(x, y) = q.front(); q.pop();
        for (int i = 0; i < 7; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || n <= nx || ny < 0 || n <= ny) continue;
            if(map[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y];
            result++;
        }
    }
    cout << result << "\n";
    return 0;
}