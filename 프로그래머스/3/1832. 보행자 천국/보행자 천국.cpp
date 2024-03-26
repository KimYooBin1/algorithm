#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    
    int MOD = 20170805;
    int answer = 0;
    long long dist[m+1][n+1][2];  //0이면 좌우 1이면 상하
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            dist[i][j][0] = 0;
            dist[i][j][1] = 0;
        }
    }
    dist[0][0][0] = 1;
    dist[0][0][1] = 1;
    for(int i=1;i<n;i++){
        if(city_map[0][i] == 1) continue;
        dist[0][i][0] = dist[0][i-1][0];
    }
    for(int i=1;i<m;i++){
        if(city_map[i][0] == 1) continue;
        dist[i][0][1] = dist[i-1][0][1];
    }
    //city_map이 0일땐 [0][1] 다 받아오고 1일땐 방향에 맞게 위쪽에서 [1] 왼쪽에서 [0]값을 가져온다
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(city_map[i-1][j] == 0){
                dist[i][j][1] = dist[i-1][j][0] + dist[i-1][j][1];
            }
            else if(city_map[i-1][j] == 2){
                dist[i][j][1] = dist[i-1][j][1];
            }
            if(city_map[i][j-1] == 0){
                dist[i][j][0] = dist[i][j-1][0] + dist[i][j-1][1];
            }
            else if(city_map[i][j-1] == 2){
                dist[i][j][0] = dist[i][j-1][0];
            }
            dist[i][j][0] %= MOD;
            dist[i][j][1] %= MOD;
        }
    }
    return (dist[m-1][n-1][1] + dist[m-1][n-1][0]) % MOD;
}