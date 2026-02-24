#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define mod 1000000007
typedef long long ll;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    ll n;
    cin>>n;
    vector<ll> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(2);
    for (int i = 3; i <= 191229; i++) {
        v.push_back((v[i - 1] + v[i - 2]) % mod);
    }
    while(n--) {
        ll num;
        cin>>num;
        cout<<v[num--]<<"\n";
    }
}