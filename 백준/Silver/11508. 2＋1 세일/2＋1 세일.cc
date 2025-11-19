#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int result = 0;
    for (int i = 0; i < n; i++) {
        if((i + 1) % 3 == 0) continue;
        result += v[i];
    }
    cout << result << "\n";
}