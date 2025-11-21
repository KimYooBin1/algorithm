#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int main() {
    FIO;
    int n, k;
    cin >> n >> k;
    vector<int> feed(n);
    for (int i = 0; i < n; i++) {
        cin >> feed[i];
    }
    vector<int> next_i(n, -1);
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += feed[j];
            if(k <= sum){
                next_i[i] = j;
                break;
            }
        }
//        if(next_i[i] == -1) next_i[i] = i;
    }

    vector<int> energy(n, 0);
    for (int i = 0; i < n; i++) {
        int next_index = next_i[i];
        int sum = 0;
        for (int j = i; j <= next_index; j++) {
            sum += feed[j];
        }
        energy[i] = sum - k;
    }


    vector<int> dp(n + 1, 0);
//    dp[0] = max(0, energy[0]);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = max(dp[i + 1], dp[i]);

        if(n >= next_i[i] + 1 && next_i[i] != -1){
            dp[next_i[i] + 1] = max(dp[next_i[i] + 1], dp[i] + energy[i]);
        }
    }
//    for(auto a : dp){
//        cout << a << " ";
//    }
//    cout<<"\n";
//    for(auto a : next_i){
//        cout << a << " ";
//    }
//    cout<<"\n";
//    for(auto a : energy){
//        cout << a << " ";
//    }
//    cout<<"\n";
    cout << dp[n] << "\n";
};
