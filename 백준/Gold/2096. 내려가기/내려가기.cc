#include<iostream>

#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100001
using namespace std;
int map[MAX_SIZE][3];
int min_dist[2][3];
int max_dist[2][3];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 2; j++) {
            int m = -1;
            int m1 = -1;
            for (int z = -1; z <= 1; z++) {
                if(j+z == -1 || j+z == 3) continue;
                if(m == -1 || min_dist[0][z + j] < m) m = min_dist[0][z + j];
                if(max_dist[0][z + j] > m1) m1 = max_dist[0][z + j];

            }
            min_dist[1][j] = m + map[i][j];
            max_dist[1][j] = m1 + map[i][j];
        }
        for (int i = 0; i < 3; i++) {
            min_dist[0][i] = min_dist[1][i];
            max_dist[0][i] = max_dist[1][i];
        }
    }
    int result1 = -1;
    int result2 = -1;
    for (int i = 0; i < 3; i++) {
        if(result2 == -1 || result2 > min_dist[1][i]) result2 = min_dist[1][i];
        if(result1 < max_dist[1][i]) result1 = max_dist[1][i];
    }
    cout<<result1<<" "<<result2<<"\n";
}