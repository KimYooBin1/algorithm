#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <cstring>
#define MAX_SIZE 102
using namespace std;
int dx[8] = {0,0,-1,1,1,1,-1,-1};
int dy[8] = {-1,1,0,0,1,-1,1,-1};
int Dx[4] = {0,0,-1,1};
int Dy[4] = {-1,1,0,0};
vector<vector<int>> rec(MAX_SIZE, vector<int>());
int map[MAX_SIZE][MAX_SIZE];
int m[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    characterX *= 2;
    characterY *= 2;
    itemX *= 2;
    itemY *= 2;
    for(int i=0;i<rectangle.size();i++){
        int f_x, f_y, t_x, t_y;
        auto dot = rectangle[i];
        f_x = 2*dot[0], f_y = 2*dot[1], t_x = 2*dot[2], t_y = 2*dot[3];
        for(int i=f_x;i<=t_x;i++){
            for(int j=f_y;j<=t_y;j++){
                map[i][j] = 1;
            }
        }
    }
    for(int x=1;x<=100;x++){
        for(int y=1;y<=100;y++){
            if(map[x][y] != 1) continue;
            bool check = false;
            for(int i=0;i<8;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(map[nx][ny] == 0){
                    check = true;
                    break;
                }
            }
            if(check){
                m[x][y] = 1;
            }
        }
    }
    queue<pair<int,int>> q;
    memset(dist, -1, sizeof(dist));
    q.push(make_pair(characterX, characterY));
    dist[characterX][characterY] = 0;
    while(!q.empty()){
        int x,y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + Dx[i];
            int ny = y + Dy[i];
            if(m[nx][ny] != 1) continue;
            if(dist[nx][ny] != -1) continue;
            if(nx<=0 || 100<nx || ny<=0 || 100<ny) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    return dist[itemX][itemY] / 2;
}