#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    sort(jobs.begin(), jobs.end());
    int current = 0;
    int total = 0;
    int index = 0;
    while(index < jobs.size() || !q.empty()){
        //현재 시간보다 일찍 시작하는 일
        if(index < jobs.size() && jobs[index][0] <= current){
            q.push(make_pair(jobs[index][1], jobs[index][0]));
            index++;
            continue;
        }
        //현재 작업중인 일이 없다
        if(q.empty()){
            current = jobs[index][0];
        }
        //현재 작업중인 일이 있음
        else{
            current += q.top().first;
            total += current - q.top().second;
            q.pop();
        }
    }
    return total/jobs.size();
}