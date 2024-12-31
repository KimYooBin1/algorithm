#include<cstring>
#include<iostream>
#include<map>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
int main(){
    map<char, int> m;
    FIO;
    int n;
    cin >> n;
    string str;
    cin >> str;
    int result = 0;
    m['S'] = 0;
    m['L'] = 0;
    for (int i = 0; i < n; i++) {
        if(str[i] == 'S'){
            m['S']++;
        }else if(str[i] == 'K'){
            if(m['S'] == 0) break;
            m['S']--;
            result++;
        }else if(str[i] == 'L'){
            m['L']++;
        }else if(str[i] == 'R'){
            if(m['L'] == 0) break;
            m['L']--;
            result++;
        }else {
            result++;
        }
    }
    cout << result << "\n";
}