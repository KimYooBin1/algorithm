#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct ad {
    int cost;
    int customer;
};
int main() {
    FIO;
    int c, n;
    cin >> c >> n;
    vector<ad> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].cost >> v[i].customer;
    }
    vector<int> dp(c + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < c; i++) {
        if(dp[i] == -1) continue;
        for (int j = 0; j < n; j++) {
            int index = i + v[j].customer;
            if(index > c) index = c;
            if (dp[index] == -1 || dp[index] > dp[i] + v[j].cost)
                dp[index] = dp[i] + v[j].cost;

        }
    }
//    for(auto a : dp){
//        cout<<a<<" ";
//    }
//    cout << "\n";
    cout << dp[c] << "\n";
};
