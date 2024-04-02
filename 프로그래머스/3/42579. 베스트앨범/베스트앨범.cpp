#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b){
    if(a.first == b.first){
        return a.second < b.second;
    }
    return a.first > b.first;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    map<string, int> m; //목록별 개수
    vector<string> index;   //목록 종류
    map<string, vector<pair<int, int>>> info;   //목록별 정보(count, index)
    vector<pair<int, string>> v;    //목록별 개수(count, 종류)
    for(int i=0;i<genres.size();i++){
        if(m.find(genres[i]) == m.end()){
            index.push_back(genres[i]);
        }
        m[genres[i]] += plays[i];
        info[genres[i]].push_back(make_pair(plays[i], i));
    }
    
    for(int i=0;i<index.size();i++){
        v.push_back(make_pair(m[index[i]], index[i]));
    }
    
    sort(v.begin(), v.end(), greater<>());
    vector<int> answer;
    
    for(int i=0;i<v.size();i++){
        auto &a = info[v[i].second];    //vector<pair<count, index>>
        sort(a.begin(), a.end(), cmp);
        answer.push_back(a[0].second);
        if(1 < a.size()) answer.push_back(a[1].second);
        
    }
    return answer;
}