#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
#define MAX_SIZE 201
int dist[3][MAX_SIZE];
void calc_dist(int from, vector<vector<pair<int, int>>>& v, int c){
    dist[c][from] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0, from});
    while(!pq.empty()){
        int cost = -pq.top().first;
        int now = pq.top().second;
        
        pq.pop();
        if(dist[c][now] < cost) continue;
        for(int i=0;i<v[now].size();i++){
            int next = v[now][i].first;
            int next_cost = cost + v[now][i].second;
            if(dist[c][next] == -1 || next_cost < dist[c][next]){
                dist[c][next] = next_cost;
                pq.push({-next_cost, next});
            }
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    memset(dist, -1, sizeof(dist));
    int answer = INT_MAX;
    vector<vector<pair<int, int>>> v(n + 1);
    for(int i=0;i<fares.size();i++){
        int from = fares[i][0];
        int to = fares[i][1];
        int cost = fares[i][2];
        v[from].push_back({to, cost});
        v[to].push_back({from, cost});
    }
    calc_dist(s, v, 0);
    calc_dist(a, v, 1);
    calc_dist(b, v, 2);
    for(int i=1;i<=n;i++){
        int res1 = dist[0][i];
        int res2 = dist[1][i];
        int res3 = dist[2][i];
        if(res1 == -1 || res2 == -1 || res3 == -1) continue;
        answer = min(answer, res1 + res2 + res3);
    }
    return answer;
}