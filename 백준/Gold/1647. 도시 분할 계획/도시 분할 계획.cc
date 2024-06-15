#include <cstring>
#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 100001
using namespace std;
int parent[MAX_SIZE];
int g_size[MAX_SIZE];
int find(int x){
    if(parent[parent[x]] == x) return x;
    return find(parent[parent[x]]);
}
bool U(int x, int y){
    int px = find(parent[x]);
    int py = find(parent[y]);
    if(px == py) return true;
    if(g_size[px] < g_size[py]){
        int tmp = py;
        py = px;
        px = tmp;
    }
    parent[py] = px;
    g_size[px] += g_size[py];
    return false;
}
int main(){
    FIO;
    int n, m;
    int result = 0;
    cin >> n >> m;
    if(2 == n){
        cout<<0<<"\n";
        return 0;
    }
    int from, to, cost;
    vector<tuple<int,int,int>> v;
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
        g_size[i] = 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        v.push_back({cost, from, to});
//        v.push_back({cost, to, from});
    }
    sort(v.begin(), v.end(), [](tuple<int, int, int> a, tuple<int, int, int> b) {
        return get<0>(a) < get<0>(b);
    });
    int cnt = 0;
    for (int i = 0; i < m; i++) {
        cost = get<0>(v[i]);
        from = get<1>(v[i]);
        to = get<2>(v[i]);
        // true 면 사이클 형성, false이면 사이클 형성 안됨
        if(U(from, to)) continue;
        result += cost;
        if(++cnt == n-2){
            cout<<result<<"\n";
            return 0;
        }
    }
    cout<<result<<"\n";

    return 0;
}