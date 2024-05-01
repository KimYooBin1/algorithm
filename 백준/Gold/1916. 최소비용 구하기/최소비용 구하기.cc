#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>

#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 1001
using namespace std;
int dist[MAX_SIZE];
bool check[MAX_SIZE];
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    vector<vector<pair<int, int>>> v(n + 1, vector<pair<int, int>>());
    for (int i = 0; i < m; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        v[from].push_back(make_pair(to, cost));
    }
    priority_queue<pair<int,int>> pq;
    int s, e;
    cin >> s >> e;
    pq.push(make_pair(0, s));
    dist[s] = 0;
    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int index = front.second;
        if(check[index]) continue;
        check[index] = true;
        int cost = -front.first;
//        cout << index << " " << cost << "\n";
        for (int i = 0; i < v[index].size(); i++) {
            int next = v[index][i].first;
            int n_cost = v[index][i].second;
            if(cost + n_cost < dist[next]){
                dist[next] = cost + n_cost;
                pq.push(make_pair(-(cost + n_cost), next));
            }
        }
    }
    cout << dist[e] << "\n";
}