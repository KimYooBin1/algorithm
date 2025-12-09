#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
void rolling (int d, vector<int> &v){
    vector<int> tmp(7);
    if(d == 1){
        tmp = {0, v[4], v[2], v[1], v[6], v[5], v[3]};
    }else if(d == 2){
        tmp = {0, v[3], v[2], v[6], v[1], v[5], v[4]};
    }else if(d == 3){
        tmp = {0, v[2], v[6], v[3], v[4], v[1], v[5]};
    }else{
        tmp = {0, v[5], v[1], v[3], v[4], v[6], v[2]};
    }
    v = tmp;
}

int main(){
    FIO;
    int n, m, x, y, k;
    cin >> n >> m >> x >> y >> k;
    vector<vector<int>> map(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
    vector<int> dice(7, 0);
    for (int i = 0; i < k; i++) {
//        cout<<x<<" "<<y<<"\n";
        int dir;
        cin >> dir;
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
        rolling(dir, dice);
        if (map[nx][ny]) {
            dice[1] = map[nx][ny];
            map[nx][ny] = 0;
        } else { map[nx][ny] = dice[1]; }
        cout<<dice[6]<<"\n";
        x = nx, y = ny;

    }
    cout<<"\n";

}