#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

bool check(string str1, string str2){
    int cnt = 0;
    for(int i=0;i<str1.length();i++){
        if(str1[i] != str2[i]) cnt++;
    }
    if(cnt > 1) return false;
    return true;
}

int solution(string begin, string target, vector<string> words) {
    
    queue<string> q;
    map<string, int> m;
    q.push(begin);
    m[begin] = 0;
    while(!q.empty()){
        string str = q.front(); q.pop();
        for(int i=0;i<words.size();i++){
            if(str == words[i]) continue;
            if(!check(str, words[i])) continue;
            if(m.find(words[i]) != m.end()) continue;
            q.push(words[i]);
            m[words[i]] = m[str] + 1;
        }
    }
    if(m.find(target) == m.end()){
        return 0;
    }
    else{
        return m[target];
    }
}