#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple>
#define FIO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
using namespace std;
int calc(int x, int y){
    return max(x, y) % min(x, y);
}
int main(){
    FIO;
    int N, L;
    cin >> N >> L;
    int D, R, G;
    // 초과된 시간
    int result = 0;
    vector<tuple<int,int,int>> v;
    for (int i = 0; i < N; i++) {
        cin >> D >> R >> G;
//        v.push_back({D, R, G});
//    }
//    sort(v.begin(), v.end());
//    for (int i = 0; i < N; i++) {
//        tie(D, R, G) = v[i];
        // 빨간불
        int current_time = D + result;
        int remain = current_time % (R + G);
        if(R <= remain) continue;
        result += abs(remain - R);
    }
    result += L;
    cout << result << "\n";
    return 0;
}
