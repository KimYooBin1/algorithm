#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 51
using namespace std;
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int main(){
    FIO;
    int n, m, t;
    cin >> n >> m >> t;
    queue<pair<int,int>> q;
    int a_x, a_y;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>map[i][j];
            if(map[i][j] == -1){
                a_x = i;
                a_y = j;
            }
        }
    }
    int x, y;
    while(t--){
        memset(dist, 0, sizeof(dist));
        //현재 map에서 먼지가 남아있는 부분을 check
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(0<map[i][j]){
                    q.push(make_pair(i, j));
                }
            }
        }

        while(!q.empty()){
            tie(x, y) = q.front();
            q.pop();
            int sum = map[x][y];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                //범위를 넘어서거나 공기청정기가 있으면
                if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
                if(map[nx][ny] == -1) continue;
                dist[nx][ny] += map[x][y] / 5;
                sum -= map[x][y]/5;
            }
            dist[x][y] += sum;
        }
        memcpy(map, dist, sizeof(dist));
        map[a_x][a_y] = -1;
        map[a_x-1][a_y] = -1;
//        for(int i=0;i<n;i++){
//            for (int j = 0; j < m; j++) {
//                cout<<map[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"-------------\n";
        //윗쪽 공기청정기 작동
        for (int i = a_x - 2; 0 < i; i--) {
            map[i][0] = map[i-1][0];
        }
        for (int i = 0; i < m-1; i++) {
            map[0][i] = map[0][i+1];
        }
        for (int i = 0; i < a_x - 1; i++) {
            map[i][m-1] = map[i+1][m-1];
        }
        for (int i = m - 1; 0 < i; i--) {
            map[a_x - 1][i] = map[a_x - 1][i - 1];
        }

        //아래쪽 공기청정기 작동
        for (int i = a_x + 1; i < n-1; i++) {
            map[i][0] = map[i+1][0];
        }
        for (int i = 0; i < m - 1; i++) {
            map[n-1][i] = map[n-1][i+1];
        }
        for (int i = n - 1; a_x < i; i--) {
            map[i][m - 1] = map[i - 1][m - 1];
        }
        for (int i = m - 1; 0 < i; i--) {
            map[a_x][i] = map[a_x][i-1];
        }

        map[a_x - 1][1] = 0;
        map[a_x][1] = 0;
//        for(int i=0;i<n;i++){
//            for (int j = 0; j < m; j++) {
//                cout<<map[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"-------------\n";
    }
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result += map[i][j];
        }
    }
    cout<<result+2<<"\n";
}