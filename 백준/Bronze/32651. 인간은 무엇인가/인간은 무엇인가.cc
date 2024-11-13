#include <cstring>
#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(100000 < n || n%2024 != 0) {
        cout << "No\n";
    }else{
        cout << "Yes\n";
    }
    return 0;
}