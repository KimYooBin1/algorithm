#include <string>
#include <vector>
#include <iostream>
#include <climits>
#define M_L LONG_MAX/9
typedef long long ll;

using namespace std;

long long solution(int n, vector<int> times) {
    ll s = 0;
    ll e = M_L;
    // 현재 시간이 m일때 처리할수 있는 인원
    while(s<e){
        ll m = (s+e)/2;
        ll exac = 0;
        for(int i=0;i<times.size();i++){
            exac += m/times[i];
        }
        // cout<<m<<" "<<exac<<"\n";
        //처리할수 있는 인원이 기존보다 적다
        if(exac < n){
            s = m+1;
        }
        //처리할 수 있는 인원이 더 많거나 같다
        else{
            e = m;
        }
    }
    return e;
}