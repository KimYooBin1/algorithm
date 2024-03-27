#include <cstring>
#include <iostream>

#define MAX_SIZE 65
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int mapA[MAX_SIZE][MAX_SIZE];       //A규칙
int mapB[MAX_SIZE][MAX_SIZE];       //B규칙
int dist[MAX_SIZE][MAX_SIZE][4];    //해당 dir로 좌표까지의 청소량
int cnt[MAX_SIZE][MAX_SIZE][4];     //해당 dir로 좌표까지의 이동거리
int map[MAX_SIZE][MAX_SIZE];        //해당 좌표를 청소했는지
int l_len = 0;
int n, m;
// s,e : 시작위치, dir:방향, len:이동거리, dump:치운 쓰레기
int dfs(int s, int e, int dir, int len, int dump) {
//    cout<<s<<" "<<e<<" "<<dist[s][e][dir]<<" "<<dump<<" "<<len<<"\n";
    //해당 방향으로 접근한적 있는지?
    // 이미 dist[s][e][dir] 에 걸리고 len 가 길이가 동일하면 치운것이 없이 원래 자리로 복귀한것, 즉 무한루프
    if(dist[s][e][dir] != -1 && dist[s][e][dir] == dump) return cnt[s][e][dir];
    int n_dir;
    if(map[s][e] == 0){
        map[s][e] = -1;
        dist[s][e][dir] = dump++;
        n_dir = (mapA[s][e] + dir) % 4;
        l_len = len+1;
    }
    else{
        n_dir = (mapB[s][e] + dir) % 4;
        dist[s][e][dir] = dump;
    }
    int nx = s + dx[n_dir];
    int ny = e + dy[n_dir];
    if(nx<0 || n<=nx || ny<0 || m<=ny) {
        return l_len;
    }
    cnt[s][e][dir] = len;
    return dfs(nx, ny, n_dir, len + 1, dump);
}

int main(){
    FIO;
    cin >> n >> m;
    int r, h, d;
    cin >> r >> h >> d;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            mapA[i][j] = s[j] - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            mapB[i][j] = s[j] - '0';
        }
    }
    memset(dist, -1, sizeof dist);
    int result = dfs(r, h, d, 0, 0);
    cout << result << "\n";
    return 0;
}