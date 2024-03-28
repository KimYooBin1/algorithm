
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#define MAX_SIZE 20001
using namespace std;
int dist[20001];
vector<vector<int>> v(MAX_SIZE, vector<int> ());
int solution(int n, vector<vector<int>> edge) {
    memset(dist, -1, sizeof(dist));
    for(auto vec : edge){
        v[vec[0]].push_back(vec[1]);
        v[vec[1]].push_back(vec[0]);
    }
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    int m_len = 0;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for(int i=0;i<v[x].size();i++){
            int next = v[x][i];
            if(dist[next] != -1) continue;
            dist[next] = dist[x] + 1;
            if(m_len < dist[next]) m_len = dist[next];
            q.push(next);
        }
    }
    int result = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] == m_len) result++;
    }
    return result;
}