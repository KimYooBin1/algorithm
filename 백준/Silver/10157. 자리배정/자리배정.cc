#include<cstring>
#include<iostream>
#include<tuple>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int main(){
    FIO;
    int c, r;
    cin >> r >> c;
    int k;
    cin >> k;
    bool check[c + 1][r + 1];
    memset(check, false, sizeof(check));
    if(c * r < k){
        cout << 0 << "\n";
        return 0;
    }

    check[1][1] = true;
    int x = 1, y = 1, d = 0;
    for (int num = 1; num < k; num++) {
//        cout << x << " " << y << " " << d << " " << num << "\n";
        int nx = x + dx[d];
        int ny = y + dy[d];
//        cout << nx << " " << ny << "\n";
        if(0 < nx && nx <= c && 0 < ny && ny <= r && !check[nx][ny]){
            x = nx;
            y = ny;
            check[x][y] = true;
        }else{
            x = x + dx[(d + 1) % 4];
            y = y + dy[(d + 1) % 4];
            check[x][y] = true;
            d = (d + 1) % 4;
        }
    }
    cout << y << " " << x << "\n";
}