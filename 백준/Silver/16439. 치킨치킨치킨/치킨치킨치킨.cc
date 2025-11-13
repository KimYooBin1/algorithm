#include <cstring>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ck(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> ck[i][j];
        }
    }
    vector<int> v(m, 0);
    v[m - 1] = 1;
    v[m - 2] = 1;
    v[m - 3] = 1;

    int result = 0;
    do {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int p_max = 0;
            for (int j = 0; j < m; j++) {
                if(!v[j]) continue;
                p_max = max(p_max, ck[i][j]);
            }
            sum += p_max;
        }
        if(result < sum) result = sum;
    } while (next_permutation(v.begin(), v.end()));
    cout << result << "\n";
}