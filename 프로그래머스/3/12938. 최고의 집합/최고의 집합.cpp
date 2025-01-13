#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(n > s){
        answer.push_back(-1);
        return answer;
    }else if(n == s){
        answer.push_back(1);
        return answer;
    }
    int num1 = s / n;
    int num2 = s % n;
    
    for(int i=0;i<n;i++){
        if(i < num2) answer.push_back(num1 + 1);
        else answer.push_back(num1);
    }
    sort(answer.begin(), answer.end());    
    return answer;
}