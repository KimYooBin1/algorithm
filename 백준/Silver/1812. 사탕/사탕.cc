#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int n;
    cin>>n;
    vector<int> sum(n);
    vector<int> result;
    for (int i = 0; i < n; i++) {
        cin >> sum[i];
    }
    int s = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            s += sum[i];
        } else {
            s -= sum[i];
        }
    }
    int x = s / 2;
    result.push_back(x);
    for (int i = 0; i < n - 1; i++) {
        int tmp = sum[i] - x;
        result.push_back(tmp);
        x = tmp;
    }

    for(auto &a: result){
        cout<<a<<" ";
    }
    cout << "\n";
}