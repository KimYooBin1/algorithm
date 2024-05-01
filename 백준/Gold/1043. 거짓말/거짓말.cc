#include <iostream>
#include <vector>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
int parent[51];

int find(int x){
    if(parent[x] == x) return x;
    return find(parent[x]);
}

void U(int x, int y){
    int px = find(x);
    int py = find(y);
    if(px == py) return;
    parent[py] = px;
}

int main() {
    FIO;
    int n, m;
    cin >> n >> m;
    int cnt;
    cin >> cnt;
    int index;
    for (int i = 1; i <= 50; i++) {
        parent[i] = i;
    }
    vector<int> know;
    for (int i = 0; i < cnt; i++) {
        cin >> index;
        know.push_back(index);
    }
    vector<vector<int>> v(50);
    for (int i = 0; i < m; i++) {
        int p_cnt;
        cin >> p_cnt;
        int first;
        cin>>first;
        v[i].push_back(first);
        for (int j = 1; j < p_cnt; j++) {
            cin >> index;
            U(first, index);
            v[i].push_back(index);
        }
    }
    int answer = m;
    for (auto &list: v) {
        bool check = false;
        for (auto &ind: list) {
            if(check){
                break;
            }
            for (auto &t: know) {
                if (find(t) == find(ind)) {
                    check = true;
                }
            }
        }
        if(check){
            answer--;
        }
    }
    cout << answer << "\n";
}