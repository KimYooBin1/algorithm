#include<cstring>
#include<iostream>
#include<queue>
#include<tuple>
#include<vector>
#include<algorithm>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 101
using namespace std;
int map[MAX_SIZE][MAX_SIZE];
int dist[MAX_SIZE][MAX_SIZE];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(){
    FIO;
    int n, m, k;
    cin >> m >> n >> k;
    int x1, x2, y1, y2;
    for (int i = 0; i < k; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                map[x][y] = 1;
            }
        }
    }
//    for (int i = 0; i < n; i++) {
//        for (int j = 0; j < m; j++) {
//            cout<<map[i][j]<<" ";
//        }
//        cout << "\n";
//    }
    memset(dist, -1, sizeof(dist));
    queue<pair<int,int>> q;
    vector<int> result;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(map[i][j] == 1) continue;
            if(dist[i][j] != -1) continue;
            q.push({i, j});
            dist[i][j] = 1;
            int size = 1;
            while(!q.empty()){
                int x, y;
                tie(x, y) = q.front(); q.pop();
//                cout << x << " " << y << "\n";
                for (int z = 0; z < 4; z++) {
                    int nx = x + dx[z];
                    int ny = y + dy[z];
                    if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
                    if(dist[nx][ny] != -1) continue;
                    if(map[nx][ny] == 1) continue;
                    q.push({nx, ny});
                    dist[nx][ny] = dist[x][y];
                    size++;
                }
            }
//            cout << size << "\n";
            result.push_back(size);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << "\n";
    for(auto &a : result){
        cout << a << " ";
    }
    cout << "\n";
    return 0;
}