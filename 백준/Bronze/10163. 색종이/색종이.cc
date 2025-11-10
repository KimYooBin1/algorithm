#include<cstring>
#include<iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct B{
    int x, y, X, Y;
};
int main(){
    FIO;
    int n;
    cin>>n;
    int map[102][102];
    memset(map, -1, sizeof(map));
    for (int i = 0; i < n; i++) {
        int a, b, A, B;
        cin >> a >> b >> A >> B;
        for (int a_i = a; a_i < a + A; a_i++) {
            for (int b_i = b; b_i < b + B; b_i++) {
                map[a_i][b_i] = i;
            }
        }
    }
    for (int index = 0; index < n; index++) {
        int result = 0;
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
//                cout<<map[i][j]<<" ";
                if(map[i][j] == index) result++;
            }
//            cout << "\n";
        }
        cout << result << "\n";
    }
}