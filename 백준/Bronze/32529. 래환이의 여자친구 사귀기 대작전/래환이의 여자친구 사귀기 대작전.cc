#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int num;
        cin>>num;
        v.push_back(num);
    }
    reverse(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < v.size(); i++) {
        sum += v[i];
        if(m <= sum){
            cout << n << "\n";
            return 0;
        }
        n--;
    }
    cout << -1 << "\n";
    return 0;
}