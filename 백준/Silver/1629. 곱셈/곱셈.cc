#include <iostream>
#include <cstring>
#include <vector>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main()
{
    FIO;
    ll A, B, C;
    cin >> A >> B >> C;
    ll result = 1;
    while (B) {
        if (B % 2 == 1) {
            result *= A;
            result %= C;
        }
        A *= A;
        A %= C;
        B /= 2;
    }
    cout << result % C << "\n";
    return 0;
}