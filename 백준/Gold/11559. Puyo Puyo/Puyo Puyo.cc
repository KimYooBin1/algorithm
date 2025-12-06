#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void drop(vector<vector<char>> &m) {
    bool check = true;
    while(check){
        check = false;
        for (int i = 10; i >= 0; i--) {
            for (int j = 0; j < 6; j++) {
                if(m[i][j] == '.') continue;
                if (m[i + 1][j] != '.') continue;
                swap(m[i][j], m[i + 1][j]);
                check = true;
            }
        }
    }
//    for(auto & a : m){
//        for (auto &b: a) {
//            cout<<b<<" ";
//        }
//        cout << "\n";
//    }
}

int main(){
    FIO;
    vector<vector<char>> puyo(12, vector<char>(6));
    for (int i = 0; i < 12; i++) {
        string str;
        cin>>str;
        for (int j = 0; j < str.length(); j++) {
            puyo[i][j] = str[j];
        }
    }
    int result = 0;
    while(true){
        bool check = true;
        bool check_dist[12][6];
        memset(check_dist, true, sizeof(check_dist));
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if(!check_dist[i][j]) continue;
                if(puyo[i][j] == '.') continue;
//                cout << i << " " << j << "\n";
                queue<tuple<int,int,char>> q;
                q.push({i, j, puyo[i][j]});
                check_dist[i][j] = false;
                vector<pair<int,int>> tmp_store;
                tmp_store.push_back({i, j});
                while (!q.empty()) {
                    int x, y; char c;
                    tie(x, y, c) = q.front(); q.pop();
//                    cout << x << " " << y << " " << c << "\n";
                    for (int z = 0; z < 4; z++) {
                        int nx = x + dx[z];
                        int ny = y + dy[z];
                        if (nx < 0 || 12 <= nx || ny < 0 || 6 <= ny) continue;
                        if(puyo[nx][ny] != c) continue;
                        if(!check_dist[nx][ny]) continue;
                        check_dist[nx][ny] = false;
                        tmp_store.push_back({nx, ny});
                        q.push({nx, ny, c});
                    }
                }
//                cout << tmp_store.size() << "\n";
                if(tmp_store.size() >= 4){
                    check = false;
                    for(auto &p: tmp_store){
                        puyo[p.first][p.second] = '.';
                    }
                }
                tmp_store.clear();
            }
        }
        if(check) break;
        result++;
        drop(puyo);
    }
    cout << result << "\n";
}