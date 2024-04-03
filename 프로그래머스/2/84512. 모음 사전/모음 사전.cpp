#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<string> v;
char arr[] = {'A', 'E', 'I', 'O', 'U'};

void dfs(string str){
    v.push_back(str);
    if(str.length() == 5) return;
    for(int i=0;i<5;i++){
        dfs(str + arr[i]);
    }
}

int solution(string word) {
    dfs("");
    for(int i=1;i<v.size();i++){
        if(v[i] == word){
            return i;
        }
    }
}