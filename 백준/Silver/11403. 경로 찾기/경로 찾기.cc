#include<cstring>
#include<iostream>
#include<map>
#include<set>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;

int main(){
    FIO;
    int n;
    cin>>n;
    int map[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin>>map[i][j];
        }
    }
    for (int z = 0; z < n; z++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(map[i][j] == 1) continue;
                if(map[i][z] == 1 && map[z][j] == 1) map[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<map[i][j]<<" ";
        }
        cout << "\n";
    }
}