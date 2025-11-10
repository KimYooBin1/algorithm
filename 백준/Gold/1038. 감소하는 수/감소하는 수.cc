#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
ll result_num;
ll c(ll n){
    ll result = 1;
    while(n){
        result *= n;
        n--;
    }
    return result;
}

ll calc(ll n){
    return c(10) / (c(n) * c(10 - n));
}

long long num_index = 9;
bool check_num[10];
int n;

bool cn(ll nm){
    ll pre_num = -1;
    while(nm){
        ll num = nm % 10;
        nm /= 10;
        if(num <= pre_num) return false;
        pre_num = num;
    }
    return true;
}

bool b(ll len, ll num){
//    cout << num << "\n";
    if(len == 0) {
        num_index++;
        if(num_index == n) {
            result_num = num;
            return true;
        }
        return false;
    }
    for (int i = 0; i < 10; i++) {
        if(!num && i == 0) continue;
        if(check_num[i]) continue;
        if(!cn(num * 10 + i)) continue;
        check_num[i] = true;
        bool r = b(len - 1, num * 10 + i);
        check_num[i] = false;
        if(r) return true;
    }
    return false;
}

int main(){
    FIO;
    cin >> n;
    if(n <= num_index){
        cout << n;
        return 0;
    }
    int check = false;
    ll i = 2;
    for (; i <= 10; i++) {
        ll sum_index = calc(i);
        num_index += sum_index;
        if(n <= num_index) {
            check = true;
            num_index -= sum_index;
            break;
        }
    }
    if(!check) cout << -1 << "\n";
    else {
//        cout << i << " " << num_index << "\n";

        b(i, 0);
        cout << result_num << "\n";
    }
}