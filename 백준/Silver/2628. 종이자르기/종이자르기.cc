#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct cut {
    int dir, index;
};
int main(){
    FIO;
    int n, m;
    cin >> n >> m;
    int cnt;
    cin >> cnt;
    vector<cut> v(cnt + 2);
    v[0] = {0, m};
    v[1] = {1, n};
    for (int i = 2; i < cnt + 2; i++) {
        cin >> v[i].dir >> v[i].index;
    }
    vector<int> n_len;
    vector<int> m_len;
    int last_n = 0;
    int last_m = 0;
    sort(v.begin(), v.end(), [](cut &a, cut &b){
        return a.index < b.index;
    });
    for(auto &a : v){
        if(a.dir == 0){
            n_len.push_back(a.index - last_n);
            last_n = a.index;
        }else{
            m_len.push_back(a.index - last_m);
            last_m = a.index;
        }
    }
    int result = 0;
    for (int &i : n_len) {
        for (int &j : m_len) {
//            cout << i << " " << j << "\n";
            result = max(result, i * j);
        }
    }
    cout << result << "\n";
}