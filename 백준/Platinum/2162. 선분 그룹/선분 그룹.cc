#include <cstring>
#include <iostream>
#include <vector>
#include <map>

#define MAX_SIZE 3001

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

int in = 1;
int g_index[MAX_SIZE];
int g_size[MAX_SIZE];
int parent[MAX_SIZE];

vector<vector<pair<pll, pll>>> v((MAX_SIZE), vector<pair<pll,pll>>());
ll CCW(pll A, pll B, pll C){
    ll tmp = A.first * B.second + B.first * C.second + C.first * A.second
             - (B.first * A.second + C.first * B.second + A.first * C.second);

    if(tmp<0) return -1;
    else if(tmp == 0) return 0;
    else return 1;
}

int find(int x){
    if(x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void U(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return ;
    if(px<py){
        parent[py] = px;
    } else{
        parent[px] = py;
    }
}

void calc(vector<pair<pll, pll>> A, vector<pair<pll, pll>> B, int i, int j) {
    ll ret1 = CCW(A[0].first, A[0].second, B[0].first) * CCW(A[0].first, A[0].second, B[0].second);
    ll ret2 = CCW(B[0].first, B[0].second, A[0].first) * CCW(B[0].first, B[0].second, A[0].second);

    if(ret1<=0 && ret2<=0) {
        if(A[0].second < A[0].first) swap(A[0].first, A[0].second);
        if(B[0].second < B[0].first) swap(B[0].first, B[0].second);
        if(A[0].first <= B[0].second && B[0].first <= A[0].second){
            U(i, j);
        }
    }
}

int main(){
    int n;
    cin>>n;
    for (int i = 0; i < MAX_SIZE; i++) {
        parent[i] = i;
    }
    for(int j=0;j<n;j++){
        ll x, y, x1, y1;
        cin>>x>>y>>x1>>y1;
        v[j].push_back(make_pair(make_pair(x, y), make_pair(x1, y1)));
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            calc(v[i], v[j], i, j);
        }
    }

    for(int i=0;i<n;i++){
        g_size[find(i)]++;
    }
    int cnt = 0;
    int result = 0;
    for(int i=0;i<n;i++){
//        cout<<g_size[i]<<" ";
        if(g_size[i]) cnt++;
        result = max(result, g_size[i]);
    }
//    cout<<"\n";
    cout << cnt << "\n" << result << "\n";
}