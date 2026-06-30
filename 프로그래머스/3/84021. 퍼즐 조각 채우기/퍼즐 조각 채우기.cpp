#include <string>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

//map : 맵, check : 빈공간을 찾을지 0, 큐브를 찾을지 1
vector<vector<pair<int,int>>> bfs(const vector<vector<int>> &map, int c){
    int n = map.size();
    int m = map[0].size();
    
    vector<vector<pair<int,int>>> result;
    
    vector<vector<bool>> check(n, vector<bool> (m, false));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            vector<pair<int,int>> temp;
            if(map[i][j] != c) continue;
            if(check[i][j]) continue;
            check[i][j] = true;
            queue<pair<int,int>> q;
            q.push({i, j});
            temp.push_back({i, j});
            while(!q.empty()){
                int x, y;
                tie(x, y) = q.front(); q.pop();
                for(int i = 0; i < 4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || n <= nx || ny < 0 || m <= ny) continue;
                    if(map[nx][ny] != c) continue;
                    if(check[nx][ny]) continue;
                    q.push({nx, ny});
                    check[nx][ny] = true;
                    temp.push_back({nx, ny});
                }
            }
            result.push_back(temp);
        }
    }
    return result;
}

vector<vector<vector<pair<int,int>>>> rotate(const vector<vector<pair<int,int>>> &shapes){
    int size = shapes.size();
    vector<vector<vector<pair<int,int>>>> result (size, vector<vector<pair<int,int>>> (4, vector<pair<int,int>> ()));
    for(int i = 0;i<size;i++){
        // 기존 좌표는 0번 인덱스에 등록
        result[i][0] = shapes[i];
        for(int j=1;j<4;j++){
            for(auto [x, y]: result[i][j-1]) result[i][j].push_back({y, -x});
        }
    }
        
    return result;
}

bool fit(const vector<pair<int,int>> & empty, const vector<vector<pair<int,int>>> & full){
    int size1 = empty.size();
    int size2 = full[0].size();
    if(size1 != size2) return false;
    for(int j=0;j<4;j++){
        if(full[j] == empty) return true;
    }
    return false;
}

void normalization(vector<pair<int,int>> &v){
    int mx = INT_MAX/2;
    int my = INT_MAX/2;
    int size1 = v.size();
    for(int z=0;z<size1; z++){
        mx = min(mx, v[z].first);
        my = min(my, v[z].second);
    }
    for(int z=0;z<size1; z++){
        v[z].first -= mx;
        v[z].second -= my;

        // cout<<v[i][j][z].first<<" "<<v[i][j][z].second<<" | ";
    }
    sort(v.begin(), v.end());
    // cout<<"\n";
    
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    vector<vector<pair<int,int>>> empty = bfs(game_board, 0);
    vector<vector<pair<int,int>>> full = bfs(table, 1);
    
    vector<vector<vector<pair<int,int>>>> rotation_full = rotate(full);

    
    for(int i=0;i<rotation_full.size();i++){
        for(int z=0;z<4;z++){
        normalization(rotation_full[i][z]);   
        }
    }
    for(int i=0;i<empty.size();i++){
        normalization(empty[i]);    
    }
    
    
    vector<bool> check(rotation_full.size(), false);
    int result = 0;
    for(int i=0;i<empty.size();i++){
        for(int j=0;j<rotation_full.size();j++){
            if(check[j]) continue;
            if(fit(empty[i], rotation_full[j])){
                check[j] = true;
                // cout<<i<<" "<<j<<"fit\n";
                result += rotation_full[j][0].size();
                break;
            }
        }
    }
    return result;
}