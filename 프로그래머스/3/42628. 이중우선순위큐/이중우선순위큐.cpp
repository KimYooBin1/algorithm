#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq1;
    priority_queue<int, vector<int>, greater<int>> pq2;
    int cnt1 = 0;
    for(string str : operations){
        char c = str[0];
        int n = stoi(str.substr(2));
        if(c == 'I'){
            pq1.push(n);
            pq2.push(n);
            cnt1++;
        }
        else if(c == 'D' && n == 1 && 0 < cnt1){
            cnt1--;
            pq1.pop();
        }
        else if(c == 'D' && n == -1 && 0 < cnt1){
            cnt1--;
            pq2.pop();
        }
        if(cnt1 == 0){
            pq1 = priority_queue<int>();
            pq2 = priority_queue<int, vector<int>, greater<int>>();
        }
    }
    if(cnt1 == 0){
        answer.push_back(0);
        answer.push_back(0);
    }
    else{
        answer.push_back(pq1.top());
        answer.push_back(pq2.top());
    }
    return answer;
}