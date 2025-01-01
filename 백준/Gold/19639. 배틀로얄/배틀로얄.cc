#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main() {
    int x, y, m;
    cin >> x >> y >> m;
    vector<pair<int,int>> v1;   // 잃는 체력
    vector<pair<int,int>> v2;   // 체력 회복
    for (int i = 0; i < x; i++) {
        int tmp;
        cin >> tmp;
        v1.push_back({i+1, tmp});
    }
    for (int i = 0; i < y; i++) {
        int tmp;
        cin >> tmp;
        v2.push_back({i+1, tmp});
    }
    vector<int> result;
    int index1 = 0, index2 = 0;
    int health = m;
    while (index1 < x && index2 < y) {
        // 피가 절반도 안남았을 때(힐해야됨)
        if (health <= (m / 2)) {
            health += v2[index2].second;
            health = min(m, health);
            result.push_back(v2[index2++].first);
        } else {
            health -= v1[index1].second;
            result.push_back(-v1[index1++].first);
        }
    }
    while (index1 < x) {
        health -= v1[index1].second;
        if(health <= 0){
            cout << 0 << "\n";
            return 0;
        }
        result.push_back(-v1[index1++].first);
    }
    while(index2 < y){
        result.push_back(v2[index2++].first);
    }
    for(auto & num: result){
        cout << num << "\n";
    }
}