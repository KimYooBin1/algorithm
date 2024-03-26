#include <cstring>
#include <iostream>
#include <vector>

#define MAX_SIZE 16
#define mod 1000000003
#define FIO cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(false);

using namespace std;

int main() {
    FIO;
    long long n;
    cin >> n;
    long long sum = 3 * n + n;
    cout << sum << "\n";
    return 0;

}