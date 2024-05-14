#include<iostream>
#include<cstring>
#include<map>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    map<string, string> hashmap;
    for (int i = 0; i < n; i++) {
        string str1, str2;
        cin >> str1 >> str2;
        hashmap[str1] = str2;
    }
    for (int i = 0; i < m; i++) {
        string tmp;
        cin >> tmp;
        string result = "";
        for (int j = 0; j < tmp.length(); j++) {    //시작지점
            string str = "";
            for (int z = j; z < tmp.length(); z++) {
                str += tmp[z];
                if(hashmap.find(str) != hashmap.end()) result += hashmap[str];
            }
        }
        if(result.empty()) cout<<-1<<"\n";
        else cout<<result<<"\n";
    }
}