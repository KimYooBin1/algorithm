#include <cstring>
#include <iostream>
#include <stack>
#include <map>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int main(){
    FIO;
    string str;
    cin>>str;
    stack<char> s;
    map<char, int> m;
    //각 연산자 우선순위
    m['+'] = 1;
    m['-'] = 1;
    m['*'] = 2;
    m['/'] = 2;

    string result = "";
    for(int i=0;i<str.length();i++){
        char c = str[i];
        if(c == '('){
            s.push('(');
        }
        else if(c == ')'){
            while(true){
                if(s.top() == '('){
                    s.pop();
                    break;
                }
                result += s.top();
                s.pop();
            }
        }
        else{
            if(c == '+' || c == '-' || c == '*' || c == '/'){
                //햔재 연산자의 우선순위가 깉가니 더 높다
                if(s.empty() || s.top() == '(' || m[s.top()] < m[c]){
                    s.push(c);
                }
                //우선순위가 더 높다
                else{
                    while(!s.empty() && s.top() != '(' && m[c] <= m[s.top()]){
                        result += s.top();
                        s.pop();
                    }
                    s.push(c);
                }
            }
            else{
                result += c;
            }
        }
    }
    while(!s.empty()){
        result += s.top();
        s.pop();
    }
    cout<<result<<"\n";
}