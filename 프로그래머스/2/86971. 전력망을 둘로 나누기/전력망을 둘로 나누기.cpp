#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#define MAX_SIZE 101
using namespace std;
int dist[MAX_SIZE];
int solution(int n, vector<vector<int>> wires) {
    int len = wires.size();
    vector<int> order(len, 0);
    order[len-1] = 1;
    int answer = -1;
    do{
        memset(dist, -1, sizeof(dist));
        vector<vector<int>> v(n+1, vector<int>());
        int g_size = 0;
        for(int i=0;i<wires.size();i++){
            if(order[i] == 1) continue;
            int from = wires[i][0]; int to = wires[i][1];
            v[from].push_back(to);
            v[to].push_back(from);
        }
        
        for(int i=1;i<=n;i++){
            if(dist[i] != -1) continue;
            queue<int> q;
            q.push(i);
            dist[i] = g_size++;
            while(!q.empty()){
                int x = q.front(); q.pop();
                for(int j=0;j<v[x].size();j++){
                    int nx = v[x][j];
                    if(dist[nx] != -1) continue;
                    q.push(nx);
                    dist[nx] = dist[x];
                }
            }
            
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] == 0){
                cnt1++;
            }
            else{
                cnt2++;
            }
        }
        int result = abs(cnt1 - cnt2);
        if(answer == -1 || result < answer){
            answer = result;
        }
    }while(next_permutation(order.begin(), order.end()));
    return answer;
}