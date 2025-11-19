#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    string str;
    cin >> str;
//    str += str[str.length() - 1];
    vector<int> v(2, 0);
    for (int i = 1; i < str.length(); i++) {
        if(str[i - 1] == str[i]) continue;
        v[str[i - 1] - '0']++;
    }
    v[str[str.length() - 1] - '0']++;
    cout << min(v[0], v[1]) << "\n";
}