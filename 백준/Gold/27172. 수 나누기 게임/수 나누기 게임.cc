#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100001
using namespace std;
bool check[MAX_SIZE];
int main(){
    FIO;
    int n;
    cin >> n;
    vector<int> v(n);
    // 해당 num에 대한 점수
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]] = 0;
    }
    int max_element = *std::max_element(v.begin(), v.end());
    for (int i = 1; i <= max_element; i++) {
        //해당 수는 알아볼 필요가 없다
        if(m.find(i) == m.end()) continue;
//        if(check[i]) continue;
//        cout << i << "\n";
        for (int j = i * 2; j <= max_element; j += i) {
            // 양 숫자가 모두 v에 존재할때
//            cout << i << " " << j << "\n";
            if (m.find(j) != m.end()) {
                m[i]++;
                m[j]--;
            }
//            check[j] = true;
        }
    }
    for (int i = 0; i < n; i++) {
        cout<<m[v[i]]<<" ";
    }
    cout << "\n";
    return 0;
}
