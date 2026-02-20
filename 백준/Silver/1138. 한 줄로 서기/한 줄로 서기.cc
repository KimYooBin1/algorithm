#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> result(n, 0);
    vector<bool> check(n, true);
    for (int i = 0; i < n; i++) {
        int index = v[i];
        int r;
        for (int j = 0; j < n && index != -1; j++) {
            if (!check[j]) continue;
            index--;
            r = j;
        }
        check[r] = false;
        result[r] = i + 1;
    }
    for(auto &a: result){
        cout << a << " ";
    }
    cout << "\n";
}