#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main(){
    FIO;
//    vector<int> map[101][101];
    bool check[101][101];
    memset(check, false, sizeof(check));
    int result = 0;
    for (int i = 0; i < 4; i++) {
        int x, y, X, Y;
        cin >> x >> y >> X >> Y;
        for (int n = x; n < X; n++) {
            for (int m = y; m < Y; m++) {
                if(check[n][m]) continue;
                result++;
                check[n][m] = true;
            }
        }
    }
    cout << result << "\n";
}