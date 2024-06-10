#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 102

using namespace std;
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int n, m;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void check_empty_room(){

    memset(dist, -1, sizeof(dist));
    int x = 0;
    int y = 0;
    dist[x][y] = -2;
    queue<pair<int,int>> q;
    q.push(make_pair(x, y));
    while (!q.empty()) {
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || n+1<nx || ny<0 || m+1<ny) continue;
            if(dist[nx][ny] != -1) continue;
            if(map[nx][ny] == 1) continue;
            q.push(make_pair(nx, ny));
            dist[nx][ny] = -2;
        }
    }
//    for (int i = 0; i <= n + 1; i++) {
//        for (int j = 0; j <= m + 1; j++) {
//            cout<<dist[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//    cout<<"\n";
}
int main(){
    FIO;
    cin>>n>>m;
//    현재 치즈가 몇개인지
    int total_cnt = 0;
    queue<pair<int,int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin>>map[i][j];
            if(map[i][j] == 1) total_cnt++;
        }
    }
    int result = 0;
    while(total_cnt){
        result++;
        // 치즈가 남아있는지
        check_empty_room();
        for (int x = 0; x <= n; x++) {
            for (int y = 0; y <= m; y++) {
                if(map[x][y] == 1){
                    // 주변에 빈공간이 몇개인지
                    int cnt = 0;
                    for(int i=0;i<4;i++){
                        int nx = x + dx[i];
                        int ny = y + dy[i];
                        //범위 check
                        if(nx==0 || n+1==nx || ny == 0 || m+1==ny) continue;
                        //해당 공간이 빈공간이 아니면 continue, -2일때 빈공간으로 인식
                        if(dist[nx][ny] == -1) continue;
                        cnt++;
                     }
                    if(1<cnt) {
                        map[x][y] = 0;
                        total_cnt--;
                    }
                }
            }
        }
    }
    cout<<result<<"\n";
}