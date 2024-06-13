#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 32001
using namespace std;
int cnt[MAX_SIZE];
vector<vector<int>> v(MAX_SIZE, vector<int>());
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int high, low;
        cin >> high >> low;
        v[high].push_back(low);
        cnt[low]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if(cnt[i] == 0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            int nx = v[x][i];
            if(cnt[nx] != 1) {
                cnt[nx]--;
                continue;
            }
            q.push(nx);
        }
    }
    cout<<"\n";
    return 0;
}