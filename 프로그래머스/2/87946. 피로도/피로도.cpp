#include <string>
#include <vector>
#include <iostream>

#define MAX_SIZE 5001
using namespace std;

bool check[MAX_SIZE];

int dfs(int k, vector<vector<int>> dungeons){
    int cnt = 0;
    for(int i=0;i<dungeons.size();i++){
        if(check[i]) continue;
        int need = dungeons[i][0];
        if(k<need) continue;
        check[i] = true;
        int result = dfs(k-dungeons[i][1], dungeons) + 1;
        check[i] = false;
        cnt = max(cnt, result);
    }
    return cnt;
}

int solution(int k, vector<vector<int>> dungeons) {
    int result = dfs(k, dungeons);
    return result;
}