#include<cstring>
#include<iostream>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
using namespace std;

int main(){
    FIO;
    int n;
    cin >> n;
    cout << n * 78 / 100 << " " << (n * 2 / 10) * 78 / 100 + n * 8 / 10;
    return 0;
}
