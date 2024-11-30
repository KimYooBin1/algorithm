#include<vector>
#define MAX_SIZE 1000000000
using namespace std;
typedef long long ll;

ll calc(ll m, vector<vector<int>> & land, int P, int Q){
    int len1 = land.size();
    int len2 = land[0].size();
    ll sum = 0;
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            if(land[i][j] < m){
                sum += (m - land[i][j]) * P;
            }else if(m < land[i][j]){
                sum += (-m + land[i][j]) * Q;
            }
        }
    }
    return sum;
}

ll solution(vector<vector<int>> land, int P, int Q) {
    ll answer = -1;
    ll s = 0;
    ll e = MAX_SIZE;
    while(s < e){
        ll m = (s + e) / 2;
        ll result1 = calc(m, land, P, Q);
        ll result2 = calc(m + 1, land, P, Q);
        
        if(result1 < result2){
            answer = result1;
            e = m;
        }else{
            answer = result2;
            s = m + 1;
        }
    }
    return answer;
}