#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;
int s;
map<string, vector<string>> m;  //도시별 이동할수 있는 도시
map<pair<string, string>, int> dist;
vector<string> v;       //어떤 도시가 있는지

vector<string> answer;
bool dfs(string str, int cnt){
    // cout<<str<<" "<< cnt<<"\n";
    if(cnt == s) return true;
    for(int i=0;i<m[str].size();i++){
        string next = m[str][i];
        if(dist[make_pair(str, next)] == 0) continue;
        dist[make_pair(str,next)]--;
        
        answer.push_back(next);
        if(dfs(next, cnt+1)){
            return true;
        }
        answer.erase(answer.begin() + cnt + 1);
        dist[make_pair(str, next)]++;
        // cout<<str<<" "<<next<<" "<<dist[make_pair(str, next)]<<"\n";
        
    }
    return false;
}
vector<string> solution(vector<vector<string>> tickets) {
    for(int i=0;i<tickets.size();i++){
        string from = tickets[i][0];
        string to = tickets[i][1];
        if(find(v.begin(), v.end(), from) == v.end()){
            v.push_back(from);
        }
        if(find(v.begin(), v.end(), to) == v.end()){
            v.push_back(to);
        }
        dist[make_pair(from, to)]++;
        m[from].push_back(to);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++){
        sort(m[v[i]].begin(), m[v[i]].end());
    }    
    s = tickets.size();
    answer.push_back("ICN");
    dfs("ICN", 0);
    return answer;
}