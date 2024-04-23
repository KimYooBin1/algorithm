#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int parent[101];

int find(int x){
    if(x == parent[x]) return x;
    return find(parent[x]);
}

bool u(int x, int y){
    int p_x = find(x);
    int p_y = find(y);
    if(p_x != p_y){
        parent[p_y] = p_x;
        return true;
    }
    return false;
}

int solution(int n, vector<vector<int>> costs) {
    for(int i=0;i<n;i++){
        parent[i] = i;
    }
    int answer = 0;
    sort(costs.begin(), costs.end(), [](vector<int> a, vector<int> b){
        return a[2]<b[2];
    });
    
    for(int i=0;i<costs.size();i++){
        int x = costs[i][0];
        int y = costs[i][1];
        int cost = costs[i][2];
        if(!u(x, y)){
            continue;
        }
        cout<<x<<" "<<y<<" "<<cost<<"\n";
        answer += cost;
    }
    return answer;
}