#include <cstring>
#include <iostream>
#include <vector>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int map[9][9];
bool row[10][10];
bool column[10][10];
bool group[10][10];
bool calc(int cnt){
    if(cnt == 0){
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout<<map[i][j];
            }
            cout<<"\n";
        }
        return true;
    }
//    cout<<cnt<<"\n";
//    for (int i = 0; i < 9; i++) {
//        for (int j = 0; j < 9; j++) {
//            cout<<map[i][j];
//        }
//        cout<<"\n";
//    }
//    cout<<"\n";
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(map[i][j] != 0) continue;
            int g = 3 * (i/3) + j/3;
            for (int num = 1; num < 10; num++) {
                if(row[i][num] || column[j][num] || group[g][num]) continue;
                map[i][j] = num;
                row[i][num] = true;
                column[j][num] = true;
                group[g][num] = true;
                if(calc(cnt-1)) return true;
                map[i][j] = 0;
                row[i][num] = false;
                column[j][num] = false;
                group[g][num] = false;
            }
            if(!map[i][j]) return false;
        }
    }
    return false;
}
int main(){
    FIO;
    string input;
    //비어있는 공간의 개수
    int cnt = 0;
    for (int i = 0; i < 9; i++) {
        cin>>input;
        for (int j = 0; j < 9; j++) {
            map[i][j] = input[j]-'0';
            if(map[i][j] != 0){
                cnt++;
                int g = 3 * (i/3) + j/3;
                row[i][map[i][j]] = true;
                column[j][map[i][j]] = true;
                group[g][map[i][j]] = true;
            }
        }
    }
    cnt = 81-cnt;
    calc(cnt);
}