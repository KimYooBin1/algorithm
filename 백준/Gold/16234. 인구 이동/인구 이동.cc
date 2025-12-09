#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<cmath>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int main(){
    FIO;
    int N,L,R;
    cin>>N>>L>>R;
    vector<vector<int>> people(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> people[i][j];
        }
    }
    int result = 0;
    while(true){
        bool check = true;
        int index = 1;
        vector<vector<int>> u(N, vector<int>(N, 0));
        map<int, int> u_size;
        map<int, int> u_sum;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if(u[i][j]) continue;
                u[i][j] = index;
                u_size[index] = 1;
                u_sum[index] = people[i][j];
                index++;
                queue<pair<int,int>> q;
                q.push({i, j});
                while(!q.empty()){
                    int x, y;
                    tie(x, y) = q.front(); q.pop();
                    for (int z = 0; z < 4; z++) {
                        int nx = x + dx[z];
                        int ny = y + dy[z];
                        if(nx < 0 || N <= nx || ny < 0 || N <= ny) continue;
                        if(u[nx][ny]) continue;
                        if(abs(people[x][y] - people[nx][ny]) < L || abs(people[x][y] - people[nx][ny]) > R) continue;
                        u[nx][ny] = u[x][y];
                        q.push({nx, ny});
                        u_size[u[nx][ny]]++;
                        u_sum[u[nx][ny]] += people[nx][ny];

                        check = false;
                    }
                }
            }
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                people[i][j] = u_sum[u[i][j]] / u_size[u[i][j]];
            }
        }
        if(check) break;
        result++;
    }
    cout << result << "\n";
}