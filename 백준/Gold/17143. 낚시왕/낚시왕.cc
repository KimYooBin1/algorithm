#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 10001
using namespace std;
struct info{
    int x, y, speed, dir, size;
    bool dead = false;
};
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
info shark[MAX_SIZE];
vector<vector<int>> map(101, vector<int>(101));

int r, c, m;
int hunt(int x){
    int size = 0;
//    for (int i = 1; i <= r; i++) {
//        for (int j = 1; j <= c; j++) {
//            cout<<map[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
//    cout<<"\n";
    for (int i = 1; i <= r; i++) {
        //상어가 없음
        if(!map[i][x]) continue;
        size += shark[map[i][x]].size;
        shark[map[i][x]].dead = true;
        break;
    }

    return size;
}

void shark_move(){
    vector<vector<int>> tmp_map(101, vector<int>(101, 0));

    for (int i = 1; i <= m; i++) {
        info& tmp = shark[i];
        if(tmp.dead) continue;
//        cout << i << " " << shark[i].x << " " << shark[i].y << " " << shark[i].speed << " " << shark[i].dir << "\n";
        int nx = tmp.x + dx[tmp.dir] * tmp.speed;
        int ny = tmp.y + dy[tmp.dir] * tmp.speed;
        int speed = tmp.speed;
        while (nx <= 0 || r < nx) {
            if (nx <= 0) {
                nx = -nx + 2;
                tmp.dir = 1 - tmp.dir;
                tmp.x = 0;
                speed = abs(nx);
            } else if (r < nx) {
                nx = 2*r - tmp.x - dx[tmp.dir] * speed;
                tmp.dir = 1 - tmp.dir;
            }
        }
        while(ny <= 0|| c < ny){
            if (ny <= 0) {
                ny = -ny + 2;
                tmp.dir = 5 - tmp.dir;
                tmp.y = 0;
                speed = abs(ny);
            } else if (c < ny) {
                ny = 2*c - tmp.y - dy[tmp.dir] * speed;
                tmp.dir = 5 - tmp.dir;
            }
        }
//        cout << nx << " " << ny << "\n";
        tmp.x = nx;
        tmp.y = ny;
        //해당 칸에 이미 상어가 있다
        if(tmp_map[nx][ny] != 0){
            //내가 더커
            if(shark[tmp_map[nx][ny]].size < tmp.size){
                shark[tmp_map[nx][ny]].dead = true;
                tmp_map[nx][ny] = i;
            }
            //상대가 더커
            else{
                tmp.dead = true;
            }
        }
        else{
            tmp_map[nx][ny] = i;
        }
    }
    map = tmp_map;
}

int main(){
    FIO;
    //격자 크기, 상어의 개수
    cin >> r >> c >> m;
    //속력, 이동방향, 크기
    int x, y, s, d, z;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> s >> d >> z;
        shark[i] = {x, y, s, d-1, z};
        map[x][y] = i;
    }
    int position = 0;
    int result = 0;
    while (position != c + 1) {
        position++;
        result += hunt(position);
        shark_move();
    }
    cout << result << "\n";
    return 0;
}
