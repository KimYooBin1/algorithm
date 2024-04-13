#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

#define MAX_SIZE 6001

#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;


vector<tuple<int, int, long long>> map;

long long dist[MAX_SIZE];
int n, m;

void calc(){
    dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (auto a: map) {
            int from = get<0>(a);
            int to = get<1>(a);
            long long cost = get<2>(a);

            if(dist[from] == INT_MAX) continue;
            if(dist[to] > dist[from] + cost){
                dist[to] = dist[from] + cost;
            }
        }
    }
    bool check = true;
    for (auto a: map) {
        int from = get<0>(a);
        int to = get<1>(a);
        long long cost = get<2>(a);

        if(dist[from] == INT_MAX) continue;
        if(dist[to] > dist[from] + cost){
            dist[to] = dist[from] + cost;
            check = false;
        }
    }
    if(check){
        for (int i = 2; i <= n; i++) {
            if(dist[i]==INT_MAX){
                cout<<-1<<"\n";
            }
            else{
                cout<<dist[i]<<"\n";
            }
        }
        return;
    }
    else{
        cout<<-1<<"\n";
        return;
    }
}

int main()
{
    FIO;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to ,cost;
        cin >> from >> to >> cost;
        map.push_back(make_tuple(from, to, cost));
    }
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    calc();

    return 0;
}