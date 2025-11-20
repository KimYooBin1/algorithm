#include <cstring>
#include <iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    string str;
    cin >> str;
    int num = 0;
    int i = 0;
    int tmp;
    for(auto & c : str) {
        if(c == '*'){
            tmp = (i % 2 ? 3 : 1);
            i++;
            continue;
        }
        num += (c - '0') * (i % 2 ? 3 : 1);
        i++;
    }
//    cout << num << "\n";
    for (int j = 0; j < 10; j++) {
        if((num + j * tmp) % 10) continue;
        cout<<j<<"\n";
        return 0;
    }
};
