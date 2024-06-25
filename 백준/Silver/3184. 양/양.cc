#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 251
using namespace std;
int dx[4] = {0, 0, -1 , 1};
int dy[4] = {-1, 1, 0, 0};
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int v_size[MAX_SIZE * MAX_SIZE];
int k_size[MAX_SIZE * MAX_SIZE];
int main(){
    FIO;
    int r, c;
    cin >> r >> c;
    string str;
    for (int i = 0; i < r; i++) {
        cin>>str;
        for (int j = 0; j < c; j++) {
            map[i][j] = str[j];
        }
    }
    memset(dist, -1, sizeof(dist));
    int g = 1;
    queue<pair<int,int>> q;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(map[i][j] == '#') continue;
            if(dist[i][j] != -1) continue;
            dist[i][j] = g++;
            q.push({i, j});
            while(!q.empty()){
                int x, y;
                tie(x, y) = q.front(); q.pop();
                if(map[x][y] == 'v'){
                    v_size[dist[x][y]]++;
                }else if(map[x][y] == 'o'){
                    k_size[dist[x][y]]++;
                }
                for (int z = 0; z < 4; z++) {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if(dist[nx][ny] != -1) continue;
                    if(map[nx][ny] == '#') continue;
                    if(nx < 0 || r <= nx || ny < 0 || c <= ny) continue;
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y];
                }
            }
        }
    }
    int result_v = 0;
    int result_k = 0;

    for (int i = 1; i < g; i++) {
        //늑대가 더 적은
        if(v_size[i] < k_size[i]){
            result_k += k_size[i];
        }else{
            result_v += v_size[i];
        }
    }
    cout << result_k << " " << result_v << "\n";
    return 0;
}