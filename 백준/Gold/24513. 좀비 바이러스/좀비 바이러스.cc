#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
int main(){
    FIO;
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> dist(n, std::vector<int> (m, -1));
    std::vector<std::vector<int>> virus(n, std::vector<int> (m, 0));
    std::vector<std::vector<int>> map(n, std::vector<int> (m));
    std::queue<std::pair<int,int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin>>map[i][j];
            if(map[i][j] == 1){
                q.push(std::make_pair(i, j));
                dist[i][j] = 0;
                virus[i][j] = 1;
            }else if(map[i][j] == 2){
                q.push(std::make_pair(i, j));
                dist[i][j] = 0;
                virus[i][j] = 2;
            }
        }
    }
    int x, y;
    int dx[4] = {0, 0, -1, 1};
    int dy[4] = {-1, 1, 0, 0};
    int result = 0;
    while (!q.empty()) {
        std::tie(x, y) = q.front(); q.pop();
        if(virus[x][y] == 3) continue;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
            if(dist[nx][ny] == dist[x][y] || virus[nx][ny] == 3) continue;
            if(map[nx][ny] == -1) continue;
            if(dist[nx][ny] == dist[x][y] + 1){
                if(virus[nx][ny] != virus[x][y]){
                    virus[nx][ny] = 3;
                }
            }else if(dist[nx][ny] == -1){
                virus[nx][ny] = virus[x][y];
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    int A_count = 0, B_count = 0, C_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(virus[i][j] == 1){
                A_count++;
            }else if(virus[i][j] == 2){
                B_count++;
            }else if(virus[i][j] == 3){
                C_count++;
            }
//            std::cout<<virus[i][j]<<" ";
        }
//        std::cout << "\n";
    }
    std::cout << A_count << " " << B_count << " " << C_count << "\n";
    return 0;
}