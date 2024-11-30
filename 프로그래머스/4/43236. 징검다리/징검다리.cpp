#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int e, vector<int> rocks, int n) {
    int answer = 0;
    int s = 0;
    rocks.push_back(e);
    sort(rocks.begin(), rocks.end());
    while(s <= e){
        int m = (s + e) / 2;
        int cnt = 0;
        int end = 0;
        for(int i=0;i<rocks.size();i++){
            if(rocks[i] - end < m){
                cnt++;
                continue;
            }
            end = rocks[i];
        }
        // 제거한 돌이 더 많다(거리가 너무 넓다)
        if(cnt > n){
            e = m - 1;
        }
        // 제거한 돌이 더 적거나 같다(거리가 너무 좁다)
        else{
            s = m + 1;
            answer = m;
        }
    }
    return answer;
}