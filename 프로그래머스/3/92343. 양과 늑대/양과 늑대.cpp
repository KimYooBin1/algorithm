#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool dist[17];
vector<int> result;
void dfs(int sheep, int wolf, vector<vector<int>> & v, vector<int> & info){
    if(sheep > wolf){
        result.push_back(sheep);
    }else{
        return ;
    }
    for(int i=0;i<v.size();i++){
        int parent = v[i][0];
        int child = v[i][1];
        if(dist[parent] && !dist[child]){
            dist[child] = true;
            if(info[child] == 0) dfs(sheep + 1, wolf, v, info);
            else dfs(sheep, wolf + 1, v, info);
            dist[child] = false;
        }
    }
}
int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    dist[0] = true;
    dfs(1, 0, edges, info);
    sort(result.begin(), result.end());
    answer = result[result.size() - 1];
    return answer;
}