#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
int main(){
    FIO;
    int n;
    cin >> n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    int b, c;
    cin >> b >> c;
    ll result = 0;
    for(auto & num : v){
        result++;
        if(num - b > 0){
            result += (num - b) / c + ((num - b) % c ? 1 : 0);
        }
    }
    cout << result << "\n";
}