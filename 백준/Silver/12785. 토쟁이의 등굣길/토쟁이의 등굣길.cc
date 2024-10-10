#include<cstring>
#include<iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 202
#define MOD 1000007
int w, h, x, y;
int dist[MAX_SIZE][MAX_SIZE];
long long BFS(int sx, int sy, int Dx, int Dy) {
    memset(dist, 0, sizeof(dist));
    dist[sx][sy] = 1;
    for (int i = sx; i <= Dx; i++) {
        for (int j = sy; j <= Dy; j++) {
            dist[i + 1][j] = (dist[i + 1][j] + dist[i][j]) % MOD;
            dist[i][j + 1] = (dist[i][j + 1] + dist[i][j]) % MOD;
        }
    }
    return dist[Dx][Dy] % MOD;
}
int main(){
    FIO;
    cin >> w >> h >> x >> y;
    long long result1 = BFS(1, 1, x, y);
    long long result2 = BFS(x, y, w, h);
//    cout << result1 << " " << result2 << "\n";
    cout << (result1 * result2) % MOD << "\n";
}