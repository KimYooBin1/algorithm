#include <cstring>
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <deque>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
struct info{
    int X;
    char C;
};
int main(){
    FIO;
    int n, k;
    cin >> n >> k;
    vector<vector<int>> map(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        map[x][y] = 1;
    }
    int L;
    cin>>L;
    vector<info> v(L);
    for (int i = 0; i < L; i++) {
        cin >> v[i].X >> v[i].C;
    }
    int index = 0;
    queue<tuple<int, int, int>> q;
    q.push({1, 1, 0});
    deque<pair<int,int>> tail;
    tail.push_back({1, 1});
    int time = 0;
    while (!q.empty()) {
        int x, y, d, tx, ty;
        tie(x, y, d) = q.front(); q.pop();
//        cout << x << " " << y << " " << d << " " << time << "\n";
        if(v[index].X == time){
            d = v[index++].C == 'L' ? (d + 1) % 4 : (d + 3) % 4;
        }
        int nx = x + dx[d];
        int ny = y + dy[d];
        if (nx <= 0 || n < nx || ny <= 0 || n < ny) continue;
        if(map[nx][ny] == 2) continue;
        if(map[nx][ny]){
            map[nx][ny] = 2;
        }else{
            tie(tx, ty) = tail.front(); tail.pop_front();
            map[tx][ty] = 0;
        }
        tail.push_back({nx, ny});
        map[nx][ny] = 2;
        q.push({nx, ny,  d});
        time++;
    }
    cout << time + 1 << "\n";
}