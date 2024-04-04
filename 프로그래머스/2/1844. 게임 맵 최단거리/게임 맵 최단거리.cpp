#include<vector>
#include<queue>
#include<cstring>
#include<iostream>
#define MAX_SIZE 101
using namespace std;

int dist[MAX_SIZE][MAX_SIZE];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

int solution(vector<vector<int> > maps)
{
    memset(dist, -1, sizeof(dist));
    int n = maps.size();
    int m = maps[0].size();
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 1;
    int answer = 0;
    while(!q.empty()){
        int x, y;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || n<=nx || ny<0 || m<=ny) continue;
            if(maps[nx][ny] == 0) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push(make_pair(nx,ny));
        }
    }
    return dist[n-1][m-1];
}