#include <cstring>
#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};
int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> map(n, vector<int> (m, 0));
    vector<vector<bool>> check(n, vector<bool> (m, false));

    int r, c, d;
    cin >> r >> c >> d;
    if(d == 1) d = 3;
    else if(d == 3) d = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>map[i][j];
        }
    }
//    r = n - r - 1;
//    map[r][c] = 0;
    check[r][c] = true;
    queue<tuple<int,int, int>> q;
    q.push({r, c, d});
    int result = 1;
    while(!q.empty()){
        int x, y, dir;
        tie(x, y, dir) = q.front(); q.pop();
//        cout << x << " " << y << " " << dir << "\n";
        bool clean = false;
        for (int i = 1; i <= 4; i++) {
            int nx = x + dx[(dir + i) % 4];
            int ny = y + dy[(dir + i) % 4];
            if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if(map[nx][ny]) continue;
            if(check[nx][ny]) continue;
            map[nx][ny] = 0;
            clean = true;
            q.push({nx, ny, (dir + i) % 4});
            check[nx][ny] = true;
            result++;
            break;
        }
        if(!clean){
            int nx = x - dx[dir];
            int ny = y - dy[dir];
            if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if(map[nx][ny]) continue;
//            map[nx][ny] = 0;
//            result++;
            q.push({nx, ny, dir});
        }
    }
    cout << result << "\n";
}