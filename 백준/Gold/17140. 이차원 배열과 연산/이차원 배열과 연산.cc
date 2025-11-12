#include<cstring>
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct s{
    int num;
    int size = 0;
};
int main(){
    FIO;
    int r, c, k;
    cin >> r >> c >> k;
    vector<vector<int>> v(101, vector<int>(101, 0));
    int n = 3;
    int m = 3;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            cin >> v[i][j];
        }
    }
    int in = 0;
    bool check = false;
    while (in <= 100) {
//        cout << in << " " << v[r][c] << " " << r << " " << c << "\n";
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= m; j++) {
//                cout << v[i][j] << " ";
//            }
//            cout << "\n";
//        }
//        cout << "\n";
        if(v[r][c] == k) {
            check = true;
            break;
        }
        if(n >= m){
            int max_size = -1;
            for (int i = 1; i <= min(100, n); i++) {
                vector<s> tmp_v;
                vector<int> num_index;
                map<int, int> num_cnt;
                for (int j = 1; j <= m; j++) {
                    if(!v[i][j]) continue;
                    num_cnt[v[i][j]]++;
                    num_index.push_back(v[i][j]);
                }
                sort(num_index.begin(), num_index.end());
                num_index.erase(unique(num_index.begin(), num_index.end()), num_index.end());
                int index_size = num_index.size();
                for (auto &num: num_index) {
                    tmp_v.push_back({num, num_cnt[num]});
                }
                sort(tmp_v.begin(), tmp_v.end(), [](s a, s b){
                    if(a.size != b.size) return a.size < b.size;
                    else return a.num < b.num;
                });
                v[i] = vector<int> (101, 0);
                for (int j = 1; j <= index_size; j++) {
                    v[i][2 * j - 1] = tmp_v[j - 1].num;
                    v[i][2 * j] = tmp_v[j - 1].size;
                }
                max_size = max(max_size, index_size * 2);
            }
            m = max_size;
        }else{
            int max_size = -1;
            for (int i = 1; i <= min(100, m); i++) {
                vector<s> tmp_v;
                vector<int> num_index;
                map<int, int> num_cnt;
                for (int j = 1; j <= n; j++) {
                    if(!v[j][i]) continue;
                    num_cnt[v[j][i]]++;
                    num_index.push_back(v[j][i]);
                }
                sort(num_index.begin(), num_index.end());
                num_index.erase(unique(num_index.begin(), num_index.end()), num_index.end());
                int index_size = num_index.size();
                for (auto &num: num_index) {
//                    cout << num << " " << num_cnt[num] << "\n";
                    tmp_v.push_back({num, num_cnt[num]});
                }
                sort(tmp_v.begin(), tmp_v.end(), [](s a, s b){
                    if(a.size != b.size) return a.size < b.size;
                    else return a.num < b.num;
                });
                for (int j = 1; j <= 100; j++) {
                    v[j][i] = 0;
                }
                for (int j = 1; j <= index_size; j++) {
                    v[2 * j - 1][i] = tmp_v[j - 1].num;
                    v[2 * j][i] = tmp_v[j - 1].size;
                }
                max_size = max(max_size, index_size * 2);
            }
            n = max_size;
        }
        in++;
    }
    if(check) cout<<in<<"\n";
    else cout << -1 << "\n";
}