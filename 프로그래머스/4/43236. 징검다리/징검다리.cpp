#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int answer;
    int s = 0;
    int e = distance;
    int m;
    while(s<=e){
        m = (s+e)/2;
        int cnt = 0;
        int before = rocks[0];
        //시작점과 도착점은 지울수 없기때문에 뺀다
        for(int i=1;i<rocks.size();i++){
            //간격이 더 크커나 같으면 부술 필요가 없다
            if(m <= rocks[i] - before){
                before = rocks[i];
            }
            //간격이 더 작으면 부순다
            else{
                cnt++;
            }
        }
        //목표한 돌보다 적게 부숨
        if(cnt <= n){
            s = m + 1;
            answer = m;
        }
        //목표한 돌보다 많음
        else{
            e = m-1;
        }
    }
    return answer;
}