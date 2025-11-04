#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct d {
    int dir;
    int length;
};
int role[4][2] = {{3, 2}, {2, 4}, {1, 3}, {4, 1}};
//int max_role[4][2] = {{2, 3}, {3, 1}, {1, 4}, {4, 2}};
int main(){
    FIO;
    int n;
    cin>>n;
    vector<d> v(7);
    for (int i = 0; i < 6; i++) {
        cin >> v[i].dir >> v[i].length;
    }
    v[6].dir = v[0].dir;
    v[6].length = v[0].length;
    int result = 0;
    int sum = 0;
    for (int i = 1; i <= 6; i++) {
        for (auto & j : role) {
            if (v[i - 1].dir == j[0] && v[i].dir == j[1]) {
                sum = v[i - 1].length * v[i].length;
                break;
            }
        }
        result = max(result, v[i - 1].length * v[i].length);
    }
    cout << (result - sum) * n << "\n";
}