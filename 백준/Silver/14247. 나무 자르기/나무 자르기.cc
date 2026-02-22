#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    long long result = 0;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        result += num;
    }
    vector<long long> grow(n);
    for (int i = 0; i < n; i++) {
        cin >> grow[i];
    }
    sort(grow.begin(), grow.end());
    for (long long  i = 0; i < n; i++) {
        result += (i ) * grow[i];
    }
    cout << result << "\n";
}