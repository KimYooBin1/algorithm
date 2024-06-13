#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long ll;
using namespace std;
int main(){
    FIO;
    int n;
    cin>>n;
    vector<ll> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    sort(v.begin(), v.end());
    int r_s, r_e, r_m;
    //세개의 용액중 한개를 고정
    ll result = LONG_MAX;
    for (int i = 1; i < n - 1; i++) {
        int s = 0;
        int e = n-1;
        while (s < i && i < e) {
            ll sum = v[i] + v[s] + v[e];
//            cout<<s<<" "<<i<<" "<<e<<" "<<sum<<" "<<result<<"\n";
            if(sum < 0){
                if(abs(sum) < abs(result)){
                    result = sum;
                    r_s = s;
                    r_m = i;
                    r_e = e;
                }
                s++;
            } else if (0 < sum) {
                if(abs(sum) < abs(result)){
                    result = sum;
                    r_s = s;
                    r_m = i;
                    r_e = e;
                }
                e--;
            }else{
                cout << v[s] << " " << v[i] << " " << v[e] << "\n";
                return 0;
            }
        }
    }
    cout << v[r_s] << " " << v[r_m] << " " << v[r_e] << "\n";
}