#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    queue<int> q;
    for(int i=0;i<bridge_length;i++){
        q.push(0);
    }
    int cnt = 0;
    int index = 0;
    int len = truck_weights.size();
    int sum = 0;
    int time = 0;
    while(cnt<len){
        int num = q.front(); q.pop();
        // cout<<time<<" "<<num<<"\n";
        time++;
        if(num != 0){
            sum-=num;
            cnt++;
        }
        
        if(weight < sum + truck_weights[index]){
            q.push(0);
            continue;
        } 
        
        sum += truck_weights[index];
        q.push(truck_weights[index++]);
    }
    return time;
}