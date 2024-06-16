#include<iostream>
#include<cstring>
#include<algorithm>
#include<tuple>
#include<queue>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 1001
using namespace std;
char map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int calc(char c){
    if(c == 'U'){
        return 0;
    }
    else if(c == 'R'){
        return 1;
    }else if(c == 'D'){
        return 2;
    }else if(c == 'L'){
        return 3;
    }
    return 0;
}
int main(){
    FIO;
    int n, m, x, y;
    cin >> n >> m;
    string str;
    for (int i = 0; i < n; i++) {
        cin>>str;
        for (int j = 0; j < m; j++) {
            map[i][j] = str[j];
        }
    }
    queue<pair<int, int>> q;
    int result = 0;
    int desc = 0;
    memset(dist, -1, sizeof(dist));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(dist[i][j] != -1) continue;
            q.push(make_pair(i, j));
            dist[i][j] = result++;
            while(!q.empty()){
                tie(x, y) = q.front();
                q.pop();
                int index = calc(map[x][y]);
                int nx = x + dx[index];
                int ny = y + dy[index];
                if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
                //cycle을 만들었거나 이미 safe zone이 있는 그륩에 도착
                if(dist[nx][ny] != -1) {
                    //다른 그륩
                    if(dist[nx][ny] != dist[x][y]){
                        desc++;
                    }
                    continue;
                }
                q.push({nx, ny});
                dist[nx][ny] = dist[x][y];
            }
        }
    }
    cout << result - desc << "\n";
    return 0;
}
