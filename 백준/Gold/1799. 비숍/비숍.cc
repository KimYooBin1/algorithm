#include<iostream>
#include<cstring>
#include<cmath>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 10001
using namespace std;
bool cross1[MAX_SIZE];
bool cross2[MAX_SIZE];
int n;
int arr[102][102];
int calc(int x, int y, int cnt){
    if(n <= y){
        //홀수
        if(n%2){
            y -= n;
        }
        //짝수
        else{
            y = abs(n+1-y);
        }
        x++;
        if(x == n) return cnt;
    }
    //true : 더이상 추가할 수 없을떄, false : 아직 칸이 남아있다
    bool check1 = true;
    bool check2 = true;
    for(int i=0;i<2*n-1;i++){
        if(!cross1[i]) check1 = false;
        if(!cross2[i]) check2 = false;
    }
    if(check1 || check2) return 0;
//    cout << x << " " << y << "\n";
    if(arr[x][y] == 0 || cross1[x+y] || cross2[-(x-y)+(n-1)]) return calc(x, y+2, cnt);
    //현재 위치를 선택
    cross1[x+y] = true;
    cross2[-(x-y)+(n-1)] = true;
    int result1 = calc(x, y+2, cnt+1);
    cross1[x+y] = false;
    cross2[-(x-y)+(n-1)] = false;

    int result2 = calc(x, y+2, cnt);

    return max(result1, result2);
}
int main(){
    FIO;
    cin>>n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    int result = calc(0, 0, 0);
    int result1 = calc(0, 1, 0);
//    cout << result << " " << result1 << "\n";
    cout << result + result1 << "\n";
    return 0;
}
