#include<iostream>
#include<cstring>
#include<tuple>
#include<vector>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 10001
using namespace std;
int cross1[MAX_SIZE];
int cross2[MAX_SIZE];
bool check[101][101];
int n;
int arr[102][102];
int result[2];
vector<vector<pair<int,int>>> v(2, vector<pair<int,int>>());
void calc(int color, int x, int cnt){
    int nx, ny;
    for (int i = x+1; i < v[color].size(); i++) {
        tie(nx, ny) = v[color][i];
//        cout << nx << " " << ny << "\n";
        if(check[nx][ny] || cross1[nx+ny] || cross2[-(ny-nx) + (n-1)]) continue;
        check[nx][ny] = true;
        cross1[nx+ny] = true;
        cross2[-(ny-nx) + (n-1)] = true;

        calc(color, i, cnt+1);

        check[nx][ny] = false;
        cross1[nx+ny] = false;
        cross2[-(ny-nx) + (n-1)] = false;
    }
    result[color] = max(result[color], cnt);
}
int main(){
    FIO;
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if(arr[i][j] == 1){
                v[(i+j)%2].push_back({i, j});
            }
        }
    }
    calc(0, -1, 0);
    calc(1, -1, 0);
    cout << result[0] + result[1]<< "\n";
    return 0;
}
