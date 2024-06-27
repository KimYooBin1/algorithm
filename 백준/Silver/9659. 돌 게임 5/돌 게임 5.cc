#include<cstring>
#include<iostream>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
typedef long long ll;
int main(){
    FIO;
    ll n;
    cin >> n;
    if(n%2){
        cout<<"SK\n";
    }
    else{
        cout<<"CY\n";
    }
    return 0;
}