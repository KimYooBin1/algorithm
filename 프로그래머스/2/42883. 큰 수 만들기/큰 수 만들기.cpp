#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<int> s;
    for(int i=0;i<number.size();i++){
        if(s.empty()){
            s.push(number[i] - '0');
            continue;
        } 
        
        while(!s.empty() && k && s.top() < number[i] - '0'){ //k가 남아있거나 현재수가 더 클때
            s.pop();
            k--;
        }
        
        s.push(number[i] - '0');
    }
    while(!s.empty()){
        char c = '0' + s.top();
        s.pop();
        if(k){
            k--;
            continue;
        }
        answer += c;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}