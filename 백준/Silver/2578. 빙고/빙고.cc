#include<cstring>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct P {
    int x, y;
    bool c = false;
};
map<int, P> check;
vector<vector<int>> m(5, vector<int> (5, 0));

int static_result = 0;

int bingo(int x, int y){
    bool check1 = true, check2 = true, check3 = true, check4 = true;
    for (int i = 0; i < 5; i++) {
        if(!check[m[i][i]].c) check1 = false;
        if(!check[m[4 - i][i]].c) check2 = false;
        if(!check[m[i][y]].c) check3 = false;
        if(!check[m[x][i]].c) check4 = false;
    }
    if(check3) static_result++;
    if(check4) static_result++;
    return check1 + check2;
}

int main(){
    FIO;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> m[i][j];
            check[m[i][j]] = {i, j, false};
        }
    }
    int result = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            result++;
            int num;
            cin >> num;
            auto point = check[num];
            check[num] = {point.x, point.y, true};
            int sum = bingo(point.x, point.y) + static_result;
//            cout << num << " " << sum << "\n";
            if (sum >= 3) {
                cout << result << "\n";
                return 0;
            }
        }
    }


}