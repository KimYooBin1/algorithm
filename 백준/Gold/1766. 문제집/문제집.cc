#include <cstring>
#include <iostream>
#include <queue>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 32001
using namespace std;
int cnt[MAX_SIZE];
//0 아직 사용 못함, 1후보 등록 가능 2 사용됨
int check[MAX_SIZE];
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v(MAX_SIZE, vector<int> ());
    for (int i = 0; i < m; i++) {
        int a, b;
        cin>>a>>b;
        v[a].push_back(b);
        cnt[b]++;
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++) {
        if(!cnt[i]){
            check[i] = 1;
            q.push(i);
        }
    }

    while(!q.empty()){
        int x = q.top();
        cout << x << " ";
        q.pop();
        for (int j = 0; j < v[x].size(); j++) {
            int nx = v[x][j];
            if(check[nx]) continue;
            if(--cnt[nx] != 0) continue;
            check[nx] = 1;
            q.push(nx);
        }
    }
    return 0;
}