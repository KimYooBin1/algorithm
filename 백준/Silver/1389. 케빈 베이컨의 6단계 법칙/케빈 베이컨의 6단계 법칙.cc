#include<cstring>
#include<iostream>
#include<climits>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;


int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    int link[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for(int j=1;j<=n;j++){
            if(i==j) link[i][j] = 0;
            else link[i][j] = INT_MAX/2;
        }
    }
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        link[from][to] = 1;
        link[to][from] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int from = 1; from <= n; from++) {
            for (int to = 1; to <= n; to++) {
                if(from == to) continue;
                int calc = link[from][i] + link[i][to];
                if(calc <= link[from][to]) link[from][to] = calc;
            }
        }
    }
    int sum = -1;
    int result;
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1; j <= n; j++) {
            tmp += link[i][j];
        }
        if(sum == -1 || tmp < sum){
            result = i;
            sum = tmp;
        }
    }
    cout<<result<<"\n";
}