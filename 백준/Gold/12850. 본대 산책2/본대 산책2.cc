#include<iostream>
#include<cstring>
#include<vector>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100001
#define mod 1000000007
using namespace std;
typedef long long ll;
typedef vector<vector<ll>> mat;
mat A = {
        {0, 1, 1, 0, 0, 0, 0, 0},   //정보과학관
        {1, 0, 1, 1, 0, 0, 0, 0},   //전산관
        {1, 1, 0, 1, 1, 0, 0, 0},   //미래관
        {0, 1, 1, 0, 1, 1, 0, 0},   //상양관
        {0, 0, 1, 1, 0, 1, 1, 0},   //한경직기념관
        {0, 0, 0, 1, 1, 0, 0, 1},   //진리관
        {0, 0, 0, 0, 1, 0, 0, 1},   //형남공학관
        {0, 0, 0, 0, 0, 1, 1, 0}    //학생회관
};
mat result = {
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 1},
};
mat operator*(mat &A, mat &B){
    mat tmp(8, vector<ll>(8));
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            for (int k = 0; k  < 8; k++) {
                tmp[i][j] += (A[i][k] * B[k][j]) % mod;
            }
            tmp[i][j] %= mod;
        }
    }
    return tmp;
}
int main(){
    FIO;
    int n;
    cin >> n;

    while(n){
        if(n&1){
            n--;
            result = result * A;
        }
        A = A * A;
        n /= 2;

    }
    cout << result[0][0] << "\n";
    return 0;
}
