#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if(n == 1) {
        cout << 0 << "\n";
        return 0;
    }

    int tmp = n*n;
    if(tmp&1){
        cout << tmp / 2 + 1  << "\n";
    }else{
        cout << tmp / 2 << "\n";
    }
}