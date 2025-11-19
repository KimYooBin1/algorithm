#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int n;
    cin >> n;
    for(int c = 1; c <= n; c++) {
        vector<vector<int>> v(9, vector<int>(9));
        bool check = true;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cin >> v[i][j];
            }
        }
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> check_num(10, false);
                for (int x = 0; x < 3; x++) {
                    for (int y = 0; y < 3; y++) {
                        int nx = i + x;
                        int ny = j + y;
                        if(check_num[v[nx][ny]]){
                            check = false;
                            break;
                        }
                        check_num[v[nx][ny]] = true;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            vector<bool> check_num(10, false);
            for (int j = 0; j < 9; j++) {
                if(check_num[v[i][j]]){
                    check = false;
                    break;
                }
                check_num[v[i][j]] = true;
            }
        }

        for (int i = 0; i < 9; i++) {
            vector<bool> check_num(10, false);
            for (int j = 0; j < 9; j++) {
                if(check_num[v[j][i]]){
                    check = false;
                    break;
                }
                check_num[v[j][i]] = true;
            }
        }

        cout << "Case " << c << ": " << (check ? "CORRECT\n" : "INCORRECT\n");
    }
}