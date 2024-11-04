#include <cstring>
#include <iostream>
using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b) {
        if(a == -1 && b == -1) break;
        int result = 1;
        int num = a + b;
        for (int i = 1; i <= a; i++) {
            result *= num;
            num--;
        }
        for (int i = 1; i <= a; i++) {
            result/=i;
        }
        string str = (result == a+b) ? "=" : "!=";
        cout << a << "+" << b << str << a + b << "\n";
    }
    return 0;
}