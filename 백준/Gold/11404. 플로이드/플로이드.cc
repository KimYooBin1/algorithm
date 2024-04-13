#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define MAX_SIZE 101
#define INF INT_MAX
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
int n, m;
long long map[MAX_SIZE][MAX_SIZE];
long long dist[MAX_SIZE][MAX_SIZE];
int main()
{
    FIO;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for (int j = 1; j <= n; j++) {
            map[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        long long from, to ,cost;
        cin >> from >> to >> cost;
        map[from][to] = min(map[from][to], cost);
    }

    for(int i = 1; i<=n; i++){
        for(int j=1;j<=n;j++){
            if(i==j) dist[i][j] = 0;
            else if(map[i][j]) dist[i][j] = map[i][j];
        }
    }

    for (int z = 1; z <= n; z++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[z][j] + dist[i][z]);
            }
        }
    }
    for(int i = 1; i<=n; i++){
        for(int j =1; j<=n; j++){
            if(dist[i][j] == INF){
                cout<<0<<" ";
            }
            else{
                cout<<dist[i][j]<<" ";
            }
        }
        cout<<"\n";
    }

    return 0;
}