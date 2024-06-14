#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <tuple>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(){
    FIO;
    // test case 개수
    int t;
    cin >> t;
    while (t--) {
        //현재 가지고 있는 key종류
        map<char, bool> key;
        //찾은 문
        map<char, queue<pair<int,int>>> door;
        int n, m;
        cin >> n >> m;
        char M[n + 2][m + 2];
        bool check[n + 2][m + 2];
        for (int i = 0; i <= n + 1; i++) {
            M[i][0] = '.';
            M[i][m+1] = '.';
        }
        for (int i = 0; i <= m + 1; i++) {
            M[0][i] = '.';
            M[n+1][i] = '.';
        }
        memset(check, false, sizeof(check));
        string str;
        for (int i = 1; i <= n; i++) {
            cin>>str;
            for (int j = 1; j <= m; j++) {
                M[i][j] = str[j-1];
            }
        }
        cin>>str;
        for (int i = 0; i < str.length(); i++) {
            key[str[i]] = true;
        }
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        check[0][0] = true;
        int x, y;
        int result = 0;
        while (!q.empty()) {
            tie(x, y) = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                char room = M[nx][ny];

                if (nx < 0 || n + 2 <= nx || ny < 0 || m + 2 <= ny) continue;
                if (check[nx][ny]) continue;
                if(room == '*') continue;

                else if(room == '$') {
                    result++;
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                    M[nx][ny] = '.';
                }
                //키를 주웠다
                else if ('a' <= room && room <= 'z') {
//                    cout<<room<<nx<<ny<<"\n";
                    //해당 키의 문을 가지고 있다
                    if (door.find(room - 32) != door.end()) {
                        while(!door[room-32].empty()){
                            auto door_room = door[room - 32].front();
                            door[room - 32].pop();
                            int d_x = door_room.first;
                            int d_y = door_room.second;
                            //해당 문을 이미 지났을 경우
                            if(check[d_x][d_y]) continue;
                            q.push(make_pair(d_x, d_y));
                            check[d_x][d_y] = true;
                            M[d_x][d_y] = '.';
                        }
                    }
                    key[room] = true;
                    q.push(make_pair(nx, ny));
                    check[nx][ny] = true;
                }
                //문을 찾았다
                else if ('A' <= room && room <= 'Z') {
//                    cout<<room<<nx<<ny<<"\n";
                    // key를 가지고 있으면
                    if(key[room + 32]){
                        q.push(make_pair(nx, ny));
                        check[nx][ny] = true;
                        M[nx][ny] = '.';
                    }
                    // key가 없으면
                    else{
                        door[room].push({nx, ny});
                    }
                }
                //그냥 평범하게 지나갈수있는방
                else {
                    check[nx][ny] = true;
                    q.push(make_pair(nx, ny));
                }
            }
        }
        cout << result << "\n";
//        for (int i = 0; i <= n + 1; i++) {
//            for (int j = 0; j <= m + 1; j++) {
//                cout << check[i][j];
//            }
//            cout << "\n";
//        }
//        cout << "\n";
//        for (int i = 0; i <= n + 1; i++) {
//            for (int j = 0; j <= m + 1; j++) {
//                cout << M[i][j];
//            }
//            cout << "\n";
//        }
    }
    return 0;
}