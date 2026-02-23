#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<set>
using namespace std;

int n;
vector<set<int>> v(101);
bool calc(int i, vector<bool> &c) {
    // cout << i << "\n";

    if (i == n - 1) return true;
    for (auto &a : v[i]) {
        if (c[a]) return false;
        c[a] = true;
        if (!calc(a, c)) return false;
        c[a] = false;
    }
    return true;
}

int main() {
    cin>>n;
    vector<bool> check(n, false);
    for (int i = 0; i < n - 1; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int num;
            cin >> num;
            v[i].insert(--num);
        }
    }
    check[0] = true;
    if (calc(0, check)) {
        cout<<"NO CYCLE\n";
    }else{
        cout<<"CYCLE\n";
    }
}