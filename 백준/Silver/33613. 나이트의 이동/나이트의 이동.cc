#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef long long ll;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    ll n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    if(n == 3 && x == 2 && y == 2){
        cout << 1 << "\n";
        return 0;
    }
    if(n == 3 && (x + y)%2 == 0){
        cout << 4 << "\n";
        return 0;
    }
    ll result;
    // 홀수
    if((x + y) % 2){
        result = n * n / 2;
    }
    // 짝수
    else{
        result = n * n / 2 + (n % 2 ? 1 : 0);
    }
    cout << result << "\n";
}