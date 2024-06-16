#include <cstring>
#include <iostream>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 250001
using namespace std;
typedef long long ll;
ll arr[MAX_SIZE];
//현재위치 선택 안함 0, 현재위치 선택 1
ll dist[MAX_SIZE][2];
int main(){
    FIO;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin>>arr[i];
    }
    int result = 0;
    //처음을 선택했을 경우
    dist[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        dist[i][0] = max(dist[i-1][0], dist[i-1][1]) + arr[i];
        dist[i][1] = dist[i-1][0] + 1;
    }
    result = dist[n][0];
//    cout << result << "\n";
    memset(dist, 0, sizeof(dist));
    dist[1][0] = arr[1];
    //처음을 선택 안했을 경우
    for (int i = 2; i <= n; i++) {
        dist[i][0] = max(dist[i-1][0], dist[i-1][1]) + arr[i];
        dist[i][1] = dist[i-1][0] + 1;
    }
    int result1 = max(dist[n][0], dist[n][1]);
//    cout << result1 << "\n";
    result = max(result1, result);
    cout << result << "\n";
    return 0;
}