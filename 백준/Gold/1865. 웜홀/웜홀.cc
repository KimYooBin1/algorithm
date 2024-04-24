#include<cstring>
#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<tuple>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;


int main(){
    FIO;
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m, w;
        cin >> n >> m >> w;
        int dist[n+1];
        for (int i = 1; i <= n; i++) {
            dist[i] = 0;
        }
        vector<tuple<int, int, int>> v;
        for (int i = 0; i < m; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            v.push_back(make_tuple(from, to, cost));
            v.push_back(make_tuple(to, from, cost));
        }
        for (int i = 0; i < w; i++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            v.push_back(make_tuple(from, to, -cost));
        }
        int from, to, cost;
        for (int i = 0; i < n + w; i++) {
            for (int j = 0; j < v.size(); j++) {
                from = get<0>(v[j]);
                to = get<1>(v[j]);
                cost = get<2>(v[j]);
//                cout << from << " " << to << " " << cost << "\n";
                if(dist[from] + cost < dist[to]) dist[to] = dist[from] + cost;
//                cout << dist[to] << "\n";
            }
        }
        bool check = true;
        for (int j = 0; j < v.size(); j++) {
            from = get<0>(v[j]);
            to = get<1>(v[j]);
            cost = get<2>(v[j]); 
            if(dist[from] + cost < dist[to]) {
                check = false;
                break;
            }
        }
        if(check){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
    }
}
