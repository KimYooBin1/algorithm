#include <iostream>
#include <cstring>
#include <vector>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MOD 1000000007
using namespace std;

bool check(int current, int limit, int time){
    return (current + time <= limit);
}

int main()
{
    FIO;
    int N, M;
    cin >> N >> M;
    vector<int> time(N + 1, 0);
    time[0] = 1;
    for (int i = 0; i <= N; i++) {
        if(check(i, N, 1)){
            time[i + 1] += time[i];
            time[i + 1] %= MOD;
        }
        if (check(i, N, M)) {
            time[i + M] += time[i];
            time[i + M] %= MOD;
        }
    }
    cout << time[N] << "\n";
    return 0;
}