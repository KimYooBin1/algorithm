#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100001
using namespace std;
vector<pair<int, int>> X;
vector<pair<int, int>> Y;
vector<pair<int, int>> Z;
int parent[MAX_SIZE];
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
bool U(int x, int y){
    int nx = find(x);
    int ny = find(y);
    if(nx == ny) return false;
    parent[nx] = ny;
    return true;
}

int main(){
    FIO;
    int n;
    cin >> n;
    int x, y, z;
    memset(parent, -1, sizeof(parent));
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        cin >> x >> y >> z;
        X.push_back({x, i});
        Y.push_back({y, i});
        Z.push_back({z, i});
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());
    //거리, <index, index>
    vector<pair<int, pair<int, int>>> dist;
    for (int i = 0; i < n - 1; i++) {
        dist.push_back(make_pair(-X[i].first + X[i + 1].first, make_pair(X[i].second, X[i + 1].second)));
        dist.push_back(make_pair(-Y[i].first + Y[i + 1].first, make_pair(Y[i].second, Y[i + 1].second)));
        dist.push_back(make_pair(-Z[i].first + Z[i + 1].first, make_pair(Z[i].second, Z[i + 1].second)));
    }
    sort(dist.begin(), dist.end());
    int from, to;
    int result = 0;
    int index = 0;
    for(int i=0;i<dist.size();i++){
//        cout << i << "\n";
        tie(from, to) = dist[i].second;
//        cout << from << " " << to << " " << dist[i].first << "\n";
        // 연결된적이 없는 그륩
        if (U(from, to)) {
            result += dist[i].first;
            index++;
        }
        if(index == n) break;
    }
    cout << result << "\n";
    return 0;
}
