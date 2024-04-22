#include<cstring>
#include<iostream>
#include<map>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;

int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    map<string, string> pw;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        pw[s1] = s2;
    }
    for (int i = 0; i < m; i++) {
        string s;
        cin>>s;
        cout<<pw[s]<<"\n";
    }
}