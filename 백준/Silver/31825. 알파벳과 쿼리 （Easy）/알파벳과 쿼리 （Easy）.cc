#include<iostream>
#include<cstring>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    string str;
    cin >> str;
    for (int i = 0; i < m; i++) {
        int o, s, e;
        cin >> o >> s >> e;
        s--; e--;
        if(o == 1){ //집합 개수
            int cnt = 1;
            char alp = str[s];
            for (int j = s+1; j <= e; j++) {
                if(str[j] == alp) continue;
                cnt++;
                alp = str[j];
            }
            cout<<cnt<<"\n";
        }
        else{   //알파벳 변경
            for (int j = s; j <= e; j++) {
                if(str[j] == 'Z') str[j] = 'A';
                else str[j] = str[j] + 1;
            }
        }
    }
}