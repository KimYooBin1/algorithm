#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<long long, vector<long long>, greater<long long>> q;
    for(auto a : scoville){
        q.push(a);
    }
    while(q.top() < K){
        if(q.size() == 1) return -1;
        long long first = q.top(); q.pop();
        long long second = q.top(); q.pop();
        long long result = first + 2*second;
        q.push(result);
        answer++;
    }

    return answer;
}