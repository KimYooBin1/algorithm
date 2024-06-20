#include<cstring>
#include<iostream>
#include<climits>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 2501
using namespace std;
int dist[MAX_SIZE][MAX_SIZE];
string str;
bool check(int a, int b){
    while(a<b){
        if (str[a++] != str[b--]) return false;
    }
    return true;
}
int dp(int s, int e) {
    if(s == e) return dist[s][e] = 1;
    if(dist[s][e] != -1) return dist[s][e];
    if (check(s, e)) return dist[s][e] = 1;
    int result = INT_MAX;
    for (int i = s; i < e; i++) {
        if(!check(s, i)) continue;
        result = min(result, dp(s, i) + dp(i + 1, e));
    }
    return dist[s][e] = result;
}
int main(){
    FIO;
    cin>>str;
    memset(dist, -1, sizeof(dist));
    cout << dp(0, str.length() - 1) << "\n";

}