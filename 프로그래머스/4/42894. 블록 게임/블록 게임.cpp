#include <string>
#include <vector>
#include <iostream>
#include <cstring>
using namespace std;
int c[5][4][2] = 
{
     {{0, 0},{1, 0},{1, 1},{1, 2}},
     {{0, 0},{1, 0},{2, 0},{2, -1}},
     {{0 ,0},{1, 0},{2, 0},{2, 1}},
     {{0 ,0},{1, 0},{1, -1},{1, -2}},
     {{0, 0},{1, 0},{1, -1},{1, 1}}
};
int c1[5][2][2] = 
{
    {{0, 1},{0, 2}},
    {{0, -1},{1, -1}},
    {{0, 1},{1, 1}},
    {{0, -1},{0, -2}},
    {{0, -1},{0, 1}}
};
bool check[201];
// 위쪽 칸이 막혀있는경우
bool block[51];

void remove(int x, int y, int index, vector<vector<int>>& b){
    for(int i=0;i<4;i++){
        int nx = x + c[index][i][0];
        int ny = y + c[index][i][1];
        b[nx][ny] = 0;
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    int n = board.size();
    int k = 201;
    while(k--){
        // 이번 회차에서 검사를 진행했는지 확인
        memset(check, false, sizeof(check));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 0) continue;
                if(check[board[i][j]]) continue;
                check[board[i][j]] = true;
                // cout<<i<<" "<<j<<"\n";
                int index = -1;
                for(int z = 0;z<5;z++){
                    bool success = true;
                    for(int c_index = 0; c_index < 4;c_index++){
                        int x = i + c[z][c_index][0];
                        int y = j + c[z][c_index][1];
                        // 해당 index의 모양이 아님
                        if(x < 0 || n <= x || y < 0 || n <= y) {
                            success = false;
                            break;
                        }
                        if(board[x][y] != board[i][j]) {
                            success = false;
                            break;
                        }
                    }
                    if(success) index = z;
                }
                if(index == -1) continue;
                // cout<<index<<"\n";
                
                bool flag = true;
                //i, j 위치에서 index의 모양
                for(int c_index = 0; c_index < 2; c_index++){
                    int x = i + c1[index][c_index][0];
                    int y = j + c1[index][c_index][1];
                    // 해당 위치에 다른 블럭이 존재
                    if(x < 0 || n <= x || y < 0 || n <= y){
                        flag = false;
                        break;
                    }
                    if(board[x][y] != 0){
                        flag = false;
                        break;
                    }
                    // cout<<x<<" "<<y<<"\n";
                    for(int tmp = x; tmp >= 0; tmp--){
                        // cout<<tmp<<" "<<y<<" "<<board[tmp][y]<<"\n";
                        if(board[tmp][y] != 0){
                            flag = false;
                            break;
                        }
                    }
                    if(!flag) break;
                }
                if(flag){
                    // cout<<i<<" "<<j<<"\n";
                    remove(i, j, index, board);
                    answer++;
                }
                

            }
        }
    }
    return answer;
}