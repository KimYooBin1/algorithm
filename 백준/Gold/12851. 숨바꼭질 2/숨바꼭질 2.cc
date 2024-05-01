#include<iostream>
#include<cstring>
#include<queue>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100001
using namespace std;
int dist[2 * MAX_SIZE];
int cnt[2 * MAX_SIZE];
int main(){
    FIO;
    int n, k;
    cin >> n >> k;
    memset(dist, -1, sizeof(dist));
    dist[n] = 0;
    cnt[n] = 1;
    queue<int> q;
    q.push(n);
    while (!q.empty()) {
        int x = q.front();
//        cout<<x<<"\n";
        q.pop();
        if (0 <= x - 1) {
            if (dist[x - 1] == -1) {
                q.push(x - 1);
                dist[x - 1] = dist[x] + 1;
                cnt[x - 1] += cnt[x];
            } else if (dist[x - 1] == dist[x] + 1) {
                cnt[x - 1] += cnt[x];
            }
        }
        if (x + 1 < MAX_SIZE) {
            if (dist[x + 1] == -1) {
                q.push(x + 1);
                dist[x + 1] = dist[x] + 1;
                cnt[x + 1] += cnt[x];
            } else if (dist[x + 1] == dist[x] + 1) {
                cnt[x + 1] += cnt[x];
            }
        }
        if(x*2 <= MAX_SIZE * 2){
            if (dist[x * 2] == -1) {

                q.push(x * 2);
                dist[x * 2] = dist[x] + 1;
                cnt[x * 2] += cnt[x];
            } else if (dist[x * 2] == dist[x] + 1) {
                cnt[x * 2] += cnt[x];
            }
        }
    }
    cout<<dist[k]<<"\n"<<cnt[k]<<"\n";
}