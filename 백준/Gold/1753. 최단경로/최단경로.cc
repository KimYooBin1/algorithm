#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

#define MAX_SIZE 20001
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int dist[MAX_SIZE];

vector<vector<pair<int,int>>> map(MAX_SIZE, vector<pair<int,int>>());

int v, e, s;

void dijstra(int x){
    priority_queue<pair<int,int>> q;    //{dist, index}
    q.push(make_pair(0, x));
    dist[x] = 0;
    while (!q.empty()) {
        int d = -q.top().first;
        int index = q.top().second;
        q.pop();
        for (int i = 0; i < map[index].size(); i++) {
            int nindex = map[index][i].first;
            int ncost = map[index][i].second;
            if(dist[nindex] > d + ncost){
                dist[nindex] = d + ncost;
                q.push(make_pair(-dist[nindex], nindex));
            }
        }
    }
    for(int i=1;i<=v;i++){
        if(dist[i] == 1000000000){
            cout<<"INF"<<"\n";
        }
        else{
            cout<<dist[i]<<"\n";
        }
    }
}

int main()
{
    FIO;
    cin >> v >> e >> s;
    for (int i = 0; i < e; i++) {
        int from, to, cost;
        bool check =false;
        cin>>from>>to>>cost;
        for(int j=0;j<map[from].size();j++){
            if(map[from][j].first == to){
                check = true;
                if(cost < map[from][j].second){
                    map[from][j] = {map[from][j].first, cost};
                    break;
                }
            }
        }
        if(check) continue;
        map[from].push_back(make_pair(to, cost));
    }
    for(int i=1;i<=v;i++){
        dist[i] = 1000000000;
    }
    dijstra(s);

    return 0;
}