#include <cstring>
#include <iostream>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 10001
#define mod 1000000007
using namespace std;
typedef long long ll;
ll calc(ll a, ll b){
    ll result = 1;
    while(b){
        if(b&1){
            result *= a;
            result %= mod;
        }
        b>>=1;
        a = a * a;
        a %= mod;
    }
    return result;
}
int main(){
    FIO;
    int m;
    cin >> m;
    int n, t;
    ll result = 0;
    for (int i = 0; i < m; i++) {
        cin >> n >> t;
        result += (t * calc(n, mod-2)) % mod;

    }
    cout << result % mod << "\n";
}