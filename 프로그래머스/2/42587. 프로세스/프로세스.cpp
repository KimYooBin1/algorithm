#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 1;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for(int i=0;i<priorities.size();i++){
        int num = priorities[i];
        pq.push(num);
        q.push(make_pair(i,num));
    }
    while(!q.empty()){
        auto num = q.front(); q.pop();
        int index = num.first; int value = num.second;
        int pri = pq.top();
        if(pri <= value){
            pq.pop();
            if(index == location){
                return answer;
            }
            answer++;
            continue;
        }
        q.push(num);
    }
    return answer;
}