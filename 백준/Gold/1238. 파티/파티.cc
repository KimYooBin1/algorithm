#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;

int main(){
    FIO;
    int n, m, x;
    cin >> n >> m >> x;
    vector<vector<pair<int, int>>> v1(n + 1, vector<pair<int, int>>());
    vector<vector<pair<int, int>>> v2(n + 1, vector<pair<int, int>>());

    priority_queue<pair<int,int>> pq;   //pair{cost, index}
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v1[to].push_back(make_pair(from, cost));
        v2[from].push_back(make_pair(to, cost));

    }
    int dist1[n + 1];
    int dist2[n + 1];
    for (int i = 1; i <= n; i++) {
        dist1[i] = INT_MAX;
        dist2[i] = INT_MAX;
    }
    pq.push(make_pair(0, x));
    dist1[x] = 0;
    while (!pq.empty()) {
        int index = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for (int i = 0; i < v1[index].size(); i++) {
            int next = v1[index][i].first;
            int n_cost = v1[index][i].second;
            if(cost + n_cost < dist1[next]){
                dist1[next] = cost + n_cost;
                pq.push(make_pair(-dist1[next], next));
            }
        }
    }


    pq.push(make_pair(0, x));
    dist2[x] = 0;
    while (!pq.empty()) {
        int index = pq.top().second;
        int cost = -pq.top().first;
        pq.pop();
        for (int i = 0; i < v2[index].size(); i++) {
            int next = v2[index][i].first;
            int n_cost = v2[index][i].second;
            if(cost + n_cost < dist2[next]){
                dist2[next] = cost + n_cost;
                pq.push(make_pair(-dist2[next], next));
            }
        }
    }
    int result = -1;
    for (int i = 1; i <= n; i++) {
        if(result < dist1[i] + dist2[i]) result = dist1[i] + dist2[i];
    }
    cout << result << "\n";
}
