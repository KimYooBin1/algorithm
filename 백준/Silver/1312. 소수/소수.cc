#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int a, b, n;
    cin >> a >> b >> n;
    if(!(a % b)){
        cout << 0 << "\n";
        return 0;
    }
    int tmp_num = a % b;
    int result = 0;
    for (int i = 0; i < n; i++) {
        result = tmp_num * 10 / b;
        tmp_num = tmp_num * 10 % b;
//        cout << tmp_num << "\n";
    }
    cout << result << "\n";
}