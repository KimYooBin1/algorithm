#include<iostream>
#include<cstring>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100001
#define mod 1000000007
using namespace std;
typedef long long ll;
ll dist[MAX_SIZE][8];
int main(){
    FIO;
    int n;
    cin >> n;
    dist[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        dist[1][i] = (dist[2][i-1] + dist[3][i-1])%mod;
        dist[2][i] = (dist[1][i-1] + dist[3][i-1] + dist[4][i-1])%mod;
        dist[3][i] = (dist[1][i-1] + dist[2][i-1] + dist[4][i-1] + dist[5][i-1])%mod;
        dist[4][i] = (dist[2][i-1] + dist[3][i-1] + dist[5][i-1] + dist[6][i-1])%mod;
        dist[5][i] = (dist[3][i-1] + dist[4][i-1] + dist[6][i-1] + dist[8][i-1])%mod;
        dist[6][i] = (dist[4][i-1] + dist[5][i-1] + dist[7][i-1])%mod;
        dist[7][i] = (dist[6][i-1] + dist[8][i-1])%mod;
        dist[8][i] = (dist[5][i-1] + dist[7][i-1])%mod;
    }
    cout << dist[1][n] << "\n";
    return 0;
}
