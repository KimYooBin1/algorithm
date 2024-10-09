#include <iostream>
#include <cstring>
#include <vector>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
using namespace std;

typedef long long ll;
typedef vector<vector<ll>> mat;

ll N, M;
mat calc(mat &a, mat &b) {
    mat result(M, vector<ll>(M, 0));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            for (int z = 0; z < M; z++) {
//                cout << a[i][z] << " " << b[z][j] << "\n";
                result[i][j] = (result[i][j] + a[i][z] * b[z][j]) % MOD;
            }
        }
    }
    return result;
}

int main()
{
    FIO;
    cin >> N >> M;
    mat I = vector<vector<ll>> (M, vector<ll> (M, 0));
    I[0][0] = I[0][M - 1] = 1;
    for (int i = 1; i < M; i++) {
        I[i][i - 1] = 1;
    }
    mat v(M, vector<ll> (M, 0));
    for (int i = 0; i < M; i++) {
        v[i][i] = 1;
    }
    while (N) {
        if (N & 1) {
            v = calc(v, I);
        }
        I = calc(I, I);
        N /= 2;
//        for (int i = 0; i < v.size(); i++) {
//            for (int j = 0; j < v[i].size(); j++) {
//                cout<<I[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"------------\n";
//        for (int i = 0; i < v.size(); i++) {
//            for (int j = 0; j < v[i].size(); j++) {
//                cout<<v[i][j]<<" ";
//            }
//            cout<<"\n";
//        }
//        cout<<"\n";

    }
    cout << v[0][0] << "\n";
    return 0;
}