#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int n;
    cin >> n;
    vector<int> v(n * 3);
    for (int i = 0; i < n * 3; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    cout << v[2 * n - 1] - v[n] << "\n";
}