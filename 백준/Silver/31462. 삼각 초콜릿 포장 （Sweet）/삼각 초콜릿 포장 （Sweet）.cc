#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int n;

bool check_range(int x, int y){
    if(x <= 0 || n < x || y <= 0 || n < y) return false;
    return true;
}

int main(){
    FIO;
    cin >> n;
    vector<vector<int>> c(n + 1, vector<int>(n + 1));
//    vector<vector<bool>> check(n + 1, vector<bool>(n + 1, false));
    bool check[n + 1][n + 1];
    memset(check, false, sizeof(check));
    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;
        for (int j = 1; j <= i; j++) {
            c[i][j] = str[j - 1];
        }
    }

    if (((n * (n + 1)) / 2) % 3) {
        cout<<0<<"\n";
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if(check[i][j]) continue;
//            cout << i << " " << j << "\n";
            if(c[i][j] == 'R'){
                if(!check_range(i + 1,j) || !check_range(i + 1, j + 1)){
                    cout << 0 << "\n";
                    return 0;
                }
                if(check[i + 1][j] || check[i + 1][j + 1]){
                    cout << 0 << "\n";
                    return 0;
                }
                if(c[i + 1][j] != 'R' || c[i + 1][j + 1] != 'R'){
                    cout << 0 << "\n";
                    return 0;
                }
                check[i][j] = check[i + 1][j] = check[i + 1][j + 1] = true;
            }else{
                if(!check_range(i + 1,j + 1) || !check_range(i, j + 1)){
                    cout << 0 << "\n";
                    return 0;
                }
                if(check[i + 1][j + 1] || check[i][j + 1]){
                    cout << 0 << "\n";
                    return 0;
                }
                if(c[i + 1][j + 1] != 'B' || c[i][j + 1] != 'B'){
                    cout << 0 << "\n";
                    return 0;
                }
                check[i][j] = check[i + 1][j + 1] = check[i][j + 1] = true;
            }
        }
    }
    cout << 1 << "\n";
}