#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(n + 1, vector<int>());
    int count[n+1];
    memset(count, 0, sizeof(count));
    int from, to;

    for (int i = 0; i < m; i++) {
        int cnt;
        cin>>cnt;
        for(int j=0;j<cnt;j++){
            cin >> to;
            if (j != 0) {
                v[from].push_back(to);
                count[to]++;
            }
            from = to;
        }
    }
    queue<int> q;
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if(count[i]) continue;
        q.push(i);
    }
    while(!q.empty()){
        int x = q.front(); q.pop();
        result.push_back(x);
        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];
            if(--count[v[x][i]] != 0) continue;
            q.push(nx);
        }
    }
    if(result.size() != n) cout<<0<<"\n";
    else for(auto x:result) cout<<x<<"\n";
    return 0;
}