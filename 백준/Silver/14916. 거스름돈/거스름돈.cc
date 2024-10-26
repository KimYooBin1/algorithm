#include<cstring>
#include<iostream>
#include<climits>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 100001
int dist[MAX_SIZE];
int main(){
    FIO;
    int n;
    cin >> n;
    fill(dist, dist + MAX_SIZE, INT_MAX / 2);
    dist[2] = 1; dist[5] = 1; dist[4] = 2;
    
    for (int i = 6; i <= n; i++) {
        dist[i] = min(dist[i - 2], dist[i - 5]) + 1;
    }
    int result = dist[n] >= INT_MAX / 2 ? -1 : dist[n];

    cout << result << "\n";
    return 0;
}