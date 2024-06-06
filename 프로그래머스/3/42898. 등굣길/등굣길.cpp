#include <string>
#include <iostream>
#include <vector>
#define MAX_SIZE 101
#define mod 1000000007
using namespace std;
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    for(int i=0;i<puddles.size();i++){
        map[puddles[i][1]][puddles[i][0]] = 1;
    }
    dist[1][1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(map[i][j] == 1 || (i==1&&j==1)) continue;
            dist[i][j] = (dist[i-1][j] + dist[i][j-1])%mod;
        }
    }

    return dist[n][m]%mod;
}