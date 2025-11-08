#include<cstring>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct P {
    int dir, index;
};

int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    int cnt;
    cin >> cnt;
    vector<P> v;
    int dir, index;
    for (int i = 0; i < cnt; i++) {
        cin >> dir >> index;
        v.push_back({dir, index});
    }
    int result = 0;
    cin >> dir >> index;
    for (int i = 0; i < cnt; i++) {
        int s_dir = v[i].dir;
        int s_index = v[i].index;
        if (s_dir == dir) result += abs(index - s_index);
        else if (s_dir + dir == 3) {
            result += m + min(index + s_index, 2 * n - index - s_index);
        } else if (s_dir + dir == 7) {
            result += n + min(index + s_index, 2 * m - index - s_index);
        } else if (s_dir + dir == 6) {
            result += n + m - index - s_index;
        } else if (s_dir + dir == 4) {
            result += index + s_index;
        } else if (s_dir == 1 || s_dir == 4) {
            result += dir == 1 ? n - index + s_index : n - s_index + index;
        } else {
            result += dir == 2 ? index + m - s_index : s_index + m - index;
        }
    }
    cout << result << "\n";
}