#include <string>
#include <vector>
#include <queue>
#define MAX_SIZE 201
using namespace std;

int dist[MAX_SIZE];
int g_size = 1;
int solution(int n, vector<vector<int>> computers) {
    for(int i=0;i<n;i++){
        if(dist[i] != 0) continue;
        dist[i] = g_size++;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int x = q.front(); q.pop();
            for(int j=0;j<n;j++){
                if(x == j) continue;
                if(dist[j] != 0) continue;
                if(computers[x][j] == 0) continue;
                dist[j] = dist[x];
                q.push(j);
            }
        }
    }
    
    return g_size-1;
}