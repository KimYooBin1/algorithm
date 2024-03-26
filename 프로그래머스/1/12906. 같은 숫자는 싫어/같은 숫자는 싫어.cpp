#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    stack<int> s;
    for(int i = 0; i<arr.size();i++){
        if(s.empty()){
            s.push(arr[i]);
            continue;
        }
        if(s.top() == arr[i]) continue;
        s.push(arr[i]);
    }
    while(!s.empty()){
        answer.push_back(s.top());
        s.pop();
    }
    reverse(answer.begin(), answer.end());
    

    return answer;
}